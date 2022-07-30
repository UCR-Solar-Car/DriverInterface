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

void Gears::switchGears(int state) {
  if (state == 0) {
    gear = PARK;

    this->ui->drivingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->parkingSignal->setPixmap(parkingIcon);
  } 
  else if (state == 1) {
    gear = DRIVE;

    this->ui->parkingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->drivingSignal->setPixmap(drivingIcon);
  }
  else if (state == 2) {
    gear = NEUTRAL;

    this->ui->parkingSignal->setText("OFF");
    this->ui->drivingSignal->setText("OFF");
    this->ui->reversingSignal->setText("OFF");

    this->ui->neutralSignal->setPixmap(neutralIcon);
  }
  else if (state == 3) {
    gear = REVERSE;

    this->ui->parkingSignal->setText("OFF");
    this->ui->drivingSignal->setText("OFF");
    this->ui->neutralSignal->setText("OFF");

    this->ui->reversingSignal->setPixmap(reversingIcon);
  }
}
