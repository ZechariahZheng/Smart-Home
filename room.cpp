#include "room.h"
#include "ui_room.h"
#include "light_control.h"

enum room_type {bedroom=0, kitchen, bathroom, sitting_room};
extern room_type g_room_type;
extern bool g_light_status, g_air_status, g_TV_status, g_monitor_status, g_curtain_status;

Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
    cnt = 0;
}

Room::~Room()
{
    delete ui;
    if (1 == g_light_status)
        delete (Light_control *)next;
}

void Room::function()
{
    if (0 == cnt)
    {
       /*第一次分配地址*/
       cnt = 1;
       if (1 == g_light_status)
       {
           next = new Light_control;
           ((Light_control *)next)->show();
       }
       /*
       if (1 == g_air_status)
       {
           next = new Air_control;
           ((Air_control *)next)->show();
       }
       暂时只写两个ui界面
       if (1 == g_TV_status)
       {
           next = new TV_control;
           ((TV_control *)next)->show();
       }
       if (1 == g_monitor_status)
       {
           next = new Monitor_control;
           ((Monitor_control *)next)->show();
       }
       if (1 == g_curtain_status)
       {
           next = new Curtain_control;
           ((Curtain_control *)next)->show();
       }
       */
    }
    else
    {
        if (1 == g_light_status)
        {
            delete (Light_control *)next;
            next = new Light_control;
            ((Light_control *)next)->show();
        }
        /*
        if (1 == g_air_status)
        {
            ((Air_control *)next)->show();
        }
        if (1 == g_TV_status)
        {
            ((TV_control *)next)->show();
        }
        if (1 == g_monitor_status)
        {
            ((Monitor_control *)next)->show();
        }
        if (1 == g_curtain_status)
        {
            ((Curtain_control *)next)->show();
        }
        */
    }
}

void Room::on_bedroom_clicked()
{
    g_room_type = bedroom;
    function();
}

void Room::on_sitting_room_clicked()
{
    g_room_type = sitting_room;
    function();
}

void Room::on_kitchen_clicked()
{
    g_room_type = kitchen;
    function();
}

void Room::on_bathroom_clicked()
{
    g_room_type = bathroom;
    function();
}

void Room::on_exit_clicked()
{
    this->close();
}
