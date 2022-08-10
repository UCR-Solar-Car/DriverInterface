#include "indicators.h"
#include "scaler.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) { return; }

void Indicators::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->leftIndicator->setText("OFF");
  this->ui->rightIndicator->setText("OFF");
  leftSignal = QPixmap(":/icons/left.png").scaled(blinkerIconWH,blinkerIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  rightSignal = QPixmap(":/icons/right.png").scaled(blinkerIconWH,blinkerIconWH+1, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->leftIndicator->move(0,screenHeight/2 - blinkerIconWH/2);
  ui->rightIndicator->move(screenWidth - blinkerIconWH,screenHeight/2 - blinkerIconWH/2);
}

void Indicators::left_on() {
  left = ON;
  right = OFF;
  this->ui->leftIndicator->setPixmap(leftSignal);
  this->ui->rightIndicator->setText("OFF");
}

void Indicators::left_off() {
  left = OFF;
  this->ui->leftIndicator->setText("OFF");
}

void Indicators::right_on() {
  right = ON;
  left = OFF;
  this->ui->rightIndicator->setPixmap(rightSignal);
  this->ui->leftIndicator->setText("OFF");
}

void Indicators::right_off() {
  right = OFF;
  this->ui->rightIndicator->setText("OFF");
}

void Indicators::hazard_on() {
  left = ON;
  right = ON;
  this->ui->leftIndicator->setPixmap(leftSignal);
  this->ui->rightIndicator->setPixmap(rightSignal);
}

void Indicators::hazard_off() {
  left = OFF;
  right = OFF;
  this->ui->leftIndicator->setText("OFF");
  this->ui->rightIndicator->setText("OFF");
}

