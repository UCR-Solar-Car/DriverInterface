#ifndef HORN_H
#define HORN_H

#include "ui_mainwindow.h"
#include "states.h"

class Horn
{
public:
    Horn();
    void setup(Ui::MainWindow *);
    void horn_on();
    void horn_off();
    ~Horn() {};
private:
    states horn;
    QPixmap hornSignal;
    Ui::MainWindow *ui;
};

#endif // HORN_H
