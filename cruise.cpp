#include "cruise.h"
#include "scaler.h"

CruiseControl::CruiseControl() : cruise(OFF) {return;}

void CruiseControl::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int topIconWH = topIconScaler * screenWidth;
  cruise_control = QPixmap(":/icons/cruise.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->cruise_control->move(screenWidth/2+topIconWH*1.5+hOff*2,vOff-3);
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
