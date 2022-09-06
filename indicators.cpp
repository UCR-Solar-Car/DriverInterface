#include "indicators.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) {}


void Indicators::setup(QLabel* left_indicator_ptr, QLabel* right_indicator_ptr, uint16_t height, uint16_t width) {
  left_indicator = left_indicator_ptr;
  right_indicator = right_indicator_ptr;
  left_indicator->setText("");
  right_indicator->setText("");

  left_indicator->resize(100, 100);
  right_indicator->resize(100, 100);

  left_indicator->move(0, height / 2 - left_indicator->height() / 2);
  right_indicator->move(width - right_indicator->width(), height / 2 - right_indicator->height() / 2);

  left_icon = QPixmap(":/icons/left.png");
  right_icon = QPixmap(":/icons/right.png");
}

void Indicators::left_on() {
  left = ON;
  left_indicator->setPixmap(left_icon);
  right_off();
}

void Indicators::left_off() {
  left = OFF;
  left_indicator->setText("");
}

void Indicators::right_on() {
  right = ON;
  right_indicator->setPixmap(right_icon);
  left_off();
}

void Indicators::right_off() {
  right = OFF;
  right_indicator->setText("");
}

void Indicators::hazard_on() {
  left = ON;
  right = ON;
  left_indicator->setPixmap(left_icon);
  right_indicator->setPixmap(right_icon);
}

void Indicators::hazard_off() {
  right_off();
  left_off();
}

states Indicators::get_left_indicator_state() { return left; }

states Indicators::get_right_indicator_state() { return right; }

void Indicators::off() {
  left_indicator->setText("");
  right_indicator->setText("");
}
