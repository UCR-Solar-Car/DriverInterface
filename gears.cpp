#include "gears.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  park = QPixmap(":/icons/parking.png");
  drive = QPixmap(":/icons/drive.png");
  neutral = QPixmap(":/icons/neutral.png");
  reverse = QPixmap(":/icons/reverse.png");

  this->ui->park_label->setPixmap(park);
  this->ui->drive_label->setText("OFF");
  this->ui->neutral_label->setText("OFF");
  this->ui->reverse_label->setText("OFF");
}

void Gears::switch_gears(gears state) {
  if (state == PARK) {
    gear = state;

    this->ui->drive_label->setText("OFF");
    this->ui->neutral_label->setText("OFF");
    this->ui->reverse_label->setText("OFF");

    this->ui->park_label->setPixmap(park);
  } 
  else if (state == DRIVE) {
    gear = state;

    this->ui->park_label->setText("OFF");
    this->ui->neutral_label->setText("OFF");
    this->ui->reverse_label->setText("OFF");

    this->ui->drive_label->setPixmap(drive);
  }
  else if (state == NEUTRAL) {
    gear = state;

    this->ui->park_label->setText("OFF");
    this->ui->drive_label->setText("OFF");
    this->ui->reverse_label->setText("OFF");

    this->ui->neutral_label->setPixmap(neutral);
  }
  else if (state == REVERSE) {
    gear = state;

    this->ui->park_label->setText("OFF");
    this->ui->drive_label->setText("OFF");
    this->ui->neutral_label->setText("OFF");

    this->ui->reverse_label->setPixmap(reverse);
  }
}
