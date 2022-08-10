#ifndef INDICATORS_H
#define INDICATORS_H

#include "ui_mainwindow.h"
#include "states.h"
#include <QTimer>

class Indicators: public QObject
{
    Q_OBJECT
public:
    Indicators();
    void setup(Ui::MainWindow *);
    void left_on();
    void left_off();
    void right_on();
    void right_off();
    void hazard_on();
    void hazard_off();;
private:
    states right;
    states left;
    QPixmap leftSignal;
    QPixmap rightSignal;
    Ui::MainWindow * ui;
};

#endif // INDICATORS_H
