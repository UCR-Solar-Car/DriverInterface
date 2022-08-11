#include "cruise.h"
#include "scaler.h"

CruiseControl::CruiseControl() : cruise(OFF) {return;}

void CruiseControl::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int topIconWH = .07 * screenWidth;
  cruise_control = QPixmap(":/icons/cruise.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->cruise_control->move(4 * screenWidth/6 + hOff,vOff+5);
  this->ui->cruise_control->setText("OFF");

}

void CruiseControl::cruise_on() {
  this->cruise = ON;
  this->ui->cruise_control->setPixmap(cruise_control);
}

void CruiseControl::cruise_off() {
  this->cruise = OFF;
  this->ui->cruise_control->setText("OFF");
}
