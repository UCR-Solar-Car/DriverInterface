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
    // states park;
    // states drive;
    // states neutral;
    // states reverse;
    QPixmap parkingIcon;
    QPixmap drivingIcon;
    QPixmap reversingIcon;
    QPixmap neutralIcon;
};

#endif
