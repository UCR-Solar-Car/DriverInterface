#ifndef SPEED_H
#define SPEED_H

#include "ui_mainwindow.h"

class Speed {
public:
  Speed();
  void setup(Ui::MainWindow *, int, int);
  void increase_speed(int value);
  void decrease_speed(int value);
  ~Speed(){};

private:
  int speed;
  Ui::MainWindow *ui;
};

#endif // SPEED_H
