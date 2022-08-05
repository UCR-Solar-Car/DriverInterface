#ifndef WARNINGS_H
#define WARNINGS_H

#include "ui_mainwindow.h"
#include "states.h"

struct WarningLabel{
    WarningLabel(states state, QPixmap image, QLabel* label) : state(state), image(image), label(label){}
    states state;
    QPixmap image;
    QLabel* label;
};

class Warnings
{
public:
    Warnings();
    void setup(Ui::MainWindow*);
    void on(QLabel* inputLabel);
    void off(QLabel* inputLabel);
    ~Warnings() {};
private:
    std::vector<WarningLabel> warningLabels;
    Ui::MainWindow *ui;
};

#endif // WARNINGS_H
