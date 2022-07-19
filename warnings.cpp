#include "warnings.h"

Warnings::Warnings() : battery(OFF), motor(OFF) { return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  batteryLabel = QPixmap(":/icons/battery.png");
  motorLabel = QPixmap(":/icons/motor.png");
  this->ui->batteryWarning->setText("OFF");
  this->ui->motorWarning->setText("OFF");
}

void Warnings::battery_on() {
  this->battery = ON;
  this->ui->batteryWarning->setPixmap(batteryLabel);
}

void Warnings::battery_off() {
  this->battery = OFF;
  this->ui->batteryWarning->setText("OFF");
}

void Warnings::motor_on() {
  this->motor = ON;
  this->ui->motorWarning->setPixmap(motorLabel);
}

void Warnings::motor_off() {
  this->motor = OFF;
  this->ui->motorWarning->setText("OFF");
}
