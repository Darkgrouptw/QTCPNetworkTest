#include "TCPClient.h"

TCPClient::TCPClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connection = new QTcpSocket(this);
	connect(ui.ConnectButton,		SIGNAL(clicked()),		this,	SLOT(ConnectPress_Event()));
	connect(ui.SendMessageButton,	SIGNAL(clicked()),		this,	SLOT(SendPress_Event()));
	connect(connection,				SIGNAL(readyRead()),	this,	SLOT(ReadConnectionData()));
	connect(connection,				SIGNAL(disconnected()),	this,	SLOT(ConnectionDisconnected()));
}

//////////////////////////////////////////////////////////////////////////
// 按鈕事件
//////////////////////////////////////////////////////////////////////////
void TCPClient::ConnectPress_Event()
{
	if (connection->state() == QAbstractSocket::UnconnectedState)
	{
		cout << "Connect " << IP.toStdString() << " Port " << Port << endl;
		connection->connectToHost(QHostAddress(IP), Port);
		if (connection->waitForConnected(1000))
			cout << "Connection 成功" << endl;
		else
			cout << "Connection 失敗" << endl;
	}
	else
		cout << "已經有 Connection 了" << endl;

}
void TCPClient::SendPress_Event()
{
	QString Data = "TestString";
	cout << "Write Data: " << Data.toStdString() << endl;
	connection->write(Data.toStdString().c_str());
}

//////////////////////////////////////////////////////////////////////////
// Connection 事件
//////////////////////////////////////////////////////////////////////////
void TCPClient::ReadConnectionData()
{
	cout << connection->readAll().toStdString() << endl;
}
void TCPClient::ConnectionDisconnected()
{
	cout << "Disconnected" << endl;
}