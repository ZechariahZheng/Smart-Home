#include "control.h"
#include "ui_control.h"
#include "type.h"

extern bool g_control_status, g_add_status;

Control::Control(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
    cnt = 0;        //初始化为0
}

Control::~Control()
{
    delete ui;
    delete (Type *)next;
}

void Control::function()
{
    if (cnt == 0)
    {
        /*没有分配，则分配地址*/
        next = new Type;
        ((Type *)next)->show();
        cnt = 1;
    }
    else
    {
        ((Type *)next)->show();
    }
}

void Control::on_control_Button_clicked()
{
    g_control_status = 1;
    g_add_status = 0;
    function();
}

void Control::on_add_Button_clicked()
{
    g_control_status = 0;
    g_add_status = 1;
    function();
}
