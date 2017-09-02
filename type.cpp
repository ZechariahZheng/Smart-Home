#include "type.h"
#include "ui_type.h"
#include "floor.h"

extern bool g_light_status, g_air_status, g_TV_status, g_monitor_status, g_curtain_status;

Type::Type(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Type)
{
    ui->setupUi(this);
    cnt = 0;
}

Type::~Type()
{
    delete ui;
    delete (Floor *)next;
}

void Type::function()
{
    if (cnt == 0)
    {
        /*没有分配，则分配地址*/
        next = new Floor;
        ((Floor *)next)->show();
        cnt = 1;
    }
    else
    {
        ((Floor *)next)->show();
    }
}

void Type::on_light_clicked()
{
    g_light_status = 1;
    function();
}

void Type::on_kongtiao_clicked()
{
    g_air_status = 1;
    function();
}

void Type::on_TV_clicked()
{
    g_TV_status = 1;
    function();
}

void Type::on_monitor_clicked()
{
    g_monitor_status = 1;
    function();
}

void Type::on_curtain_clicked()
{
    g_curtain_status = 1;
    function();
}

void Type::on_exit_clicked()
{
    this->close();
}
