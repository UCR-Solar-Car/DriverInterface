#include "indicators.h"
#include "scaler.h"
#include <QMainWindow>

Indicators::Indicators() : right(OFF), left(OFF) { return; }

void Indicators::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");
  int blinkerIconWH = .13 * screenWidth;
  left_icon = QPixmap(":/icons/left.png")
                  .scaled(blinkerIconWH, blinkerIconWH, Qt::KeepAspectRatio,
                          Qt::SmoothTransformation);
  right_icon = QPixmap(":/icons/right.png")
                   .scaled(blinkerIconWH, blinkerIconWH, Qt::KeepAspectRatio,
                           Qt::SmoothTransformation);
  ui->left_indicator->move(0, screenHeight / 2 - blinkerIconWH / 2);
  ui->right_indicator->move(screenWidth - blinkerIconWH,
                            screenHeight / 2 - blinkerIconWH / 2);
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

states Indicators::get_left_indicator_state() { return left; }

states Indicators::get_right_indicator_state() { return right; }

void Indicators::off() {
  this->ui->left_indicator->setText("OFF");
  this->ui->right_indicator->setText("OFF");
}
