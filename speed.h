#ifndef SPEED_H
#define SPEED_H

#include "ui_mainwindow.h"

class Speed {
public:
  Speed();
  void setup(Ui::MainWindow *, uint16_t, uint16_t);
  void increase_speed(uint8_t value);
  void decrease_speed(uint8_t value);
  ~Speed(){};

private:
  uint8_t speed;
  Ui::MainWindow *ui;
};

#endif // SPEED_H
