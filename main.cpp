#include "server.h"
#include <QApplication>

enum room_type {bedroom=0, kitchen, bathroom, sitting_room};

int g_fd0;                                  //nrf905的文件描述符
bool g_light_status, g_air_status, g_TV_status, g_monitor_status, g_curtain_status;       //各个电器状态变量
bool g_control_status, g_add_status;        //控制类型
int g_floor_num;                            //楼层数
room_type g_room_type;                      //房间类型

QSqlDatabase g_sql_control;                 //全局变量数据库

void Init()
{
    /*打开905设备*/
    /*g_fd0 = open("/dev/nrf905", O_RDWR);
    if (g_fd0 < 0)
    {
        qDebug()<<"can't open /dev/nrf905!\n";
    }*/

    /*创建家电数据库*/
    g_sql_control = QSqlDatabase::addDatabase("QSQLITE");
    g_sql_control.setDatabaseName("control.db");
    g_sql_control.setUserName("root");
    g_sql_control.setPassword("123456");

    /*打开数据库*/
    if(g_sql_control.open())
    {
       qDebug() << "database succeeded to open";
    }
    else
    {
        qDebug() << "database failed to open";
    }

    /*数据库操作
    创建一个5列的表：id、家电名、所属房间类型、所属楼层*/
    QSqlQuery query;
    QString create_sql="create table control_table (id integer primary key autoincrement not null, jiadian_type text,room_type text,floor text)";
    QString insert_sql="insert into control_table(jiadian_type, room_type, floor) values ('light', 'bedroom', 1)";
    query.prepare(create_sql);
    if(!query.exec())                   //创建表control_table,如果该表没有创建的话
    {
        qDebug()<<"control_table can't created!";
        qDebug() << query.lastError();
    }
    else                               //创建的话，插入数据
    {
        qDebug()<<"control_table created!";
        query.prepare(insert_sql);
        if(!query.exec())
        {
           qDebug() << query.lastError();
        }
        else
        {
            qDebug()<<"inserted!";
        }

    }

    /*创建用户表*/
    create_sql="create table sql_table (id integer primary key autoincrement not null, name text,password text)";
    insert_sql="insert into sql_table(name,password) values ('liwei',406130814123)";;
    query.prepare(create_sql);
    if(!query.exec())                   //创建表sql_table,如果该表没有创建的话
    {
         qDebug()<<"sql_table can't created!";
         qDebug() << query.lastError();
    }
    else                               //创建的话，插入数据
    {
         qDebug()<<"sql_table created!";
         query.prepare(insert_sql);
         if(!query.exec())
         {
            qDebug() << query.lastError();
         }
         else
         {
             qDebug()<<"inserted!";
         }

    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Init();
    Server w;
    w.show();

    return a.exec();
}
