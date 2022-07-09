#ifndef RANGE_H
#define RANGE_H

#include "ui_mainwindow.h"

class Range
{
public:
    Range();
    void setup(Ui::MainWindow *);
    void decrease_range(int);
    void increase_range(int);
    ~Range() {}
private:
    int range;
    Ui::MainWindow *ui;
};

#endif // RANGE_H
