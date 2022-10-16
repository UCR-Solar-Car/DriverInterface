#include "../headers/tirepressure.h"

TirePressure::TirePressure(){}

void TirePressure::setup(QLabel *front_left,QLabel *front_right,QLabel *back_left,QLabel *back_right,
                         QLCDNumber *front_left_lcd, QLCDNumber *front_right_lcd, QLCDNumber *back_left_lcd,
                         QLCDNumber *back_right_lcd,uint16_t height, uint16_t width) {

  this->front_left = front_left;
  this->front_right = front_right;
  this->back_left = back_left;
  this->back_right = back_right;

  front_left_pressure = 35;
  front_right_pressure = 35;
  back_left_pressure = 35;
  back_right_pressure = 35;
  front_left_lcd->display(front_left_pressure);
  front_right_lcd->display(front_right_pressure);
  back_left_lcd->display(back_left_pressure);
  back_right_lcd->display(back_right_pressure);
  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");

  if(front_left_pressure >= PRESSURE_THRESHOLD)
      front_left->setPixmap(normal_pressure_icon);
  else
     front_left->setPixmap(low_pressure_icon);

  if(front_right_pressure >= PRESSURE_THRESHOLD)
      front_right->setPixmap(normal_pressure_icon);
  else
     front_right->setPixmap(low_pressure_icon);

  if(back_left_pressure >= PRESSURE_THRESHOLD)
      back_left->setPixmap(normal_pressure_icon);
  else
     back_left->setPixmap(low_pressure_icon);

  if(back_right_pressure >= PRESSURE_THRESHOLD)
      back_right->setPixmap(normal_pressure_icon);
  else
     back_right->setPixmap(low_pressure_icon);


  back_left->resize(150, 150);
  back_right->resize(150, 150);
  front_left->resize(150, 150);
  front_right->resize(150, 150);

  front_left->move(width * 55 / 100, height * 53 / 100);
  back_left->move(front_left->x(), front_left->y() + height * 20 / 100);
  back_right->move(back_left->x() + width * 0.25, back_left->y());
  front_right->move(front_left->x() + width * 0.25, front_left->y());

  front_left_lcd->resize(150, 150);
  front_right_lcd->resize(150, 150);
  back_left_lcd->resize(150, 150);
  back_right_lcd->resize(150, 150);

  front_left_lcd->move(width * 50 / 100, height * 52 / 100);
  back_left_lcd->move(front_left_lcd->x(), front_left_lcd->y() + height * 20 / 100);
  back_right_lcd->move(back_left_lcd->x() + width * 25 / 100, back_left_lcd->y());
  front_right_lcd->move(front_left_lcd->x() + width * 25 / 100, front_left_lcd->y());
}

void TirePressure::increasePressure(tires tire) {
  if (tire == FRONT_LEFT) {
      front_left_pressure++;
      front_left_lcd->display(front_left_pressure);
      if(front_left_pressure > PRESSURE_THRESHOLD)
        front_left->setPixmap(normal_pressure_icon);
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure++;
      front_right_lcd->display(front_right_pressure);
      if(front_right_pressure > PRESSURE_THRESHOLD)
        front_right->setPixmap(normal_pressure_icon);
  } else if (tire == BACK_LEFT) {
      back_left_pressure++;
      back_left_lcd->display(back_left_pressure);
      if(back_left_pressure > PRESSURE_THRESHOLD)
        back_left->setPixmap(normal_pressure_icon);
  } else if (tire == BACK_RIGHT) {
      back_right_pressure++;
      back_right_lcd->display(back_right_pressure);
      if(back_right_pressure > PRESSURE_THRESHOLD)
        back_right->setPixmap(normal_pressure_icon);
  }
}

void TirePressure::decreasePressure(tires tire) {
  if (tire == FRONT_LEFT) {
      front_left_pressure--;
      front_left_lcd->display(front_left_pressure);
      if(front_left_pressure <= PRESSURE_THRESHOLD)
         front_left->setPixmap(low_pressure_icon);
  } else if (tire == FRONT_RIGHT) {
      front_right_pressure--;
      front_right_lcd->display(front_right_pressure);
      if(front_right_pressure <= PRESSURE_THRESHOLD)
         front_right->setPixmap(low_pressure_icon);
  } else if (tire == BACK_LEFT) {
      back_left_pressure--;
      back_left_lcd->display(back_left_pressure);
      if(back_left_pressure <= PRESSURE_THRESHOLD)
         back_left->setPixmap(low_pressure_icon);
  } else if (tire == BACK_RIGHT) {
      back_right_pressure--;
      back_right_lcd->display(back_right_pressure);
      if(back_right_pressure <= PRESSURE_THRESHOLD)
         back_right->setPixmap(low_pressure_icon);
  }
}
