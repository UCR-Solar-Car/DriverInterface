#include "../headers/distance.h"

Distance::Distance() : distance(0) {}

void Distance::setup(QLabel *distance_label_ptr, QLCDNumber *distance_ptr, uint16_t height, uint16_t width)
{
  distance_label = distance_label_ptr;
  distance = distance_ptr;

  distance->display(distance_val);

  distance_label->resize(width * 25 / 100, height * 15 / 100);
  distance_label->move(width * 0.02, height - height * 20 / 100);
  distance->move(width * 0.25, height - height * 15 / 100);
  distance->resize(width * 15 / 100
                   , height * 5 / 100);
}

void Distance::decrease_distance(uint8_t value)
{
  if (distance_val - value > -1)
  {
    distance_val -= value;
    distance->display(distance_val);
  }
}

void Distance::increase_distance(uint8_t value)
{
  distance_val += value;
  distance->display(distance_val);
}
