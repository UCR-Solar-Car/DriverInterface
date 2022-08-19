#include "speed.h"
#include "scaler.h"

Speed::Speed() : speed(25) {}

void Speed::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  this->speed = 25;
  this->ui->speed->display(speed);
  int speedSize = screenWidth * .20;
  ui->speed->resize(speedSize, speedSize);
  ui->speed->move(3 * screenWidth / 5, screenHeight / 4);
  ui->mph->move(3 * screenWidth / 5, screenHeight / 4 + speedSize);
}

void Speed::increase_speed(int value) {
  if (speed + value < 100) {
    this->speed += value;
    this->ui->speed->display(speed);
  }
}

void Speed::decrease_speed(int value) {
  if (speed - value > -1) {
    this->speed -= value;
    this->ui->speed->display(speed);
  }
}
