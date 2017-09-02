#ifndef TYPE_H
#define TYPE_H

#include <QMainWindow>

namespace Ui {
class Type;
}

class Type : public QMainWindow
{
    Q_OBJECT

public:
    explicit Type(QWidget *parent = 0);
    ~Type();

private slots:
    void on_light_clicked();

    void on_kongtiao_clicked();

    void on_TV_clicked();

    void on_monitor_clicked();

    void on_curtain_clicked();

    void on_exit_clicked();

private:
    Ui::Type *ui;
    void *next;                     //指向下一个ui界面的指针
    int cnt;
    void function();                //分配地址函数
};

#endif // TYPE_H
