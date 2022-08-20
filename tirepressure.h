#ifndef TIREPRESSURE_H
#define TIREPRESSURE_H

#include "ui_mainwindow.h"
#include "states.h"

class TirePressure
{
public:
    TirePressure();
    void setup(Ui::MainWindow*);
    void low_pressure(tires tire);
    void normal_pressure(tires tire);
    void increasePressure(tires tire);
    void decreasePressure(tires tire);
    ~TirePressure() {};

private:
    int lowpressure;
    int frontLeftPressure = 35;
    int frontRightPressure = 35;
    int backLeftPressure = 35;
    int backRightPressure = 35;
    QPixmap low_pressure_icon;
    QPixmap normal_pressure_icon;
    QPixmap car_icon;
    Ui::MainWindow *ui;
};


#endif // TIREPRESSURE_H
