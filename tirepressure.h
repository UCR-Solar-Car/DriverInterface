#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "ui_mainwindow.h"

class TirePressure
{
public:
    TirePressure();
    void setup(Ui::MainWindow*);
    void front_left_bad();
    void front_right_bad();
    void back_left_bad();
    void back_right_bad();
    void front_left_good();
    void front_right_good();
    void back_left_good();
    void back_right_good();
    ~TirePressure() {};

private:
    int threshold;
    QPixmap warning_label;
    QPixmap tire_label;
    QPixmap car_label;
    Ui::MainWindow *ui;
};


#endif // TIREPRESSURE_H
