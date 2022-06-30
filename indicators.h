#ifndef INDICATORS_H
#define INDICATORS_H

#include "ui_mainwindow.h"
#include "states.h"

class Indicators
{
public:
    Indicators();
    void setup(Ui::MainWindow *);
    void left_on();
    void left_off();
    void right_on();
    void right_off();
    void hazard_on();
    void hazard_off();
    ~Indicators() {}
private:
    states right;
    states left;
    Ui::MainWindow * ui;
};

#endif // INDICATORS_H
