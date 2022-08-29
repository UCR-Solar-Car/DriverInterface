#ifndef BATTERY_H
#define BATTERY_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class Battery {
public:
  Battery();
  void setup(QProgressBar*, QLabel*, QLabel*, QLabel*, QLCDNumber*, uint16_t, uint16_t);
  void decrease_battery(uint8_t);
  void increase_battery(uint8_t);
  uint8_t get_battery();
  uint8_t get_range();
  void check_range();
  void on(warnings warning);
  void off(warnings warning);
  ~Battery(){};

private:
  uint8_t battery_val;
  float range_val;
  /* Efficency is (Miles traveled) per (Unit of Battery)*/
  const float efficiency_constant = .85f;
  QPixmap low_battery;
  QPixmap battery_fault;
  QProgressBar* battery;
  QLabel* range_label;
  QLabel* low_battery_label;
  QLabel* battery_label;
  QLCDNumber* range;
};

#endif // BATTERY_H
