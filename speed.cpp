#include "speed.h"
#include "scaler.h"

Speed::Speed() : speed(25) {}

void Speed::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  ui->speed->display(speed);

  ui->speed->resize(width / 3, height / 3);
  ui->speed->move(width / 2 - ui->speed->width() / 2,height / 2 - ui->speed->height() / 2);

  ui->mph->resize(width / 3, height / 3);
  ui->mph->move(width / 2 - ui->speed->width() / 2, height / 2);
}

void Speed::increase_speed(int value) {
  if (speed + value < 100) {
    speed += value;
    ui->speed->display(speed);
  }
}

void Speed::decrease_speed(int value) {
  if (speed - value > -1) {
    speed -= value;
    ui->speed->display(speed);
  }
}
