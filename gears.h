#ifndef GEARS_H
#define GEARS_H

#include "states.h"
#include "ui_mainwindow.h"

class Gears {
public:
  Gears();
  void setup(Ui::MainWindow *, int, int);
  void switch_gears(gears);
  void cruise_on();
  void cruise_off();

private:
  Ui::MainWindow *ui;
  gears gear;
  states cruise;
  QPixmap park;
  QPixmap drive;
  QPixmap reverse;
  QPixmap neutral;
  QPixmap cruise_control;
};

#endif
