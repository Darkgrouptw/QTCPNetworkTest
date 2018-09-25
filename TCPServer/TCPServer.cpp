#include "TCPServer.h"

TCPServer::TCPServer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.BroadCastButton,		SIGNAL(clicked()),			this,	SLOT(BroadCastPress_Event()));

	// Server 建立
	server = new QTcpServer();
	server->listen(QHostAddress::Any, Port);
	connect(server,					SIGNAL(newConnection()),	this,	SLOT(AcceptConnection()));
}

void TCPServer::AcceptConnection()
{
	QTcpSocket* connection = server->nextPendingConnection();
	connectionList.push_back(connection);
	cout << "Connect Number: " << connectionList.size() << endl;
	connect(connection,				SIGNAL(readyRead()),		this,	SLOT(ReadConnection()));
}
void TCPServer::ReadConnection()
{
	for (int i = 0; i < connectionList.size(); i++)
	{
		cout << i << " " << connectionList[i]->readAll().toStdString() << endl;
	}
}

void TCPServer::BroadCastPress_Event()
{
	QString Data = "BroadCast_From_Server";
	cout << "Start BroadCast: " << Data.toStdString() << endl;
	for (int i = 0; i < connectionList.size(); i++)
		connectionList[i]->write(Data.toStdString().c_str());
}
