#ifndef INDICATORS_H
#define INDICATORS_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class Indicators {

public:
  Indicators();
  void setup(QLabel*, QLabel*, uint16_t, uint16_t);
  void left_on();
  void left_off();
  void right_on();
  void right_off();
  void hazard_on();
  void hazard_off();
  states get_right_indicator_state() const;
  states get_left_indicator_state() const;
  void off();

private:
  states right;
  states left;
  QPixmap left_icon;
  QPixmap right_icon;
  QLabel* left_indicator;
  QLabel* right_indicator;
};

#endif // INDICATORS_H
