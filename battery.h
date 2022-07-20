#ifndef BATTERY_H
#define BATTERY_H

#include "ui_mainwindow.h"

class Battery
{
public:
    Battery();
    void setup(Ui::MainWindow *);
    void decrease_battery(int);
    void increase_battery(int);
    int get_battery();
    int get_range();
    ~Battery() {};

private:
    int battery;
    int range;
    Ui::MainWindow *ui;
};

#endif // BATTERY_H
