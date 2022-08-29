#include "distance.h"

Distance::Distance() : distance(0) {}

void Distance::setup(Ui::MainWindow *ui, uint16_t height, uint16_t width) {
  this->ui = ui;
  ui->distance->display(distance_val);

  ui->distance_label->resize(width * 15 / 100, height * 15 / 100);
  ui->distance->resize(width * 15 / 100, height * 15 / 100);
  ui->distance_label->move(width - width * 90 / 100, height - height * 20 / 100);
  ui->distance->move(width - width * 90 / 100 + ui->distance_label->width(), height - height * 15 / 100);
  ui->distance->resize(width * 15 / 100, height * 5 / 100);
}

void Distance::decrease_distance(uint8_t value) {
  if (distance_val - value > -1) {
    distance_val -= value;
    ui->distance->display(distance_val);
  }
}

void Distance::increase_distance(uint8_t value) {
  distance_val += value;
  ui->distance->display(distance_val);
}
