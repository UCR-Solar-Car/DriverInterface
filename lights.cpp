#include "lights.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");
  day_icon = QPixmap(":/icons/day.png");
  night_icon = QPixmap(":/icons/night.png");
}

void Lights::day_on() {
  day = ON;
  night = OFF;
  ui->day_lights->setPixmap(day_icon);
  ui->night_lights->setText("OFF");
}

void Lights::day_off() {
  day = OFF;
  ui->day_lights->setText("OFF");
}

void Lights::night_on() {
  day = OFF;
  night = ON;
  ui->night_lights->setPixmap(night_icon);
  ui->day_lights->setText("OFF");
}

void Lights::night_off() {
  night = OFF;
  ui->night_lights->setText("OFF");
}

void Lights::off() {
  day = OFF;
  night = OFF;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");
}
