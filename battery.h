#ifndef BATTERY_H
#define BATTERY_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class Battery {
public:
  Battery();
  void setup(Ui::MainWindow *, uint16_t, uint16_t);
  void decrease_battery(uint8_t);
  void increase_battery(uint8_t);
  uint8_t get_battery() const;
  uint8_t get_range() const;
  void check_range();
  void on(warnings warning);
  void off(warnings warning);
  ~Battery(){};

private:
  uint8_t battery;
  float range;
  /* Efficency is (Miles traveled) per (Unit of Battery)*/
  const float efficiency_constant = .85f;
  QPixmap low_battery;
  QPixmap battery_fault;
  Ui::MainWindow *ui;
};

#endif // BATTERY_H
