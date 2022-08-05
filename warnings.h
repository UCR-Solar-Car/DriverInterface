#ifndef WARNINGS_H
#define WARNINGS_H

#include "ui_mainwindow.h"
#include "states.h"
#include <unordered_map>
#include <iostream>

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
    void on(warnings warning);
    void off(warnings warning);
    ~Warnings() {};
private:
    std::unordered_map<warnings, WarningLabel> warning_labels;
    Ui::MainWindow *ui;
};

#endif // WARNINGS_H
