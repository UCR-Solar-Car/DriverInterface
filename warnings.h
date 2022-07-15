#ifndef WARNINGS_H
#define WARNINGS_H

#include "ui_mainwindow.h"
#include "states.h"

class Warnings
{
public:
    Warnings();
    void setup(Ui::MainWindow*);
    void battery_on();
    void battery_off();
    void motor_on();
    void motor_off();
    ~Warnings() {};
private:
    states battery;
    states motor;
    QPixmap batteryLabel;
    QPixmap motorLabel;
    Ui::MainWindow *ui;
};

#endif // WARNINGS_H
