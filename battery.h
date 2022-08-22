#ifndef BATTERY_H
#define BATTERY_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class Battery {
public:
  Battery();
  void setup(Ui::MainWindow *, int, int);
  void decrease_battery(int);
  void increase_battery(int);
  int get_battery();
  int get_range();
  void check_range();
  void on(warnings warning);
  void off(warnings warning);
  ~Battery(){};

private:
  int battery;
  double range;
  /* Efficency is (Miles traveled) per (Unit of Battery)*/
  const double efficiency_constant = .85;
  QPixmap low_battery;
  QPixmap battery_fault;
  Ui::MainWindow *ui;
};

#endif // BATTERY_H
