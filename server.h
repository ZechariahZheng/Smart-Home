#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "mytcp.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "control.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private:
    Ui::Server *ui;
    MyTcp *tcpServer;           //tcp变量
    Control *control;           //控制界面

public slots:
    void login_tcp(char *user, char *pswd);
private slots:
    void on_logInButton_clicked();
};

#endif // SERVER_H
