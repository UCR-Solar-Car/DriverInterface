#include "../headers/lights.h"

Lights::Lights() : day(OFF), night(OFF) {}

void Lights::setup(QLabel* day_lights_ptr, QLabel* night_lights_ptr, uint16_t height, uint16_t width) {
  day_lights = day_lights_ptr;
  night_lights = night_lights_ptr;
  night_lights->setText("OFF");
  day_lights->setText("OFF");

  day_lights->resize(width * 10 / 100, width * 10 / 100);
  day_lights->move((width - (width * ICON_COUNT) / 10) / 2 +(day_lights->width() * DAY_LIGHTS_ICON),0);
  day_icon = QPixmap(":/icons/day.png");

  night_lights->resize(width * 10 / 100, width * 10 / 100);
  night_lights->move((width - (width * ICON_COUNT) / 10) / 2 +(night_lights->width() * NIGHT_LIGHTS_ICON),0);
  night_icon = QPixmap(":/icons/night.png");
}

void Lights::day_on() {
  day = ON;
  day_lights->setPixmap(day_icon);
  night_off();
}

void Lights::day_off() {
  day = OFF;
  day_lights->setText("OFF");
}

void Lights::night_on() {
  night = ON;
  night_lights->setPixmap(night_icon);
  day_off();
}

void Lights::night_off() {
  night = OFF;
  night_lights->setText("OFF");
}

void Lights::off() {
  day_off();
  night_off();
}
