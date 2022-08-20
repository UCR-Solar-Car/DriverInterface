#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "states.h"
#include "ui_mainwindow.h"

class TirePressure {
public:
  TirePressure();
  void setup(Ui::MainWindow *, int, int);
  void increasePressure(tires tire);
  void decreasePressure(tires tire);
  ~TirePressure(){};

private:
  int lowpressure;
  int frontLeftPressure;
  int frontRightPressure;
  int backLeftPressure;
  int backRightPressure;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
  QPixmap car_icon;
  Ui::MainWindow *ui;
};

#endif // TIREPRESSURE_H
