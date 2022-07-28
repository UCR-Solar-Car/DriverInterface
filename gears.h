#ifndef GEARS_H
#define GEARS_H

#include "ui_mainwindow.h"
#include "states.h"

class Gears {
  public:
    Gears();
    void setup(Ui::MainWindow *);
    void switchGears(int);
    
  private:
    Ui::MainWindow *ui;
    gears gear;
    QPixmap parkingSignal;
    QPixmap drivingSignal;
    QPixmap reversingSignal;
    QPixmap neutralSignal;
};

#endif
