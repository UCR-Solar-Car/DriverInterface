#include "../headers/gears.h"

Gears::Gears() : gear(DRIVE), cruise(OFF) {}

void Gears::setup(QLabel* park_label_ptr, QLabel* cruise_control_label_ptr, uint16_t height, uint16_t width) {
  park_label = park_label_ptr;
  cruise_control_label = cruise_control_label_ptr;

  park = QPixmap(":/icons/parking.png");
  drive = QPixmap(":/icons/drive.png");
  neutral = QPixmap(":/icons/neutral.png");
  reverse = QPixmap(":/icons/reverse.png");

  cruise_control_label->resize(width * 10 / 100, width * 10 / 100);
  cruise_control_label->move((width - (width * ICON_COUNT) / 10) / 2 + (cruise_control_label->width() * CRUISE_CONTROL_ICON), height * 0.1);
  cruise_control = QPixmap(":/icons/cruise.png");


  park_label->resize(100, 100);
  park_label->move(width / 2 - park_label->width() / 2,
                       height *.95 - park_label->height() );


  park_label->setPixmap(drive);
  cruise_control_label->setText("");
  cruise_on();
}

void Gears::switch_gears(gears state) {
  if (state == PARK) {
    gear = state;

    park_label->setPixmap(park);

  } else if (state == DRIVE) {
    gear = state;

    park_label->setPixmap(drive);

  } else if (state == NEUTRAL) {
    gear = state;

    park_label->setPixmap(neutral);

  } else if (state == REVERSE) {
    gear = state;

    park_label->setPixmap(reverse);
  }
  cruise_off();
}

void Gears::cruise_on() {
  if (gear == DRIVE) {
    cruise = ON;
    cruise_control_label->setPixmap(cruise_control);
  } else {
    cruise_off();
  }
}

void Gears::cruise_off() {
  cruise = OFF;
  cruise_control_label->setText("");
}
