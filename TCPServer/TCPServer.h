#pragma once
#include <QtWidgets/QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QVector>

#include <iostream>

#include "ui_TCPServer.h"

using namespace std;

class TCPServer : public QMainWindow
{
	Q_OBJECT

public:
	TCPServer(QWidget *parent = Q_NULLPTR);

private:
	Ui::TCPServerClass ui;
	QTcpServer				*server;
	QVector<QTcpSocket*>	connectionList;
	int						Port = 10018;

private slots:
	void					AcceptConnection();
	void					ReadConnection();
	void					ConnectionDisconnected();

	void					BroadCastPress_Event();
};
