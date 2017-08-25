#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    tcpServer = new MyTcp;

    connect(tcpServer, SIGNAL(kongtiao()), this, SLOT(action()));
}

Server::~Server()
{
    delete ui;
    delete tcpServer;
}

void Server::action()
{
    ui->label->setText("hello ZZX");
}

