#ifndef DISTANCE_H
#define DISTANCE_H

#include "ui_mainwindow.h"

class Distance {
public:
  Distance();
  void setup(QLabel*, QLabel*, uint16_t, uint16_t);
  void decrease_distance(uint8_t);
  void increase_distance(uint8_t);
  ~Distance() {}

private:
  uint8_t distance_val;
  QLabel* distance_label;
  QLabel* distance;
};

#endif // DISTANCE_H
