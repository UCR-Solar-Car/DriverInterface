#include "gears.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  parkingSignal = QPixmap(":/icons/parking.png");
  drivingSignal = QPixmap(":/icons/drive.png");
  neutralSignal = QPixmap(":/icons/neutral.png");
  reversingSignal = QPixmap(":/icons/reverse.png");
}

void Gears::switchGears(int state) {
  if (state == 0) {
    this->gear = PARK;
    // this->ui->parkingSignal->setPixmap(parkingSignal);
  } 
  else if (state == 1) {
    this->gear = DRIVE;
    // this->ui->drivingSignal->setPixmap(drivingSignal);
  }
  else if (state == 2) {
    this->gear = NEUTRAL;
    // this->ui->neutralSignal->setPixmap(neutralSignal);
  }
  else if (state == 3) {
    this->gear = REVERSE;
    // this->ui->reversingSignal->setPixmap(reversingSignal);
  }
}
