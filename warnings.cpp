#include "warnings.h"

Warnings::Warnings() : battery(OFF), motor(OFF) { return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->batteryWarning->setText("OFF");
  this->ui->motorWarning->setText("OFF");
}

void Warnings::battery_on() {
  this->battery = ON;
  this->ui->batteryWarning->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\battery.png"));
}

void Warnings::battery_off() {
  this->battery = OFF;
  this->ui->batteryWarning->setText("OFF");
}

void Warnings::motor_on() {
  this->motor = ON;
  this->ui->motorWarning->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\motor.png"));
}

void Warnings::motor_off() {
  this->motor = OFF;
  this->ui->motorWarning->setText("OFF");
}

