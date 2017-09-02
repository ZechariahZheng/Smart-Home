#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>

namespace Ui {
class Control;
}

class Control : public QMainWindow
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();

private slots:
    void on_control_Button_clicked();

    void on_add_Button_clicked();

private:
    Ui::Control *ui;
    void *next;                     //指向下一个ui界面的指针
    int cnt;
    void function();                //分配地址函数
};

#endif // CONTROL_H
