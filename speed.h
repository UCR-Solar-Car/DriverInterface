#ifndef SPEED_H
#define SPEED_H

#include "ui_mainwindow.h"

class Speed
{
public:
    Speed();
    void setup(Ui::MainWindow *);
    void increaseSpeed(int value);
    void decreaseSpeed(int value);
    ~Speed() {};
   private:
    int speed;
    Ui::MainWindow * ui;
};

#endif // SPEED_H
