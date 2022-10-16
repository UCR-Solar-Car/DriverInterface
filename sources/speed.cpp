#include "../headers/speed.h"

Speed::Speed() : speed_value(0) {}


void Speed::setup(QLCDNumber *speed, QLabel *mph, uint16_t height, uint16_t width) {
  this->speed = speed;
  this->mph = mph;
  speed->display(speed_value);

  speed->resize(width / 3, height / 3);
  speed->move(width / 2 - speed->width() / 2,height / 2 - speed->height() / 1.6);

  mph->resize(width / 3, height / 3);
  mph->move(width / 2 - speed->width() / 2, height / 2);
}

void Speed::increase_speed(uint8_t value) {
  if (speed_value + value < 100) {
    this->speed_value += value;
    speed->display(speed_value);
  }
}

void Speed::reset(){
    speed_value = 0;
    speed->display(speed_value);
}

void Speed::decrease_speed(uint8_t value) {
  if (speed_value - value > -1) {
    this->speed_value -= value;
    speed->display(speed_value);
  }
}
