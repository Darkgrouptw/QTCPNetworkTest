#include "TCPClient.h"

TCPClient::TCPClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connection = new QTcpSocket(this);
	connect(ui.ConnectButton,		SIGNAL(clicked()),		this,	SLOT(ConnectPress_Event()));
	connect(ui.SendMessageButton,	SIGNAL(clicked()),		this,	SLOT(SendPress_Event()));
}

void TCPClient::ConnectPress_Event()
{
	cout << "Connect " << IP.toStdString() << " Port " << Port << endl;
	connection->connectToHost(QHostAddress(IP), Port);
	if (connection->waitForConnected(1000))
	{
		cout << "Connection 成功" << endl;
		connect(connection, SIGNAL(readyRead()), this, SLOT(ReadConnectionData()));
	}
	else
		cout << "Connection 失敗" << endl;

}
void TCPClient::SendPress_Event()
{
	QString Data = "TestString";
	cout << "Write Data: " << Data.toStdString() << endl;
	connection->write(Data.toStdString().c_str());
}

void TCPClient::ReadConnectionData()
{
	cout << connection->readAll().toStdString() << endl;
}
