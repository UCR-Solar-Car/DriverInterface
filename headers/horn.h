#ifndef HORN_H
#define HORN_H

#include "../global_variables/global_variables.h"
#include "../ui_mainwindow.h"

class Horn {
public:
  Horn();
  void setup(QLabel*, uint16_t, uint16_t);
  void horn_on();
  void horn_off();
  ~Horn(){};

private:
  states horn;
  QPixmap horn_icon;
  QLabel* horn_label;
};

#endif // HORN_H
