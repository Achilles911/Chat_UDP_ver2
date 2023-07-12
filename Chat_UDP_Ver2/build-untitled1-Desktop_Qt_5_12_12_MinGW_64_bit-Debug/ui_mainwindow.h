/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QWidget *centralwidget;
    QPushButton *SendingData;
    QTextEdit *textEdit;
    QTextEdit *inputTextEdit;
    QPushButton *selectFile;
    QPushButton *pushButton;
    QPushButton *selectPortButton;
    QLabel *portLabel;
    QLabel *ourPortLabel;
    QPushButton *switchPacketSize;
    QLabel *packetSizeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(499, 420);
        MainWindow->setMinimumSize(QSize(499, 420));
        MainWindow->setMaximumSize(QSize(499, 420));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SendingData = new QPushButton(centralwidget);
        SendingData->setObjectName(QString::fromUtf8("SendingData"));
        SendingData->setGeometry(QRect(431, 370, 69, 31));
        SendingData->setMinimumSize(QSize(69, 31));
        SendingData->setMaximumSize(QSize(100, 31));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 501, 371));
        textEdit->setMinimumSize(QSize(400, 201));
        textEdit->setMaximumSize(QSize(501, 371));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);\n"
"color: rgb(255, 255, 255);"));
        inputTextEdit = new QTextEdit(centralwidget);
        inputTextEdit->setObjectName(QString::fromUtf8("inputTextEdit"));
        inputTextEdit->setGeometry(QRect(0, 370, 431, 31));
        inputTextEdit->setMinimumSize(QSize(311, 31));
        inputTextEdit->setMaximumSize(QSize(16777215, 31));
        selectFile = new QPushButton(centralwidget);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        selectFile->setGeometry(QRect(0, 370, 31, 31));
        selectFile->setMinimumSize(QSize(31, 31));
        selectFile->setMaximumSize(QSize(31, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 370, 31, 31));
        pushButton->setMinimumSize(QSize(31, 31));
        pushButton->setMaximumSize(QSize(31, 31));
        selectPortButton = new QPushButton(centralwidget);
        selectPortButton->setObjectName(QString::fromUtf8("selectPortButton"));
        selectPortButton->setGeometry(QRect(60, 370, 31, 31));
        selectPortButton->setMinimumSize(QSize(31, 31));
        selectPortButton->setMaximumSize(QSize(31, 31));
        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setGeometry(QRect(410, 0, 81, 20));
        portLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ourPortLabel = new QLabel(centralwidget);
        ourPortLabel->setObjectName(QString::fromUtf8("ourPortLabel"));
        ourPortLabel->setGeometry(QRect(390, 350, 91, 16));
        ourPortLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        switchPacketSize = new QPushButton(centralwidget);
        switchPacketSize->setObjectName(QString::fromUtf8("switchPacketSize"));
        switchPacketSize->setGeometry(QRect(90, 380, 16, 16));
        packetSizeLabel = new QLabel(centralwidget);
        packetSizeLabel->setObjectName(QString::fromUtf8("packetSizeLabel"));
        packetSizeLabel->setGeometry(QRect(10, 350, 131, 16));
        packetSizeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        switchPacketSize->raise();
        selectPortButton->raise();
        pushButton->raise();
        selectFile->raise();
        SendingData->raise();
        textEdit->raise();
        inputTextEdit->raise();
        portLabel->raise();
        ourPortLabel->raise();
        packetSizeLabel->raise();

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), textEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200 2", nullptr));
        SendingData->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        selectFile->setText(QApplication::translate("MainWindow", "\360\237\223\216", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\360\237\227\221", nullptr));
        selectPortButton->setText(QApplication::translate("MainWindow", "Port", nullptr));
        portLabel->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 \321\201\320\276\320\261\320\265\321\201\320\265\320\264\320\275\320\270\320\272\320\260", nullptr));
        ourPortLabel->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        switchPacketSize->setText(QApplication::translate("MainWindow", "Packet", nullptr));
        packetSizeLabel->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\272\320\265\321\202\321\213 \321\201 \320\274\321\203\321\201\320\276\321\200\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
