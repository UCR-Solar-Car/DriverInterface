#include "speed.h"

Speed::Speed() : speed(25) {}

void Speed::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;
  this->ui->speed->display(speed);

  ui->speed->resize(width / 3, height / 3);
  ui->speed->move(width / 2 - ui->speed->width() / 2,height / 2 - ui->speed->height() / 2);

  ui->mph->resize(width / 3, height / 3);
  ui->mph->move(width / 2 - ui->speed->width() / 2, height / 2);
}

void Speed::increase_speed(uint8_t value) {
  if (speed + value < 100) {
    this->speed += value;
    this->ui->speed->display(speed);
  }
}

void Speed::decrease_speed(uint8_t value) {
  if (speed - value > -1) {
    this->speed -= value;
    this->ui->speed->display(speed);
  }
}
