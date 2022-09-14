#ifndef BATTERY_H
#define BATTERY_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class Battery
{
public:
  Battery();
  void setup(QProgressBar *battery_ptr, QLabel *range_label_ptr, QLabel *low_battery_label_ptr, QLabel *battery_label_ptr, QLCDNumber *range_ptr, QLabel *distance_label_ptr, QFrame *battery_line_1_ptr, QFrame *battery_line_2_ptr, QFrame *battery_line_3_ptr, QFrame *battery_line_4_ptr, uint16_t height, uint16_t width);
  void decrease_battery(uint8_t);
  void increase_battery(uint8_t);
  uint8_t get_battery() const;
  uint8_t get_range() const;
  void check_range();
  void on(warnings warning);
  void off(warnings warning);
  ~Battery(){};

private:
  uint8_t battery_val;
  float range_val;
  QPixmap low_battery;
  QPixmap battery_fault;
  QProgressBar *battery;
  QLabel *range_label;
  QLabel *low_battery_label;
  QLabel *battery_label;
  QLCDNumber *range;
};

#endif // BATTERY_H
