#ifndef WARNINGS_H
#define WARNINGS_H

#include "ui_mainwindow.h"
#include "states.h"

class Warnings
{
public:
    Warnings();
    void setup(Ui::MainWindow*);
    void on(QLabel* inputLabel);
    void off(QLabel* inputLabel);
    ~Warnings() {};
private:
    std::vector<states> warningState;
    std::vector<QPixmap> warningPixmap;
    std::vector<QLabel*> warningLabels;
    Ui::MainWindow *ui;
};

#endif // WARNINGS_H
