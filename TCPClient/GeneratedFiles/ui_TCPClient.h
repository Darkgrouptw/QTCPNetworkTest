/********************************************************************************
** Form generated from reading UI file 'TCPClient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *ConnectButton;
    QPushButton *SendMessageButton;

    void setupUi(QMainWindow *TCPClientClass)
    {
        if (TCPClientClass->objectName().isEmpty())
            TCPClientClass->setObjectName(QStringLiteral("TCPClientClass"));
        TCPClientClass->resize(300, 200);
        centralWidget = new QWidget(TCPClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ConnectButton = new QPushButton(centralWidget);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));
        ConnectButton->setGeometry(QRect(70, 40, 141, 51));
        SendMessageButton = new QPushButton(centralWidget);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        SendMessageButton->setGeometry(QRect(70, 120, 141, 51));
        TCPClientClass->setCentralWidget(centralWidget);

        retranslateUi(TCPClientClass);

        QMetaObject::connectSlotsByName(TCPClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClientClass)
    {
        TCPClientClass->setWindowTitle(QApplication::translate("TCPClientClass", "TCPClient", nullptr));
        ConnectButton->setText(QApplication::translate("TCPClientClass", "Connect To Server", nullptr));
        SendMessageButton->setText(QApplication::translate("TCPClientClass", "Send Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPClientClass: public Ui_TCPClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
