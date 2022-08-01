#ifndef CRUISE_H
#define CRUISE_H

#include "ui_mainwindow.h"
#include "states.h"

class CruiseControl {
  public:
    CruiseControl();
    void setup(Ui::MainWindow*);
    void cruise_on();
    void cruise_off();
    ~CruiseControl() {};

  private:
    Ui::MainWindow *ui;
    states cruise;
    QPixmap cruiseControlIcon;
};

#endif
