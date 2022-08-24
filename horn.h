#ifndef HORN_H
#define HORN_H

#include "global_variables.h"
#include "ui_mainwindow.h"

class Horn {
public:
  Horn();
  void setup(Ui::MainWindow *, uint8_t, uint8_t);
  void horn_on();
  void horn_off();
  ~Horn(){};
  
private:
  states horn;
  QPixmap horn_icon;
  Ui::MainWindow *ui;
};

#endif // HORN_H
