#ifndef GEARS_H
#define GEARS_H

#include "ui_mainwindow.h"
#include "states.h"

class Gears {
  public:
    Gears();
    void setup(Ui::MainWindow *);
    void switch_gears(gears);
    
  private:
    Ui::MainWindow *ui;
    gears gear;
    QPixmap park;
    QPixmap drive;
    QPixmap reverse;
    QPixmap neutral;
};

#endif
