#include "lights.h"
#include "scaler.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");
  double topIconWH = topIconScaler * screenWidth;
  day_icon = QPixmap(":/icons/day.png")
                 .scaled(topIconWH, topIconWH, Qt::KeepAspectRatio,
                         Qt::SmoothTransformation);
  night_icon = QPixmap(":/icons/night.png")
                   .scaled(topIconWH, topIconWH, Qt::KeepAspectRatio,
                           Qt::SmoothTransformation);
  ui->day_lights->move(screenWidth / 2 - topIconWH * .5, vOff + 4);
  ui->night_lights->move(screenWidth / 2 + topIconWH * .5, vOff - 7);
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
