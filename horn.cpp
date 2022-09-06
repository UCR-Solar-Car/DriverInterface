#include "horn.h"

Horn::Horn() : horn(OFF) {}

void Horn::setup(QLabel* horn_label_ptr, uint16_t height, uint16_t width) {
  horn_label = horn_label_ptr;

  horn_icon = QPixmap(":/icons/horn.png");
  horn_label->setText("");

  horn_label->resize(width * 10 / 100, width * 10 / 100);
  horn_label->move((width - (width * ICON_COUNT) / 10) / 2 + (horn_label->width() * HORN_ICON), 0);
}

void Horn::horn_on() {
  horn = ON;
  horn_label->setPixmap(horn_icon);
}

void Horn::horn_off() {
  horn = OFF;
  horn_label->setText("");
}
