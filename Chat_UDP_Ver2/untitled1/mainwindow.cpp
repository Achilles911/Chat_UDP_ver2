#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QFileDialog>
#include <QInputDialog>
#include <QToolBar>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this); // создание экземпляра сокета
    qsrand(QTime::currentTime().msec());//рандомайзер
    int port = 9000 + qrand() % 1000;
    ui->ourPortLabel->setText("Ваш port: " + QString::number(port));//лабель вывод порта
    udpSocket->bind(QHostAddress::LocalHost, port);//привязка к адрессу и порту
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(ReadingData()));//октрытие метода ридингдaта
    ui->textEdit->setReadOnly(true);//блокировка текствоика
    ui->portLabel->setText("Port: " + QString::number(selectedPort));//автоматический лабель
    ui->packetSizeLabel->setText("Рaзмер пакетов: " + QString::number(packetsize));//автоматический лабель
    // Добавление действий в тулбар
    QAction *changePortAction = new QAction("Изменить порт собеседника", this);
    QAction *clearTextAction = new QAction("Очистить текстовое поле", this);
    QAction *selectFileAction = new QAction("Выбрать файл", this);
    QAction *switchPacketSizeAction = new QAction("Изменить размер пакетов", this);
    QToolBar *toolBar = new QToolBar(this);
    toolBar->addAction(changePortAction);
    toolBar->addAction(clearTextAction);
    toolBar->addAction(selectFileAction);
    toolBar->addAction(switchPacketSizeAction);
    addToolBar(toolBar);
    connect(changePortAction, &QAction::triggered, this, &MainWindow::on_selectPortButton_clicked);
    connect(clearTextAction, &QAction::triggered, this, &MainWindow::on_pushButton_clicked);
    connect(selectFileAction, &QAction::triggered, this, &MainWindow::on_selectFile_clicked);
    connect(switchPacketSizeAction, &QAction::triggered, this, &MainWindow::on_switchPacketSize_clicked);
    //  Конец ToolBar

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadingData()//вызывается при получении данных
{ 
    int i = 0;//счетчик пакетов
    QString information = CountingDate();
    QString prefix = FotoProfil(0);

    while (udpSocket->hasPendingDatagrams())//выполнение до конца датаграмм
    {
        QByteArray datagram; //объект класса
        datagram.resize(udpSocket->pendingDatagramSize());//подгон размера под дату
        udpSocket->readDatagram(datagram.data(), datagram.size());//считывание в массив


        if(IsFilePacket(datagram))//проверка на файл
        {
            datagram.remove(0, 5);
            //ui->textEdit->append("хуйня работает");
            SaveFile(datagram); // сохранялка
            ui->textEdit->append(prefix + "<font color=#71aaeb>Получен файл: </font>" + "Документ " + QString::number(numberFile - 1));
        }
        else
        {
            if (i == 0)//условие 1 пакета
            {

                if(!QString(datagram).isEmpty())
                    ui->textEdit->append(prefix + "<font color=#71aaeb>Собеседник: </font>" + QString(datagram));//дроп текста
            }

            else
                ui->textEdit->insertPlainText(QString(datagram));//сумма текста подряд
        }


        if(!QString(datagram).isEmpty())//проверка наличия сообщений
            i++;
    }
    if(i)//ошибка пустоты
        ui->textEdit->append(information);
}

bool MainWindow::IsFilePacket(const QByteArray datagram)//проверОчка
{
    const QString filePrefix = "FILE⋠";
    return QString(datagram).startsWith(filePrefix);

}

void MainWindow::SaveFile(const QByteArray& datagram)
{
    QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "Документ " + QString::number(numberFile));
    if (!saveFilePath.isEmpty())
    {
        QFile file(saveFilePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(datagram);
            file.close();
        }
    }
    numberFile += 1;}

void MainWindow::on_SendingData_clicked()//отправка
{

    QString text = ui->inputTextEdit->toPlainText();//присваение в текст - текста написанного
    QString prefix = FotoProfil(1);

    if(!text.isEmpty())
    {

        QByteArray data = text.toUtf8(); // переделка в другой формат


        int numPackets = (data.size() + packetsize - 1) / packetsize;
        for (int i = 0; i < numPackets; ++i) {
            QByteArray packet = data.mid(i * packetsize, packetsize);
            udpSocket->writeDatagram(packet, QHostAddress::LocalHost, selectedPort);//отправка даты
        }
        QString information = CountingDate();

        ui->textEdit->append(prefix + "<font color=#71aaeb>Вы: </font>" +  QString(text));//вывод отправленного текста в свой чат
        ui->textEdit->append(QString(information));

        ui->inputTextEdit->clear();//очистка строки ввода
    }
}

void MainWindow::on_selectFile_clicked()//выборка и отправка файла
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл");//файловый путь

    QString prefix = FotoProfil(1);
    QString information = CountingDate();

    if (!filePath.isEmpty()) {//проверка пустоты

        QFile file(filePath);//объект с путем

        if (file.open(QIODevice::ReadOnly)) {//открытие файла для чтения

            QByteArray fileData = file.readAll();//чтение
            QByteArray packet = "FILE⋠" + fileData;
            QFileInfo fileInfo(file.fileName());
            QString fileName = fileInfo.fileName();
            udpSocket->writeDatagram(packet, QHostAddress::LocalHost, selectedPort);
            file.close();//поток закрыт
            ui->textEdit->append(prefix + "<font color=#71aaeb>Отправлен документ: </font>" + '"' + fileName + '"');
            ui->textEdit->append(QString(information));
        }
    }

}

QString MainWindow::CountingDate()//добавление доп информации по сообщениям
{
    QString information;
    information += QDateTime::currentDateTime().toString();
    return information;

}

QString MainWindow::FotoProfil(int a)//фотографии
{

    QString imageHtml;
    QString imagePath;
    if(a)
        imagePath = ":/resource/images/Renat.jpg";//основная

    else

        imagePath = ":/resource/images/Dmitriy.jpg";//собеседника

    imageHtml = "<img src='" + imagePath + "'width='20' height='20'>";//подгон ссылки и размера

    return imageHtml;
}

void MainWindow::on_selectPortButton_clicked()//кнопка подключения к порту
{
    bool ok;
    int port = QInputDialog::getInt(this, "Введите номер порта", "Порт:", selectedPort, 9000, 9999, 1, &ok);//вызов меню
    if (port != selectedPort)//очистить поле если меняется порт
        ui->textEdit->clear();
    if(ok)
    {
        selectedPort = port;//передача
        ui->portLabel->setText("Port: " + QString::number(selectedPort));//лабель вывод порта
    }
}

void MainWindow::on_pushButton_clicked()//очситка
{
    ui->textEdit->clear();
}

void MainWindow::on_switchPacketSize_clicked()//изменение размера отправляемых пакетов
{

    bool ok;
    int size = QInputDialog::getInt(this,"Введите размер отправляемых пакетов", "Размер", packetsize, 2, 1024, 1, &ok);
    if (ok)
    {
        packetsize = size;
        ui->packetSizeLabel->setText("Рaзмер пакетов: " + QString::number(packetsize));
    }
}

void MainWindow::on_fileLink_clicked(const QUrl &url)//открытие и сохранение файла по ссылке
{
    QString filePath = url.toString();


    QString savePath = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "All Files (*)");//окно сохранения

    if (!savePath.isEmpty()) {

        if (QFile::copy(filePath, savePath)) {// копирование файла в выбранное место и окна ответа

            QMessageBox::information(this, "Все хорошо.", "Файл сохранен.");
        } else {

            QMessageBox::warning(this, "Есть проблемка с сохранением.", "Не получилось, не фортануло.");
        }
    }
}
