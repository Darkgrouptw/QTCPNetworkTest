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
	connect(connection,				SIGNAL(disconnected()),		this,	SLOT(ConnectionDisconnected()));
}
void TCPServer::ReadConnection()
{
	for (int i = 0; i < connectionList.size(); i++)
		// 確認有東西，這邊可以再改得更好的一點
		if (connectionList[i]->bytesAvailable() > 0)
			cout << i << " " << connectionList[i]->readAll().toStdString() << endl;
}
void TCPServer::ConnectionDisconnected()
{
	// 先抓出哪些要刪掉
	QVector<int> DisconnectIDList;
	for (int i = 0; i < connectionList.size(); i++)
		if (connectionList[i]->state() == QAbstractSocket::UnconnectedState)
		{
			cout << "Disconnect: " << i << endl;
			DisconnectIDList.push_back(i);
		}

	// 刪除 Connection
	for (int i = DisconnectIDList.size() - 1; i >= 0; i--)
	{
		int ID = DisconnectIDList[i];
		connectionList[i]->close();
		connectionList.removeAt(ID);
	}
}

void TCPServer::BroadCastPress_Event()
{
	QString Data = "BroadCast_From_Server";
	cout << "Start BroadCast: " << Data.toStdString() << endl;
	for (int i = 0; i < connectionList.size(); i++)
		connectionList[i]->write(Data.toStdString().c_str());
}
