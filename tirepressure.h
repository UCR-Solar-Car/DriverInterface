#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class TirePressure {
public:
  TirePressure();
  void setup(Ui::MainWindow *, int, int);
  void increasePressure(tires tire);
  void decreasePressure(tires tire);
  ~TirePressure(){};

private:
  int front_left_pressure;
  int front_right_pressure;
  int back_left_pressure;
  int back_right_pressure;
  int pressure_threshold;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
  Ui::MainWindow *ui;
};

#endif // TIREPRESSURE_H
