#include "floor.h"
#include "ui_floor.h"
#include "room.h"

extern int g_floor_num;

Floor::Floor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Floor)
{
    ui->setupUi(this);
}

Floor::~Floor()
{
    delete ui;
    delete (Room *)next;
}
void Floor::function()
{
    if (cnt == 0)
    {
        /*没有分配，则分配地址*/
        next = new Room;
        ((Room *)next)->show();
        cnt = 1;
    }
    else
    {
        ((Room *)next)->show();
    }
}

void Floor::on_pushButton_clicked()
{
    g_floor_num = 1;
    function();
}

void Floor::on_pushButton_2_clicked()
{
    g_floor_num = 2;
    function();
}

void Floor::on_pushButton_3_clicked()
{
    g_floor_num = 3;
    function();
}

void Floor::on_pushButton_4_clicked()
{
    g_floor_num = 4;
    function();
}

void Floor::on_pushButton_5_clicked()
{
    g_floor_num = 5;
    function();
}

void Floor::on_pushButton_6_clicked()
{
    this->close();
}
