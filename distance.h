#ifndef DISTANCE_H
#define DISTANCE_H

#include "ui_mainwindow.h"

class Distance
{
public:
    Distance();
    void setup(Ui::MainWindow *);
    void decrease_distance(int);
    void increase_distance(int);
    ~Distance() {}
private:
    int distance;
    Ui::MainWindow *ui;
};

#endif // DISTANCE_H
