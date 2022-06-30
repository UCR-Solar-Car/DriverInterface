#ifndef LIGHTS_H
#define LIGHTS_H

#include "ui_mainwindow.h"
#include "states.h"

class Lights
{
public:
    Lights();
    void setup(Ui::MainWindow*);
    void day_on();
    void day_off();
    void night_on();
    void night_off();
    void off();
    ~Lights() {}

private:
    states day;
    states night;
     Ui::MainWindow *ui;
};

#endif // LIGHTS_H
