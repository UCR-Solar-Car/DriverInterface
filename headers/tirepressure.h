#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class TirePressure {
public:
  TirePressure();

  void setup(QLabel *,QLabel *,QLabel *,QLabel *, uint16_t, uint16_t);
  void increasePressure(tires tire);
  void decreasePressure(tires tire);
  ~TirePressure(){};

private:
  uint8_t front_left_pressure;
  uint8_t front_right_pressure;
  uint8_t back_left_pressure;
  uint8_t back_right_pressure;
  const uint8_t pressure_threshold = 30;
  QLabel *front_left;
  QLabel *front_right;
  QLabel *back_left;
  QLabel *back_right;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
};

#endif // TIREPRESSURE_H
