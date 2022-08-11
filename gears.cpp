#include "gears.h"
#include "scaler.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int driveModeIconWH = .09 * screenHeight;
  parkingIcon = QPixmap(":/icons/parking.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  drivingIcon = QPixmap(":/icons/drive.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  neutralIcon = QPixmap(":/icons/neutral.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  reversingIcon = QPixmap(":/icons/reverse.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  ui->parkingSignal->move(screenWidth/2 - driveModeIconWH*2,screenHeight-driveModeIconWH-vBottomOff-5);
  ui->drivingSignal->move(screenWidth/2 - driveModeIconWH*1,screenHeight-driveModeIconWH-vBottomOff-5);
  ui->neutralSignal->move(screenWidth/2 - driveModeIconWH*0,screenHeight-driveModeIconWH-vBottomOff);
  ui->reversingSignal->move(screenWidth/2 - driveModeIconWH*(-1),screenHeight-driveModeIconWH-vBottomOff);

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
