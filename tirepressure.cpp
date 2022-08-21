#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure(){ return; }

void TirePressure::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;

  front_left_pressure = 35;
  front_right_pressure = 35;
  back_left_pressure = 35;
  back_right_pressure = 35;
  pressure_threshold = 30;
  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");
  if(front_left_pressure >= pressure_threshold){
      ui->front_left->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->front_left->setPixmap(low_pressure_icon);
  }
  if(front_right_pressure >= pressure_threshold){
      ui->front_right->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->front_right->setPixmap(low_pressure_icon);
  }
  if(back_left_pressure >= pressure_threshold){
      ui->back_left->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->back_left->setPixmap(low_pressure_icon);
  }
  if(back_right_pressure >= pressure_threshold){
      ui->back_right->setPixmap(normal_pressure_icon);
  }
  else{
     this->ui->back_right->setPixmap(low_pressure_icon);
  }

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
}

void TirePressure::increasePressure(tires tire) {

  if (tire == FRONT_LEFT) {
      front_left_pressure++;
      if(front_left_pressure > pressure_threshold){
        this->ui->front_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure++;
      if(front_right_pressure > pressure_threshold){
        this->ui->front_right->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      back_left_pressure++;
      if(back_left_pressure > pressure_threshold){
        this->ui->back_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      back_right_pressure++;
      if(back_right_pressure > pressure_threshold){
        this->ui->back_right->setPixmap(normal_pressure_icon);
      }
  }
}

void TirePressure::decreasePressure(tires tire) {
  if (tire == FRONT_LEFT) {
      front_left_pressure--;
      if(front_left_pressure <= pressure_threshold){
         this->ui->front_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure--;
      if(front_right_pressure <= pressure_threshold){
         this->ui->front_right->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      back_left_pressure--;
      if(back_left_pressure <= pressure_threshold){
         this->ui->back_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      back_right_pressure--;
      if(back_right_pressure <= pressure_threshold){
         this->ui->back_right->setPixmap(low_pressure_icon);
      }
  }
}
