#pragma once

#include <QtWidgets/QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>

#include <iostream>

#include "ui_TCPClient.h"

using namespace std;

class TCPClient : public QMainWindow
{
	Q_OBJECT

public:
	TCPClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::TCPClientClass ui;

	QTcpSocket *connection;
	QString		IP = "127.0.0.1";
	int			Port = 10018;


private slots:
	void		ConnectPress_Event();
	void		SendPress_Event();

	void		ReadConnectionData();
};
