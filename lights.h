#ifndef LIGHTS_H
#define LIGHTS_H

#include "states.h"
#include "ui_mainwindow.h"

class Lights {
public:
  Lights();
  void setup(Ui::MainWindow *, int, int);
  void day_on();
  void day_off();
  void night_on();
  void night_off();
  void off();
  ~Lights() {}

private:
  states day;
  states night;
  Ui::MainWindow *ui;
  QPixmap day_icon;
  QPixmap night_icon;
};

#endif // LIGHTS_H
