#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure(){}

void TirePressure::setup(QLabel *front_left,QLabel *front_right,QLabel *back_left,QLabel *back_right, uint16_t height, uint16_t width) {
  this->front_left = front_left;
  this->front_right = front_right;
  this->back_left = back_left;
  this->back_right = back_right;

  front_left_pressure = 35;
  front_right_pressure = 35;
  back_left_pressure = 35;
  back_right_pressure = 35;
  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");
  if(front_left_pressure >= pressure_threshold){
      front_left->setPixmap(normal_pressure_icon);
  }
  else{
     front_left->setPixmap(low_pressure_icon);
  }
  if(front_right_pressure >= pressure_threshold){
      front_right->setPixmap(normal_pressure_icon);
  }
  else{
     front_right->setPixmap(low_pressure_icon);
  }
  if(back_left_pressure >= pressure_threshold){
      back_left->setPixmap(normal_pressure_icon);
  }
  else{
     back_left->setPixmap(low_pressure_icon);
  }
  if(back_right_pressure >= pressure_threshold){
      back_right->setPixmap(normal_pressure_icon);
  }
  else{
     back_right->setPixmap(low_pressure_icon);
  }

  back_left->resize(100, 100);
  back_right->resize(100, 100);
  front_left->resize(100, 100);
  front_right->resize(100, 100);

  front_left->move(width * 65 / 100, height * 35 / 100);
  back_left->move(front_left->x(),
                      front_left->y() + height * 20 / 100);
  back_right->move(back_left->x() + width * 20 / 100,
                       back_left->y());
  front_right->move(front_left->x() + width * 20 / 100,
                        front_left->y());
}

void TirePressure::increasePressure(tires tire) {

  if (tire == FRONT_LEFT) {
      front_left_pressure++;
      if(front_left_pressure > pressure_threshold){
        front_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure++;
      if(front_right_pressure > pressure_threshold){
        front_right->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      back_left_pressure++;
      if(back_left_pressure > pressure_threshold){
        back_left->setPixmap(normal_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      back_right_pressure++;
      if(back_right_pressure > pressure_threshold){
        back_right->setPixmap(normal_pressure_icon);
      }
  }
}

void TirePressure::decreasePressure(tires tire) {
  if (tire == FRONT_LEFT) {
      front_left_pressure--;
      if(front_left_pressure <= pressure_threshold){
         front_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure--;
      if(front_right_pressure <= pressure_threshold){
         front_right->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_LEFT) {
      back_left_pressure--;
      if(back_left_pressure <= pressure_threshold){
         back_left->setPixmap(low_pressure_icon);
      }
  } else if (tire == BACK_RIGHT) {
      back_right_pressure--;
      if(back_right_pressure <= pressure_threshold){
         back_right->setPixmap(low_pressure_icon);
      }
  }
}
