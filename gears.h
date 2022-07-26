#ifndef GEARS_H
#define GEARS_H

#include "ui_mainwindow.h"
#include "states.h"

class Gears {
  public:
    Gears();
    void setup(Ui::MainWindow *);
    void parking();
    void driving();
    void reversing();
    void not_parking();
    void not_driving();
    void not_reversing();
    void updates();
  private:
    Ui::MainWindow *ui;
    QPixmap parkSignal;
    QPixmap driveSignal;
    QPixmap reverseSignal;
    states gear;
};

#endif
