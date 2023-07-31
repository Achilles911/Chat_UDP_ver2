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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *toolsPanel;
    QPushButton *selectPortButton;
    QPushButton *switchPacketSize;
    QPushButton *selectFile;
    QPushButton *selectFrequency;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *inputPanel;
    QTextEdit *inputTextEdit;
    QPushButton *SendingData;
    QWidget *layoutWidget2;
    QHBoxLayout *infoPanel;
    QLabel *portLabel;
    QLabel *ourPortLabel;
    QLabel *packetSizeLabel;
    QLabel *frequencyLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(493, 480);
        MainWindow->setMinimumSize(QSize(493, 480));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 50, 491, 381));
        textEdit->setMinimumSize(QSize(441, 381));
        textEdit->setMaximumSize(QSize(550, 420));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);\n"
"color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, -10, 511, 48));
        groupBox->setMinimumSize(QSize(441, 41));
        groupBox->setFlat(true);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 15, 481, 23));
        toolsPanel = new QHBoxLayout(layoutWidget);
        toolsPanel->setObjectName(QString::fromUtf8("toolsPanel"));
        toolsPanel->setContentsMargins(0, 0, 0, 0);
        selectPortButton = new QPushButton(layoutWidget);
        selectPortButton->setObjectName(QString::fromUtf8("selectPortButton"));
        selectPortButton->setMinimumSize(QSize(91, 21));

        toolsPanel->addWidget(selectPortButton);

        switchPacketSize = new QPushButton(layoutWidget);
        switchPacketSize->setObjectName(QString::fromUtf8("switchPacketSize"));
        switchPacketSize->setMinimumSize(QSize(101, 21));

        toolsPanel->addWidget(switchPacketSize);

        selectFile = new QPushButton(layoutWidget);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        selectFile->setMinimumSize(QSize(101, 21));

        toolsPanel->addWidget(selectFile);

        selectFrequency = new QPushButton(layoutWidget);
        selectFrequency->setObjectName(QString::fromUtf8("selectFrequency"));
        selectFrequency->setMinimumSize(QSize(61, 21));

        toolsPanel->addWidget(selectFrequency);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(61, 21));

        toolsPanel->addWidget(pushButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 430, 491, 43));
        inputPanel = new QHBoxLayout(layoutWidget1);
        inputPanel->setObjectName(QString::fromUtf8("inputPanel"));
        inputPanel->setContentsMargins(0, 0, 0, 0);
        inputTextEdit = new QTextEdit(layoutWidget1);
        inputTextEdit->setObjectName(QString::fromUtf8("inputTextEdit"));
        inputTextEdit->setMinimumSize(QSize(330, 31));
        inputTextEdit->setMaximumSize(QSize(16777215, 41));

        inputPanel->addWidget(inputTextEdit);

        SendingData = new QPushButton(layoutWidget1);
        SendingData->setObjectName(QString::fromUtf8("SendingData"));
        SendingData->setMinimumSize(QSize(101, 41));

        inputPanel->addWidget(SendingData);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 30, 491, 20));
        infoPanel = new QHBoxLayout(layoutWidget2);
        infoPanel->setObjectName(QString::fromUtf8("infoPanel"));
        infoPanel->setContentsMargins(0, 0, 0, 0);
        portLabel = new QLabel(layoutWidget2);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        infoPanel->addWidget(portLabel);

        ourPortLabel = new QLabel(layoutWidget2);
        ourPortLabel->setObjectName(QString::fromUtf8("ourPortLabel"));
        ourPortLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        infoPanel->addWidget(ourPortLabel);

        packetSizeLabel = new QLabel(layoutWidget2);
        packetSizeLabel->setObjectName(QString::fromUtf8("packetSizeLabel"));
        packetSizeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        infoPanel->addWidget(packetSizeLabel);

        frequencyLabel = new QLabel(layoutWidget2);
        frequencyLabel->setObjectName(QString::fromUtf8("frequencyLabel"));

        infoPanel->addWidget(frequencyLabel);

        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        textEdit->raise();
        groupBox->raise();
        layoutWidget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200 2", nullptr));
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        selectPortButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\276\321\200\321\202", nullptr));
        switchPacketSize->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", nullptr));
        selectFile->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        selectFrequency->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        SendingData->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        portLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\270\321\200\320\260\320\265\321\202\321\201\321\217 \320\277\320\276\321\200\321\202", nullptr));
        ourPortLabel->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        packetSizeLabel->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\272\320\265\321\202\321\213 \321\201 \320\274\321\203\321\201\320\276\321\200\320\276\320\274", nullptr));
        frequencyLabel->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
