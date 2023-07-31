#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDateTime>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QtMath>
#include <QThread>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void ReadingData();
    QString CountingDate();
    QString PhotoProfile(int a);
    QByteArray SaveFile(QByteArray& datagram);
    void sendingPackets(int choise);



private slots:
    void on_SendingData_clicked();
    void on_selectFile_clicked();
    void on_selectPortButton_clicked();
    void on_pushButton_clicked();
    void on_switchPacketSize_clicked();
    void on_selectFrequency_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    int selectedPort = 9000;
    int packetsize = 32;
    int numberFile = 0;
    QString nameFile;
    QByteArray fileDatagram;
    int frequency = 100;
    QString textPackets;
    QByteArray filePackets;
    int sentTextPackets;
    int sentFilePackets;
    int numTextPackets = 0;
    int numFilePackets = 0;
    QString receivedPacket;



};
#endif // MAINWINDOW_H
