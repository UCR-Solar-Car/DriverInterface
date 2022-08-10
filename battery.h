#ifndef BATTERY_H
#define BATTERY_H

#include "ui_mainwindow.h"
#include "states.h"

class Battery
{
public:
    Battery();
    void setup(Ui::MainWindow *);
    void decrease_battery(int);
    void increase_battery(int);
    int get_battery();
    int get_range();
    void CheckRange();
    void on();
    void off();
    ~Battery() {};

private:
    int battery;
    double range;
    /* Efficency is (Miles traveled) per (Unit of Battery)*/
    const double efficiencyConstant = .85;
    QPixmap lowBatteryIcon;
    Ui::MainWindow *ui;
};

#endif // BATTERY_H
