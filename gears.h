#ifndef GEARS_H
#define GEARS_H

#include "ui_mainwindow.h"
#include "states.h"

class Gears {
  public:
    Gears();
    void setup(Ui::MainWindow *);
    void switch_gears(gears);
    void cruise_on();
    void cruise_off();
    
private slots:
    void on_increaseFrontLeftButton_clicked();

    void on_decreaseFrontLeftButton_clicked();

    void on_increaseFrontLeftButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    gears gear;
    states cruise;
    QPixmap park;
    QPixmap drive;
    QPixmap reverse;
    QPixmap neutral;
    QPixmap cruise_control;
};

#endif
