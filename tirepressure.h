#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class TirePressure {
public:
  TirePressure();
  void setup(Ui::MainWindow *, uint16_t, uint16_t);
  void increasePressure(tires tire);
  void decreasePressure(tires tire);
  ~TirePressure(){};

private:
  uint8_t front_left_pressure;
  uint8_t front_right_pressure;
  uint8_t back_left_pressure;
  uint8_t back_right_pressure;
  uint8_t pressure_threshold;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
  Ui::MainWindow *ui;
};

#endif // TIREPRESSURE_H
