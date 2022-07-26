#include "gears.h"

Gears::Gears() : gear(OFF) {return;}

void Gears::setup(Ui::MainWindow *ui) {
  this->ui = ui;

  parkSignal = QPixmap(":/icons/parking.png");
  driveSignal = QPixmap(":/icons/drive.png");
  reverseSignal = QPixmap(":/icons/reverse.png");

  // this->ui->parkSignal->setText("OFF");
  // this->ui->driveSignal->setText("OFF");
  // this->ui->reverseSignal->setText("OFF");
}

// void Gears::parking() {
//   this->gear = ON;
//   this->ui->parkSignal->setPixmap(parkSignal);
// }

// void Gears::driving() {
//   this->gear = ON;
//   this->ui->driveSignal->setPixmap(driveSignal);
// }

// void Gears::reversing() {
//   this->gear = ON;
//   this->ui->reverseSignal->setPixmap(reverseSignal);
// }

// void Gears::not_parking() {
//   this->gear = OFF;
//   this->ui->parkSignal->setText("OFF");
// }

// void Gears::not_driving() {
//   this->gear = OFF;
//   this->ui->driveSignal->setText("OFF");
// }

// void Gears::not_reversing() {
//   this->gear = OFF;
//   this->ui->reverseSignal->setText("OFF");
// }
