#include "gears.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  parkingIcon = QPixmap(":/icons/parking.png");
  drivingIcon = QPixmap(":/icons/drive.png");
  neutralIcon = QPixmap(":/icons/neutral.png");
  reversingIcon = QPixmap(":/icons/reverse.png");

  this->ui->parkingSignal->setPixmap(parkingIcon);
  this->ui->drivingSignal->setText("OFF");
  this->ui->neutralSignal->setText("OFF");
  this->ui->reversingSignal->setText("OFF");
}

void Gears::switchGears(gears state) {
  if (state == PARK) {
    gear = state;

    this->ui->drivingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->parkingSignal->setPixmap(parkingIcon);
  } 
  else if (state == DRIVE) {
    gear = state;

    this->ui->parkingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->drivingSignal->setPixmap(drivingIcon);
  }
  else if (state == NEUTRAL) {
    gear = state;

    this->ui->parkingSignal->setText("OFF");
    this->ui->drivingSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->neutralSignal->setPixmap(neutralIcon);
  }
  else if (state == REVERSE) {
    gear = state;

    this->ui->parkingSignal->setText("OFF");
    this->ui->drivingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");

    this->ui->reversingSignal->setPixmap(reversingIcon);
  }
}
