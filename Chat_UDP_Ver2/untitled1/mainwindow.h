#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QComboBox>

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
    QString FotoProfil(int a);
    bool IsFilePacket(const QByteArray datagram);
    void SaveFile(const QByteArray& datagram);



private slots:
    void on_SendingData_clicked();
    void on_selectFile_clicked();
    void on_selectPortButton_clicked();
    void on_pushButton_clicked();

    void on_switchPacketSize_clicked();
    void on_fileLink_clicked(const QUrl &url);
private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    int selectedPort = 9000;
    int packetsize = 32;
    int numberFile = 0;


};
#endif // MAINWINDOW_H
