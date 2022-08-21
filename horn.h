#ifndef HORN_H
#define HORN_H

#include "states.h"
#include "ui_mainwindow.h"

class Horn {
public:
  Horn();
  void setup(Ui::MainWindow *, int, int);
  void horn_on();
  void horn_off();
  ~Horn(){};

private:
  states horn;
  QPixmap horn_icon;
  Ui::MainWindow *ui;
};

#endif // HORN_H
