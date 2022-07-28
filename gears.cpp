#include "gears.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  parkingIcon = QPixmap(":/icons/parking.png");
  drivingIcon = QPixmap(":/icons/drive.png");
  neutralIcon = QPixmap(":/icons/neutral.png");
  reversingIcon = QPixmap(":/icons/reverse.png");

  this->ui->parkingSignal->setPixmap(parkingIcon);
  // this->ui->parkingSignal->setText("PARK");
  this->ui->drivingSignal->setText("DRIVE");
  this->ui->neutralSignal->setText("NEUTRAL");
  this->ui->reversingSignal->setText("REVERSE");
}

void Gears::switchGears(int state) {
  if (state == 0) {
    gear = PARK;

    this->ui->drivingSignal->setText("DRIVE");
    this->ui->neutralSignal->setText("NEUTRAL");
    this->ui->reversingSignal->setText("REVERSE");

    // park = ON;
    // drive = OFF;
    // neutral = OFF;
    // reverse = OFF;
    
    // this->ui->drivingSignal->setText("DRIVE");

    this->ui->parkingSignal->setPixmap(parkingIcon);
  } 
  else if (state == 1) {
    gear = DRIVE;

    this->ui->parkingSignal->setText("PARK");
    this->ui->neutralSignal->setText("NEUTRAL");
    this->ui->reversingSignal->setText("REVERSE");

    // park = OFF;
    // drive = ON;
    // neutral = OFF;
    // reverse = OFF;

    this->ui->drivingSignal->setPixmap(drivingIcon);
  }
  else if (state == 2) {
    gear = NEUTRAL;

    this->ui->parkingSignal->setText("PARK");
    this->ui->drivingSignal->setText("DRIVE");
    this->ui->reversingSignal->setText("REVERSE");

    // park = OFF;
    // drive = OFF;
    // neutral = ON;
    // reverse = OFF;

    this->ui->neutralSignal->setPixmap(neutralIcon);
  }
  else if (state == 3) {
    gear = REVERSE;

    this->ui->parkingSignal->setText("PARK");
    this->ui->drivingSignal->setText("DRIVE");
    this->ui->neutralSignal->setText("NEUTRAL");

    // park = OFF;
    // drive = OFF;
    // neutral = OFF;
    // reverse = ON;

    this->ui->reversingSignal->setPixmap(reversingIcon);
  }
}
