#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "ui_mainwindow.h"
#include "states.h"

class TirePressure
{
public:
    TirePressure();
    void setup(Ui::MainWindow*);
//    void front_left_bad();
//    void front_right_bad();
//    void back_left_bad();
//    void back_right_bad();
//    void front_left_good();
//    void front_right_good();
//    void back_left_good();
//    void back_right_good();
    void lowPressure(tires tire);
    void normalPressure(tires tire);
    ~TirePressure() {};

private:
    int lowpressure;
    QPixmap lowpressure_label;
    QPixmap normalpressure_label;
    QPixmap car_label;
    Ui::MainWindow *ui;
};


#endif // TIREPRESSURE_H
