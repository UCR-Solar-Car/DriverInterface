#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class TirePressure
{
public:
  TirePressure();

  void setup(QLabel *,QLabel *,QLabel *,QLabel *, QLCDNumber *, QLCDNumber *, QLCDNumber *, QLCDNumber *, uint16_t, uint16_t);
  void increasePressure(tires tire);
  void decreasePressure(tires tire);
  void reset();
  ~TirePressure(){};

private:
  uint8_t front_left_pressure;
  uint8_t front_right_pressure;
  uint8_t back_left_pressure;
  uint8_t back_right_pressure;
  QLabel *front_left;
  QLabel *front_right;
  QLabel *back_left;
  QLabel *back_right;
  QLCDNumber *front_left_lcd;
  QLCDNumber *front_right_lcd;
  QLCDNumber *back_left_lcd;
  QLCDNumber *back_right_lcd;
  QPixmap low_pressure_icon;
  QPixmap normal_pressure_icon;
};

#endif // TIREPRESSURE_H
