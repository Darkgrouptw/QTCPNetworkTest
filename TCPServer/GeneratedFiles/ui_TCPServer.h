/********************************************************************************
** Form generated from reading UI file 'TCPServer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServerClass
{
public:
    QWidget *centralWidget;
    QPushButton *BroadCastButton;

    void setupUi(QMainWindow *TCPServerClass)
    {
        if (TCPServerClass->objectName().isEmpty())
            TCPServerClass->setObjectName(QStringLiteral("TCPServerClass"));
        TCPServerClass->resize(300, 200);
        centralWidget = new QWidget(TCPServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BroadCastButton = new QPushButton(centralWidget);
        BroadCastButton->setObjectName(QStringLiteral("BroadCastButton"));
        BroadCastButton->setGeometry(QRect(60, 110, 181, 61));
        TCPServerClass->setCentralWidget(centralWidget);

        retranslateUi(TCPServerClass);

        QMetaObject::connectSlotsByName(TCPServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCPServerClass)
    {
        TCPServerClass->setWindowTitle(QApplication::translate("TCPServerClass", "TCPServer", nullptr));
        BroadCastButton->setText(QApplication::translate("TCPServerClass", "BroadCast To All Clients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPServerClass: public Ui_TCPServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
