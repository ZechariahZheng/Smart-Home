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
    void sendMsg(QString msg);

private:
    QTcpServer *server;
    QTcpSocket *clientConnection;

signals:
    void login(char *user, char *pswd);       //登入信号

public slots:
    void acceptConnection();
    void readClient();
};

#endif // MYTCP_H
