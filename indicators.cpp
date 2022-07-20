#include "indicators.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) { return; }

void Indicators::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->leftIndicator->setText("OFF");
  this->ui->rightIndicator->setText("OFF");
}

void Indicators::left_on() {
  left = ON;
  right = OFF;
  this->ui->leftIndicator->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\left.png"));
  this->ui->rightIndicator->setText("OFF");
}

void Indicators::left_off() {
  left = OFF;
  this->ui->leftIndicator->setText("OFF");
}

void Indicators::right_on() {
  right = ON;
  left = OFF;
  this->ui->rightIndicator->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\right.png"));
  this->ui->leftIndicator->setText("OFF");
}

void Indicators::right_off() {
  right = OFF;
  this->ui->rightIndicator->setText("OFF");
}

void Indicators::hazard_on() {
  left = ON;
  right = ON;
  this->ui->leftIndicator->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\left.png"));
  this->ui->rightIndicator->setPixmap(
      QPixmap("C:\\Users\\kavin\\OneDrive\\Desktop\\School\\Solar Car\\Driver-Interface-2022\\right.png"));
}

void Indicators::hazard_off() {
  left = OFF;
  right = OFF;
  this->ui->leftIndicator->setText("OFF");
  this->ui->rightIndicator->setText("OFF");
}

