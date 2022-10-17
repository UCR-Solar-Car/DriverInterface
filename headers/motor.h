#ifndef MOTOR_H
#define MOTOR_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"
#include <iostream>
#include <unordered_map>

class Motor {
public:
  Motor();
  void setup(QLabel *motor_label, uint16_t, uint16_t);
  void on(warnings warning);
  void off(warnings warning);
  void reset();
  ~Motor(){};

private:
  QPixmap motor_fault;
  QLabel *motor_label;
};

#endif // WARNINGS_H
