#include "mytcp.h"
int findByte(const char *string, const char target);
int rfindByte(const char *string, const char target);
char *cutString(const int n, const int m, char *string);

/*接收、处理数据*/
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
    char *rec;
    QByteArray ba = str.toLatin1();
    int pos_h;      //头部
    int pos_t;      //尾部
    char *user;
    char *pswd;

    /*将QString类型转换为char *类型*/
    rec = ba.data();
    pos_h = findByte(rec, ';');
    pos_t = rfindByte(rec, ';');

    /*指令判断*/
    if (pos_h != -1 && pos_t != -1)
    {
        /*login*/
        if (!strncmp("login", rec, pos_h))
        {
            user = cutString(pos_h, pos_t, rec);
            pswd = cutString(pos_t, strlen(rec), rec);
            emit login(user, pswd);         //发送信号，并传递信息
        }
    }

    /*释放分配的内存*/
    delete [] user;
    delete [] pswd;
}

void MyTcp::sendMsg(QString msg)
{
    clientConnection->write(msg.toStdString().c_str(), strlen(msg.toStdString().c_str()));  //发送信息
}

/*从头寻找某个字符*/
int findByte(const char *string, const char target)
{
    int i = 0;

    while (string[i] != '\0')
    {
        if (string[i] == target)
            return i;
        i++;
    }
    return -1;
}

/*从尾寻找某个字符*/
int rfindByte(const char *string, const char target)
{
    int i = strlen(string) - 1;

    while (i >= 0)
    {
        if (string[i] == target)
            return i;
        i--;
    }
    return -1;
}

/*从字符串中截取某段字符串,n为起点，m为终点，截取n与m之间的字符串*/
char *cutString(const int n, const int m, char *string)
{
    char *subString;
    int i = n+1;

    if (n >= m)
        return NULL;
    subString = new char [m-n];
    while(i < m)
    {
        subString[i-n-1] = string[i];
        i++;
    }
    subString[m-n-1] = '\0';
    return subString;
}
