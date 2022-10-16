#include "../headers/horn.h"

Horn::Horn() : horn(OFF) {}

void Horn::setup(QLabel *horn_label_ptr, uint16_t width, uint16_t height)
{
  horn_label = horn_label_ptr;

  horn_icon = QPixmap(":/icons/horn.png");
  horn_label->setText("");

  horn_label->resize(width * 10 / 100, width * 10 / 100);
  horn_label->move((width - (width * ICON_COUNT) / 10) / 2 + (horn_label->width() * HORN_ICON), height * 0.07);
  horn_on();
}

void Horn::horn_on()
{
  horn = ON;
  horn_label->setPixmap(horn_icon);
}

void Horn::horn_off()
{
  horn = OFF;
  horn_label->setText(" ");
}
