#ifndef LIGHT_CONTROL_H
#define LIGHT_CONTROL_H

#include <QWidget>

namespace Ui {
class Light_control;
}

class Light_control : public QWidget
{
    Q_OBJECT

public:
    explicit Light_control(QWidget *parent = 0);
    ~Light_control();

private slots:
    void on_turn_on_clicked();

    void on_turn_off_clicked();

private:
    Ui::Light_control *ui;
};

#endif // LIGHT_CONTROL_H
