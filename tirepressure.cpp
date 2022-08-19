#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure() : lowpressure(34) { return; }

void TirePressure::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  int tireIconWH = .03 * screenWidth;
  int tireIconWH2 = tireIconWH / 2;
  int carIconWH = .1 * screenWidth;
  low_pressure_icon = QPixmap(":/icons/lowpressure.png")
                          .scaled(tireIconWH, tireIconWH, Qt::KeepAspectRatio,
                                  Qt::SmoothTransformation);
  normal_pressure_icon =
      QPixmap(":/icons/normalpressure.png")
          .scaled(tireIconWH, tireIconWH, Qt::KeepAspectRatio,
                  Qt::SmoothTransformation);
  car_icon = QPixmap(":/icons/car.png")
                 .scaled(carIconWH, carIconWH, Qt::KeepAspectRatio,
                         Qt::SmoothTransformation);
  this->ui->car_label->setPixmap(car_icon);
  normal_pressure(FRONT_LEFT);
  normal_pressure(FRONT_RIGHT);
  normal_pressure(BACK_LEFT);
  normal_pressure(BACK_RIGHT);
  ui->front_left->move(screenWidth / 6 - tireIconWH2,
                       screenHeight * .55 - tireIconWH2);
  ui->front_right->move(screenWidth / 6 + carIconWH + tireIconWH2,
                        screenHeight * .55 - tireIconWH2);
  ;
  ui->back_left->move(screenWidth / 6 - tireIconWH2,
                      screenHeight * .55 + carIconWH + tireIconWH2);
  ui->back_right->move(screenWidth / 6 + carIconWH + tireIconWH2,
                       screenHeight * .55 + carIconWH + tireIconWH);
  ui->car_label->move(screenWidth / 6 + tireIconWH * 1.8, screenHeight * .55);
}

void TirePressure::low_pressure(tires tire) {
  if (tire == FRONT_LEFT) {
    this->ui->front_left->setPixmap(low_pressure_icon);
  } else if (tire == FRONT_RIGHT) {
    this->ui->front_right->setPixmap(low_pressure_icon);
  } else if (tire == BACK_LEFT) {
    this->ui->back_left->setPixmap(low_pressure_icon);
  } else if (tire == BACK_RIGHT) {
    this->ui->back_right->setPixmap(low_pressure_icon);
  }
}

void TirePressure::normal_pressure(tires tire) {
  if (tire == FRONT_LEFT) {
    this->ui->front_left->setPixmap(normal_pressure_icon);
  } else if (tire == FRONT_RIGHT) {
    this->ui->front_right->setPixmap(normal_pressure_icon);
  } else if (tire == BACK_LEFT) {
    this->ui->back_left->setPixmap(normal_pressure_icon);
  } else if (tire == BACK_RIGHT) {
    this->ui->back_right->setPixmap(normal_pressure_icon);
  }
}
