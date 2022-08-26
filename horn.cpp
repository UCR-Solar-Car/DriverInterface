#include "horn.h"

Horn::Horn() : horn(OFF) {}

void Horn::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;

  horn_icon = QPixmap(":/icons/horn.png");
  this->ui->horn_label->setText("OFF");

  ui->horn_label->resize(width * 10 / 100, width * 10 / 100);
  ui->horn_label->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->horn_label->width() * HORN_ICON), 0);
}

void Horn::horn_on() {
  this->horn = ON;
  this->ui->horn_label->setPixmap(horn_icon);
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->horn_label->setText("OFF");
}
