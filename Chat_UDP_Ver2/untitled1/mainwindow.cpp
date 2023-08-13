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
    ui->packetLabel->setVisible(false);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadingData()//вызывается при получении данных
{
    QString dateTime = CountingDate();
    QString photo = PhotoProfile(0);
    QByteArray datagram; //объект класса
    datagram.resize(udpSocket->pendingDatagramSize());//подгон размера под дату
    udpSocket->readDatagram(datagram.data(), datagram.size());
    if (QString(datagram).startsWith("FILE"))//проверка на файл
    {
        if (QString(datagram).startsWith("FILE⋠"))
        {
            datagram.remove(0, 7);
            fileDatagram = datagram;
        }
        else
        {
            datagram.remove(0, 4);
            fileDatagram += datagram;
        }
        if (QString(datagram).endsWith("EOF", Qt::CaseInsensitive))
        {

            fileDatagram.remove(fileDatagram.length()-3, 3);
            datagram = SaveFile(fileDatagram); // сохранялка
            ui->textEdit->append(photo + "<font color=#71aaeb>Получен файл: </font>" + "'" + nameFile + "'");
            ui->textEdit->append(dateTime);
        }
    }
    else
    {
        if (!QString(datagram).isEmpty()) {
            if (QString(datagram).startsWith("SMS")) {
                receivedPacket = QString(datagram);
                receivedPacket.remove(0, 3);
            }
            else
                receivedPacket += QString(datagram);

            if (QString(datagram).endsWith("EOS", Qt::CaseInsensitive)) {
                receivedPacket.remove(receivedPacket.length() - 3, 3);
                ui->textEdit->append(photo + "<font color=#71aaeb>Собеседник: </font>" + receivedPacket);
                ui->textEdit->append(dateTime);
            }
        }
    }
}
QByteArray MainWindow::SaveFile(QByteArray& datagram)
{
    //выявление имени и удаление имени из файла

    QByteArray aboba = datagram;
    int name = aboba.indexOf("Ω");
    int len = 0;

    if (name != -1)
    {
        len = (aboba.left(name)).toInt();
        aboba.remove(0, name + 2);
    }
    nameFile = aboba.mid(0,len);
    ui->textEdit->append(QString::number(len));
    aboba.remove(0, len);
    aboba = QByteArray::fromBase64(aboba);

    QString SaveFilePath = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), nameFile);
    if (!SaveFilePath.isEmpty())
    {
        QFile file(SaveFilePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(aboba);
            file.close();
            QString packet = "SMSФайл '" +  nameFile + "' был сохранен  EOS";
            udpSocket->writeDatagram(packet.toUtf8(), QHostAddress::LocalHost, selectedPort);
        }
    }
    else
    {
         QString packet = "SMSФайл '" +  nameFile + "' не был сохранен  EOS";
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
        messageQueue.push_back(text);
        if (messageQueue.size() == 1)
        {

            sentTextPackets = 0;
            numTextPackets = qCeil(static_cast<double>(text.size()) / packetsize);
            sendingPackets(1);
            static QTimer textTimer;
            connect(&textTimer, &QTimer::timeout, this, [this]() {
                sendingPackets(1);
            });
            textTimer.start(frequency);
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
            int len = (fileName.toUtf8()).size();
            fileQueue.push_back(QString::number(len).toUtf8() + "Ω" + fileName.toUtf8() +  fileData.toBase64());
            filePackets = QString::number(len).toUtf8() + "Ω" + fileName.toUtf8() +  fileData.toBase64();
            ui->textEdit->append(QString::number(fileName.size()).toUtf8());
            if (fileQueue.size() == 1)
            {
                sentFilePackets = 0;
                numFilePackets = qCeil(static_cast<double>(filePackets.size()) / packetsize);
                sendingPackets(2);
                static QTimer fileTimer;
                connect(&fileTimer, &QTimer::timeout, this, [this]() {
                    sendingPackets(2);
                });
                fileTimer.start(frequency);
            }
            ui->textEdit->append(photo + "<font color=#71aaeb>Отправлен документ: </font>" + '"' + fileName + '"');
            ui->textEdit->append(QString(dateTime));
            file.close();//поток закрыт
        }
    }
}

void MainWindow::sendingPackets(int choice)
{
    switch (choice)
    {
    case 1://сообщения
    {
        if (!messageQueue.empty())
        {
            QString textPackets = messageQueue.front();
            if (sentTextPackets < numTextPackets)
            {
                QString packet = textPackets.mid(sentTextPackets * packetsize, packetsize);
                if (!sentTextPackets)
                    packet = "SMS" + packet;
                if (sentTextPackets == numTextPackets - 1)
                    packet += "EOS";
                udpSocket->writeDatagram(packet.toUtf8(), QHostAddress::LocalHost, selectedPort);
                ++sentTextPackets;
            }
            else
            {
                messageQueue.pop_front();
                sentTextPackets = 0;
            }
        }
        else
        {
            QTimer::singleShot(0, this, []()
            {
                static QTimer textTimer;
                textTimer.stop();
            });
        }
        break;
    }

    case (2)://файл
    {
        if (!fileQueue.empty())
        {
            QByteArray filePackets = fileQueue.front();
            if (sentFilePackets < numFilePackets)
            {
                QByteArray packet = filePackets.mid(sentFilePackets * packetsize, packetsize);
                if (!sentFilePackets)
                    packet = "FILE⋠" + packet;
                else
                    packet = "FILE" + packet;
                if (sentFilePackets == numFilePackets - 1)
                    packet += "EOF";
                udpSocket->writeDatagram(packet, QHostAddress::LocalHost, selectedPort);
                ++sentFilePackets;
               updateLabel();

            }
            else
            {
                fileQueue.pop_front();
                sentFilePackets = 0;
            }
        }
        else
        {
            QTimer::singleShot(0, this, []()
            {
                static QTimer fileTimer;
                fileTimer.stop();
            });
        }
    }
    }
}

void MainWindow::on_selectFrequency_clicked()
{
    bool ok;
    int size = QInputDialog::getInt(this,"Введите частоту отправки пакетов в ms", "Частота:", frequency, 0, 1000, 1, &ok);
    if (ok)
    {
        frequency = size;
        ui->frequencyLabel->setText("Частота отправки: " + QString::number(frequency));
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
    int size = QInputDialog::getInt(this,"Введите размер отправляемых пакетов", "Размер", packetsize, 10, 1024, 1, &ok);
    if (ok)
    {
        packetsize = size;
        ui->packetSizeLabel->setText("Рaзмер пакетов: " + QString::number(packetsize));
    }
}

void MainWindow::on_debugCheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {         
        isDebug = true;
        packetsize = 10;
        ui->textEdit->append("<font color=#71aaeb>Размер пакетов изменен на: </font>" + QString::number(packetsize));
        ui->packetSizeLabel->setText("Рaзмер пакетов: " + QString::number(packetsize));
        frequency = 1000;
        ui->textEdit->append("<font color=#71aaeb>Частота отправки изменена на: </font>" + QString::number(frequency));
        ui->textEdit->append("<font color=#71aaeb>Порт изменяется автоматически</font>");
        ui->frequencyLabel->setText("Частота отправки: " + QString::number(frequency));
        ui->packetLabel->setVisible(true);
        ui->packetLabel->setText("0 из 0");
    }

    else if (arg1 == Qt::Unchecked)
    {
        ui->packetLabel->setVisible(false);
    }

}


void MainWindow::updateLabel()
{
    ui->packetLabel->setText(QString::number(sentFilePackets) + " из " + QString::number(numFilePackets));
}

