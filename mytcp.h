#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcp : public QObject
{
    Q_OBJECT
public:
    explicit MyTcp(QObject *parent = 0);
    ~MyTcp();

private:
    QTcpServer *server;
    QTcpSocket *clientConnection;

signals:
    void kongtiao();

public slots:
    void acceptConnection();
    void readClient();
};

#endif // MYTCP_H
