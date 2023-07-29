#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this); // создание экземпляра сокета
    qsrand(QTime::currentTime().msec());//рандомайзер
    int port = 9000 + qrand() % 1000;//пределы рандома
    ui->ourPortLabel->setText("Ваш port: " + QString::number(port));//лабель вывод порта
    udpSocket->bind(QHostAddress::LocalHost, port);//привязка к адрессу и порту
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(ReadingData()));//октрытие метода ридингдaта
    ui->textEdit->setReadOnly(true);//блокировка текствоика
    ui->portLabel->setText("Port: " + QString::number(selectedPort));//автоматический лабель
    ui->packetSizeLabel->setText("Рaзмер пакетов: " + QString::number(packetsize));//автоматический лабель
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadingData()//вызывается при получении данных
{ 
    int i = 0;//счетчик пакетов
    QString dateTime = CountingDate();
    QString photo = PhotoProfile(0);
    QByteArray fileDatagram;
    QByteArray datagram; //объект класса
    datagram.resize(udpSocket->pendingDatagramSize());//подгон размера под дату
    udpSocket->readDatagram(datagram.data(), datagram.size());

    //если есть смс остальные идут подряд

    if (IsFilePacket(datagram))//проверка на файл
    {
        i++;
        datagram.remove(0, 7);

        fileDatagram += datagram;
        while (udpSocket->hasPendingDatagrams())//выполнение до конца датаграмм
        {
            datagram.resize(udpSocket->pendingDatagramSize());//подгон размера под дату
            udpSocket->readDatagram(datagram.data(), datagram.size());
            fileDatagram += datagram;
        }

        datagram = SaveFile(fileDatagram); // сохранялка
        ui->textEdit->append(photo + "<font color=#71aaeb>Получен файл: </font>" + nameFile);


    }
    else
    {

        if (!QString(datagram).isEmpty()){


            if(QString(datagram).startsWith("SMS"))
            {
                ui->textEdit->append(photo + "<font color=#71aaeb>Собеседник: </font>" + QString(datagram));//дроп текста
                i++;
            }

            else

            {
                while (udpSocket->hasPendingDatagrams())//выполнение до конца датаграмм
                {
                    datagram.resize(udpSocket->pendingDatagramSize());//подгон размера под дату
                    udpSocket->readDatagram(datagram.data(), datagram.size());

                    if(!QString(datagram).isEmpty())
                        ui->textEdit->insertPlainText(QString(datagram));//сумма текста подряд
                }
            }
        }
        if(i)//ошибка пустоты
            ui->textEdit->append(dateTime);
    }
}
    bool MainWindow::IsFilePacket(const QByteArray datagram)//проверОчка
    {
        const QString filephoto = "FILE⋠";
        return QString(datagram).startsWith(filephoto);
    }

    QByteArray MainWindow::SaveFile(QByteArray& datagram)
    {
        //выявление имени и удаление имени из файла
        QString aboba = QString::fromUtf8(datagram);
        int Name = aboba.indexOf("Ω");
        if (Name != +1)
        {
            nameFile = aboba.left(Name);
            aboba.remove(0, Name + 1);
        }
        QString SaveFilePath = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), nameFile);
        if (!SaveFilePath.isEmpty())
        {
            QFile file(SaveFilePath);
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(aboba.toUtf8());
                file.close();
                QString packet = "Пользователь получил файл '" +  nameFile + "'";
                udpSocket->writeDatagram(packet.toUtf8(), QHostAddress::LocalHost, selectedPort);
            }
        }
        else
        {
            QString packet = "Пользователь не получил файл '" + nameFile + "'";
            udpSocket->writeDatagram(packet.toUtf8(), QHostAddress::LocalHost, selectedPort);

        }

        return datagram;
    }

    void MainWindow::on_SendingData_clicked()//отправка
    {

        QString text = ui->inputTextEdit->toPlainText();//присваение в текст - текста написанного
        QString photo = PhotoProfile(1);
        QString dateTime = CountingDate();
        if (!text.isEmpty())
        {
            int numPackets = qCeil(static_cast<double>(text.size()) / packetsize);
            for (int i = 0; i < numPackets; ++i) {
                QString packet = text.mid(i * packetsize, packetsize);
                if (i == 0)
                {
                    udpSocket->writeDatagram("SMS"+packet.toUtf8(), QHostAddress::LocalHost, selectedPort);
                }
                udpSocket->writeDatagram(packet.toUtf8(), QHostAddress::LocalHost, selectedPort);
            }
            ui->textEdit->append(photo + "<font color=#71aaeb>Вы: </font>" +  QString(text));//вывод отправленного текста в свой чат
            ui->textEdit->append(dateTime);
            ui->inputTextEdit->clear();//очистка строки ввода
        }

    }

    void MainWindow::on_selectFile_clicked()//выборка и отправка файла

    {
        QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл");//файловый путь
        QString photo = PhotoProfile(1);
        QString dateTime = CountingDate();
        if (!filePath.isEmpty()) {//проверка пустоты
            QFile file(filePath);//объект с путем
            if (file.open(QIODevice::ReadOnly)) {//открытие файла для чтения
                QByteArray fileData = file.readAll();//чтение

                QFileInfo fileInfo(file.fileName());
                QString fileName = fileInfo.fileName();
                QByteArray oldpacket = fileData;
                int numPacketsData = qCeil(static_cast<double>(oldpacket.size()) / packetsize);
                QString numData = QString::number(numPacketsData);
                QByteArray info = "FILE⋠" + fileName.toUtf8() + "Ω" + numData.toUtf8() + "Ω";
                int numPacketInfo = qCeil(static_cast<double>(info.size()) / packetsize);

                QByteArray packet = "FILE⋠" +fileName.toUtf8() + "Ω" +  fileData;

                int numPackets = numPacketInfo + numPacketsData;

                for (int i = 0; i < numPackets; ++i) {
                    QByteArray packets = packet.mid(i * packetsize, packetsize);

                    udpSocket->writeDatagram(packets, QHostAddress::LocalHost, selectedPort);
                }
                //Здесь все хорошо, работает правильно!!!
                file.close();//поток закрыт

                ui->textEdit->append(photo + "<font color=#71aaeb>Отправлен документ: </font>" + '"' + fileName + '"');
                ui->textEdit->append(QString(dateTime));
            }
        }

    }

    QString MainWindow::CountingDate()//добавление доп информации по сообщениям
    {
        QString dateTime;
        dateTime += QDateTime::currentDateTime().toString();
        return dateTime;

    }

    QString MainWindow::PhotoProfile(int a)//фотографии
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
