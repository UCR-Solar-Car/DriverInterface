#include "speed.h"

Speed::Speed() : speed(25) {}

void Speed::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->speed = 25;
  this->ui->speed->display(speed);
}

void Speed::increaseSpeed(int value) {
  if (speed + value < 100) {
    this->speed += value;
    this->ui->speed->display(speed);
  }
}

void Speed::decreaseSpeed(int value) {
  if (speed - value > -1) {
    this->speed -= value;
    this->ui->speed->display(speed);
  }
}
