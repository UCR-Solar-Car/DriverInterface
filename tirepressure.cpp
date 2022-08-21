#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure() : lowpressure(34) { return; }

void TirePressure::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;

  frontLeftPressure = 35;
  frontRightPressure = 35;
  backLeftPressure = 35;
  backRightPressure = 35;
  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");

  
  if(frontLeftPressure >= 31){
      ui->front_left->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->front_left->setPixmap(low_pressure_icon);
  }

  if(frontRightPressure >= 31){
      ui->front_right->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->front_right->setPixmap(low_pressure_icon);
  }

  if(backLeftPressure >= 31){
      ui->back_left->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->back_left->setPixmap(low_pressure_icon);
  }

  if(backRightPressure >= 31){
      ui->back_right->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->back_right->setPixmap(low_pressure_icon);
  }

  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");

  ui->back_left->resize(100, 100);
  ui->back_right->resize(100, 100);
  ui->front_left->resize(100, 100);
  ui->front_right->resize(100, 100);

  ui->front_left->move(width * 65 / 100, height * 35 / 100);
  ui->back_left->move(ui->front_left->x(),
                      ui->front_left->y() + height * 20 / 100);
  ui->back_right->move(ui->back_left->x() + width * 20 / 100,
                       ui->back_left->y());
  ui->front_right->move(ui->front_left->x() + width * 20 / 100,
                        ui->front_left->y());

  normal_pressure(FRONT_LEFT);
  normal_pressure(FRONT_RIGHT);
  normal_pressure(BACK_LEFT);
  normal_pressure(BACK_RIGHT);
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
