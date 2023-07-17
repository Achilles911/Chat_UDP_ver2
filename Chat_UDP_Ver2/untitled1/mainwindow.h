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
    bool IsFilePacket(const QByteArray datagram);
    QByteArray SaveFile(QByteArray& datagram);



private slots:
    void on_SendingData_clicked();
    void on_selectFile_clicked();
    void on_selectPortButton_clicked();
    void on_pushButton_clicked();
    void on_switchPacketSize_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    int selectedPort = 9000;
    int packetsize = 32;
    int numberFile = 0;
    QString nameFile;



};
#endif // MAINWINDOW_H
