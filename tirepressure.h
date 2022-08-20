#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class TirePressure {
public:
  TirePressure();
  void setup(Ui::MainWindow *, int, int);
  void low_pressure(tires tire);
  void normal_pressure(tires tire);
  ~TirePressure(){};

private:
  int lowpressure;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
  QPixmap car_icon;
  Ui::MainWindow *ui;
};

#endif // TIREPRESSURE_H
