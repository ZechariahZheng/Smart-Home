#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    tcpServer = new MyTcp;                                  //tcp初始化
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password); //明文加密

    connect(tcpServer, SIGNAL(login(char *, char*)), this, SLOT(login_tcp(char *, char *)));
}

Server::~Server()
{
    delete ui;
    delete tcpServer;
    delete control;
}

void Server::login_tcp(char *user, char *pswd)
{
    ui->userLineEdit->setText(user);
    ui->passwordLineEdit->setText(pswd);

    on_logInButton_clicked();
}


void Server::on_logInButton_clicked()
{
    QString user_g,password_g;      //QLineEdit中的变量
    QString user_l,password_l;     //数据库中的变量
    QSqlQuery query;

    user_g = ui->userLineEdit->text();
    password_g = ui->passwordLineEdit->text();

    /*查找数据库中是否有该用户*/
    if(!query.exec("select name,password from sql_table"))
    {
        qDebug()<<query.lastError();
    }
    else
    {
        while(query.next())
        {
            user_l = query.value(0).toString();
            password_l =query.value(1).toString();
            if ((user_g == user_l) && (password_g == password_l))
            {
                /*存在该用户,跳到下一个界面，同时给客户端发送一个信号*/
                tcpServer->sendMsg("find");
                control = new Control;
                control->show();
                break;
            }
        }
    }
}
