#include "cruise.h"

CruiseControl::CruiseControl() : cruise(OFF) {return;}

void CruiseControl::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  cruiseControlIcon = QPixmap(":/icons/cruise.png");
  this->ui->cruiseControlSignal->setText("OFF");
}

void CruiseControl::cruise_on() {
  this->cruise = ON;
  this->ui->cruiseControlSignal->setPixmap(cruiseControlIcon);
}

void CruiseControl::cruise_off() {
  this->cruise = OFF;
  this->ui->cruiseControlSignal->setText("OFF");
}
