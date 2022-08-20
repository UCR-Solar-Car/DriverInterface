#include "gears.h"
#include "scaler.h"

Gears::Gears() : gear(PARK) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int driveModeIconWH = .09 * screenHeight;
  
  park = QPixmap(":/icons/parking.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  drive = QPixmap(":/icons/drive.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  neutral = QPixmap(":/icons/neutral.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  reverse = QPixmap(":/icons/reverse.png").scaled(driveModeIconWH,driveModeIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  this->ui->park_label->move(screenWidth/2 - driveModeIconWH*2,screenHeight-driveModeIconWH-vBottomOff-5);
  this->ui->drive_label->move(screenWidth/2 - driveModeIconWH*1,screenHeight-driveModeIconWH-vBottomOff-5);
  this->ui->neutral_label->move(screenWidth/2 - driveModeIconWH*0,screenHeight-driveModeIconWH-vBottomOff);
  this->ui->reverse_label->move(screenWidth/2 - driveModeIconWH*(-1),screenHeight-driveModeIconWH-vBottomOff);

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
