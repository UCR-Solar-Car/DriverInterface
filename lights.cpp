#include "lights.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  ui->nightLights->setText("OFF");
  ui->dayLights->setText("OFF");
}

void Lights::day_on() {
  day = ON;
  night = OFF;
  ui->dayLights->setPixmap(
      QPixmap("/Users/shahdivyank/Documents/DriverInterface/day.png"));
  ui->nightLights->setText("OFF");
}

void Lights::day_off() {
  day = OFF;
  ui->dayLights->setText("OFF");
}

void Lights::night_on() {
  day = OFF;
  night = ON;
  ui->nightLights->setPixmap(
      QPixmap("/Users/shahdivyank/Documents/DriverInterface/night.png"));
  ui->dayLights->setText("OFF");
}

void Lights::night_off() {
  night = OFF;
  ui->nightLights->setText("OFF");
}

void Lights::off() {
  day = OFF;
  night = OFF;
  ui->nightLights->setText("OFF");
  ui->dayLights->setText("OFF");
}
