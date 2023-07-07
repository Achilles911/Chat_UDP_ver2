#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QFileDialog>
#include <QInputDialog>

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
        if (i == 0)//условие 1 пакета
        {
            if(!QString(datagram).isEmpty())
                ui->textEdit->append(prefix + "<font color=#71aaeb>Собеседник: </font>" + QString(datagram));//дроп текста
        }

        else
            ui->textEdit->insertPlainText(QString(datagram));//сумма текста подряд
        if(!QString(datagram).isEmpty())//проверка наличия сообщений
        i++;
    }
    if(i)//ошибка пустоты
     ui->textEdit->append(information);
}



void MainWindow::on_SendingData_clicked()//отправка
{

    QString text = ui->inputTextEdit->toPlainText();//присваение в текст - текста написанного
    QString prefix = FotoProfil(1);

    if(!text.isEmpty())
    {

        QByteArray data = text.toUtf8(); // переделка в другой формат

        const int packetSize = 32;  // Размер пакета в байтах

        int numPackets = (data.size() + packetSize - 1) / packetSize;  // Вычисляем общее количество пакетов

        for (int i = 0; i < numPackets; ++i) {
            QByteArray packet = data.mid(i * packetSize, packetSize);  // Получаем фрагмент данных
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

        if (!filePath.isEmpty()) {//проверка пустоты
            QFile file(filePath);//объект с путем

            if (file.open(QIODevice::ReadOnly)) {//открытие файла для чтения
                QByteArray fileData = file.readAll();//чтение

                udpSocket->writeDatagram(fileData, QHostAddress::LocalHost, selectedPort);//отправка

                file.close();//поток закрыт
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
        imagePath = ":/resource/images/Renat.jpg";

    else

        imagePath = ":/resource/images/Dmitriy.jpg";

    imageHtml = "<img src='" + imagePath + "'width='20' height='20'>";

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





