#ifndef FLOOR_H
#define FLOOR_H

#include <QMainWindow>

namespace Ui {
class Floor;
}

class Floor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Floor(QWidget *parent = 0);
    ~Floor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Floor *ui;
    void *next;
    int cnt;
    void function();
};

#endif // FLOOR_H
