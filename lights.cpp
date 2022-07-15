#include "lights.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  ui->nightLights->setText("OFF");
  ui->dayLights->setText("OFF");
  dayLights = QPixmap(":/icons/day.png");
  nightLights = QPixmap(":/icons/night.png");
}

void Lights::day_on() {
  day = ON;
  night = OFF;
  ui->dayLights->setPixmap(dayLights);
  ui->nightLights->setText("OFF");
}

void Lights::day_off() {
  day = OFF;
  ui->dayLights->setText("OFF");
}

void Lights::night_on() {
  day = OFF;
  night = ON;
  ui->nightLights->setPixmap(nightLights);
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
