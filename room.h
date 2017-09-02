#ifndef ROOM_H
#define ROOM_H

#include <QWidget>

namespace Ui {
class Room;
}

class Room : public QWidget
{
    Q_OBJECT

public:
    explicit Room(QWidget *parent = 0);
    ~Room();

private slots:


    void on_bedroom_clicked();

    void on_sitting_room_clicked();

    void on_kitchen_clicked();

    void on_bathroom_clicked();

    void on_exit_clicked();

private:
    Ui::Room *ui;
    void *next;             //指向下一个界面的指针
    int cnt;
    void function();        //分配地址
};

#endif // ROOM_H
