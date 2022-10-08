#ifndef GEARS_H
#define GEARS_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class Gears
{
public:
  Gears();
  void setup(QLabel *, QLabel *, uint16_t, uint16_t);
  void switch_gears(gears);
  void cruise_on();
  void cruise_off();
  void reset();

private:
  gears gear;
  states cruise;
  QPixmap park;
  QPixmap drive;
  QPixmap reverse;
  QPixmap neutral;
  QPixmap cruise_control;
  QLabel *park_label;
  QLabel *cruise_control_label;
};

#endif
