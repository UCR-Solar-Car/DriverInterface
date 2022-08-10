#include "indicators.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) { return; }

void Indicators::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");
  left_icon = QPixmap(":/icons/left.png");
  right_icon = QPixmap(":/icons/right.png");
}

void Indicators::left_on() {
  left = ON;
  right = OFF;
  this->ui->left_indicator->setPixmap(left_icon);
  this->ui->right_indicator->setText("OFF");
}

void Indicators::left_off() {
  left = OFF;
  this->ui->left_indicator->setText("OFF");
}

void Indicators::right_on() {
  right = ON;
  left = OFF;
  this->ui->right_indicator->setPixmap(right_icon);
  this->ui->left_indicator->setText("OFF");
}

void Indicators::right_off() {
  right = OFF;
  this->ui->right_indicator->setText("OFF");
}

void Indicators::hazard_on() {
  left = ON;
  right = ON;
  this->ui->left_indicator->setPixmap(left_icon);
  this->ui->right_indicator->setPixmap(right_icon);
}

void Indicators::hazard_off() {
  left = OFF;
  right = OFF;
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");
}

