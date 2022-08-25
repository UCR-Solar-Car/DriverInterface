#include "indicators.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) {}


void Indicators::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");

  ui->left_indicator->resize(100, 100);
  ui->right_indicator->resize(100, 100);

  ui->left_indicator->move(0, height / 2 - ui->left_indicator->height() / 2);
  ui->right_indicator->move(width - ui->right_indicator->width(), height / 2 - ui->right_indicator->height() / 2);

  left_icon = QPixmap(":/icons/left.png");
  right_icon = QPixmap(":/icons/right.png");
}

void Indicators::left_on() {
  left = ON;
  this->ui->left_indicator->setPixmap(left_icon);
  right_off();
}

void Indicators::left_off() {
  left = OFF;
  this->ui->left_indicator->setText("OFF");
}

void Indicators::right_on() {
  right = ON;
  this->ui->right_indicator->setPixmap(right_icon);
  left_off();
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
  right_off();
  left_off();
}

states Indicators::get_left_indicator_state() { return left; }

states Indicators::get_right_indicator_state() { return right; }

void Indicators::off() {
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");
}
