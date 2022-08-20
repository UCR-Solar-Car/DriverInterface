#include "horn.h"
#include "scaler.h"

Horn::Horn() : horn(OFF) { return; }

void Horn::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;

  ui->horn_label->resize(width * 10 / 100, width * 10 / 100);
  ui->horn_label->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->horn_label->width() * HORN_ICON), 0);
  horn_icon = QPixmap(":/icons/horn.png");

  qDebug() << "HORN" << width << ui->horn_label->width() << ui->horn_label->x() << ui->horn_label->y();

  this->ui->horn_label->setText("OFF");
}

void Horn::horn_on() {
  this->horn = ON;
  this->ui->horn_label->setPixmap(horn_icon);
}

void Horn::horn_off() {
  this->horn = OFF;
  this->ui->horn_label->setText("OFF");
}
