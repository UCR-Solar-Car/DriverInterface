#ifndef SPEED_H
#define SPEED_H

#include "../ui_mainwindow.h"

class Speed {
public:
  Speed();
  void setup(QLCDNumber *, QLabel *, uint16_t, uint16_t);
  void increase_speed(uint8_t value);
  void decrease_speed(uint8_t value);
  ~Speed(){};

private:
  uint8_t speed_value;
  QLCDNumber *speed;
  QLabel *mph;
};

#endif // SPEED_H
