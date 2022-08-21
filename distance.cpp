#include "distance.h"
#include "scaler.h"

Distance::Distance() : distance(0) {}

void Distance::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  ui->distance->display(distance);

  ui->distance_label->resize(width * 15 / 100, height * 15 / 100);
  ui->distance->resize(width * 15 / 100, height * 15 / 100);
  ui->distance_label->move(width - width * 90 / 100,
                           height - height * 20 / 100);

  ui->distance->move(width - width * 90 / 100 + ui->distance_label->width(),
                     height - height * 15 / 100);
  ui->distance->resize(width * 15 / 100, height * 5 / 100);

  qDebug() << "DISTANCE" << ui->distance_label->x() << ui->distance_label->y()
           << ui->distance->x() << ui->distance->y();
}

void Distance::decrease_distance(int value) {
  if (distance - value > -1) {
    this->distance -= value;
    ui->distance->display(distance);
  }
}

void Distance::increase_distance(int value) {
  this->distance += value;
  ui->distance->display(distance);
}
