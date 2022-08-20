#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure() : lowpressure(34) { return; }

void TirePressure::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  int tireIconWH = .03 * screenWidth;
  int tireIconWH2 = tireIconWH / 2;
  int carIconWH = .1 * screenWidth;
  frontLeftPressure = 35;
  frontRightPressure = 35;
  backLeftPressure = 35;
  backRightPressure = 35;
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
  ui->front_left->setPixmap(normal_pressure_icon);
  ui->front_right->setPixmap(normal_pressure_icon);
  ui->back_left->setPixmap(normal_pressure_icon);
  ui->back_right->setPixmap(normal_pressure_icon);
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

void TirePressure::increasePressure(tires tire) {

  if (tire == FRONT_LEFT) {
      frontLeftPressure++;
      if(frontLeftPressure >= 31){
        this->ui->front_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      frontRightPressure++;
      if(frontRightPressure >= 31){
        this->ui->front_right->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      backLeftPressure++;
      if(backLeftPressure >= 31){
        this->ui->back_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      backRightPressure++;
      if(backRightPressure >= 31){
        this->ui->back_right->setPixmap(normal_pressure_icon);
      }
  }
}

void TirePressure::decreasePressure(tires tire) {
  if (tire == FRONT_LEFT) {
      frontLeftPressure--;
      if(frontLeftPressure <= 30){
         this->ui->front_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      frontRightPressure--;
      if(frontRightPressure <= 30){
         this->ui->front_right->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      backLeftPressure--;
      if(backLeftPressure <= 30){
         this->ui->back_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      backRightPressure--;
      if(backRightPressure <= 30){
         this->ui->back_right->setPixmap(low_pressure_icon);
      }
  }
}
