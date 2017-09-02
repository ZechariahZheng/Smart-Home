#include "light_control.h"
#include "ui_light_control.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

enum room_type {bedroom=0, kitchen, bathroom, sitting_room};

extern int g_floor_num;                            //楼层数
extern room_type g_room_type;                      //房间类型

extern QSqlDatabase sql_control;                   //控制界面数据库

QString light_Init()
{
    QSqlQuery query;
    QString msg;
    QString floor_num, room_type;
    QString jiandian_type_l, room_type_l, floor_l;


    switch (g_floor_num)
    {
        case 1: floor_num = "1";
                break;
        case 2: floor_num = "2";
                break;
        case 3: floor_num = "3";
                break;
        case 4: floor_num = "4";
                break;
        case 5: floor_num = "5";
    }
    switch (g_room_type)
    {
        case bedroom: room_type = "bedroom";
                      break;
        case kitchen: room_type = "kitchen";
                      break;
        case bathroom: room_type = "bathroom";
                       break;
        case sitting_room: room_type = "sitting_room";
    }

    /*判断家电是否存在*/
    if(!query.exec("select jiadian_type,room_type,floor from control_table"))
    {
        qDebug()<<query.lastError();
    }
    else
    {
        while(query.next())
        {
            jiandian_type_l = query.value(0).toString();
            room_type_l =query.value(1).toString();
            floor_l =query.value(2).toString();

            if ((floor_num == floor_l) && (room_type == room_type_l) && ("light" == jiandian_type_l))
            {
                /*显示信息*/
                msg = "家电类型: 电灯; 楼层数: ";
                msg += floor_num;
                msg += "; 房间类型: ";
                msg += room_type;

                return msg;
            }
        }
    }

    /*没有查找到*/
    msg = "Not exist the light!";
    return msg;
}

Light_control::Light_control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Light_control)
{
    QString msg;

    ui->setupUi(this);
    msg = light_Init();
    ui->showMsg->setText(msg);
}

Light_control::~Light_control()
{
    delete ui;
}

void Light_control::on_turn_on_clicked()
{
    /*发送打开信息*/
}

void Light_control::on_turn_off_clicked()
{
    /*发送关闭信息*/
}
