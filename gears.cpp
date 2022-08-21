#include "gears.h"
#include "scaler.h"

Gears::Gears() : gear(PARK), cruise(OFF) { return; }

void Gears::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;

  park = QPixmap(":/icons/parking.png");
  drive = QPixmap(":/icons/drive.png");
  neutral = QPixmap(":/icons/neutral.png");
  reverse = QPixmap(":/icons/reverse.png");

  ui->cruise_control->resize(width * 10 / 100, width * 10 / 100);
  ui->cruise_control->move(
      (width - (width * ICON_COUNT) / 10) / 2 +
          (ui->cruise_control->width() * CRUISE_CONTROL_ICON),
      0);
  cruise_control = QPixmap(":/icons/cruise.png");

  qDebug() << "CRUISE" << width << ui->cruise_control->width()
           << ui->cruise_control->x() << ui->cruise_control->y();

  ui->park_label->resize(100, 100);
  ui->park_label->move(width / 2 - ui->park_label->width() / 2,
                       height - ui->park_label->height() - 100);

  qDebug() << "PARK LABEL" << ui->park_label->x() << ui->park_label->y();

  this->ui->park_label->setPixmap(park);
}

void Gears::switch_gears(gears state) {
  if (state == PARK) {
    gear = state;
    cruise_off();

    this->ui->park_label->setPixmap(park);

  } else if (state == DRIVE) {
    gear = state;

    this->ui->park_label->setPixmap(drive);
  } else if (state == NEUTRAL) {
    gear = state;
    cruise_off();

    this->ui->park_label->setPixmap(neutral);
  } else if (state == REVERSE) {
    gear = state;
    cruise_off();

    this->ui->park_label->setPixmap(reverse);
  }
}

void Gears::cruise_on() {
  if (gear == DRIVE) {
    this->cruise = ON;
    this->ui->cruise_control->setPixmap(cruise_control);
  } else {
    cruise_off();
  }
}

void Gears::cruise_off() {
  this->cruise = OFF;
  this->ui->cruise_control->setText("OFF");
}
