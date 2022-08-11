#ifndef MOTOR_H
#define MOTOR_H

#include "ui_mainwindow.h"
#include "states.h"
#include <unordered_map>
#include <iostream>

class Motor
{
public:
    Motor();
    void setup(Ui::MainWindow*);
    void on(warnings warning);
    void off(warnings warning);
    ~Motor() {};
private:
    QPixmap motor_fault;
    Ui::MainWindow *ui;
};

#endif // WARNINGS_H
