#include "lights.h"
#include "scaler.h"

Lights::Lights() : day(OFF), night(OFF) { return; }

void Lights::setup(Ui::MainWindow *ui, int height, int width) {
  ui = ui;
  ui->night_lights->setText("OFF");
  ui->day_lights->setText("OFF");

  ui->day_lights->resize(width * 10 / 100, width * 10 / 100);
  ui->day_lights->move((width - (width * ICON_COUNT) / 10) / 2 +(ui->day_lights->width() * DAY_LIGHTS_ICON),0);
  day_icon = QPixmap(":/icons/day.png");

  ui->night_lights->resize(width * 10 / 100, width * 10 / 100);
  ui->night_lights->move((width - (width * ICON_COUNT) / 10) / 2 +(ui->night_lights->width() * NIGHT_LIGHTS_ICON),0);
  night_icon = QPixmap(":/icons/night.png");
}

void Lights::day_on() {
  day = ON;
  ui->day_lights->setPixmap(day_icon);
  night_off();
}

void Lights::day_off() {
  day = OFF;
  ui->day_lights->setText("OFF");
}

void Lights::night_on() {
  night = ON;
  ui->night_lights->setPixmap(night_icon);
  day_off();
}

void Lights::night_off() {
  night = OFF;
  ui->night_lights->setText("OFF");
}

void Lights::off() {
  day_off();
  night_off();
}
