#include "mytcp.h"

MyTcp::MyTcp(QObject *parent) : QObject(parent)
{
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6665);

    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

MyTcp::~MyTcp()
{
    delete server;
}

void MyTcp::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    QObject::connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void MyTcp::readClient()
{
    QString str = clientConnection->readAll();
    if (str == "kongtiao")
        emit kongtiao();
}
