#include "tirepressure.h"
#include "scaler.h"

TirePressure::TirePressure() : lowpressure(34) { return; }

void TirePressure::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;

  low_pressure_icon = QPixmap(":/icons/lowpressure.png");
  normal_pressure_icon = QPixmap(":/icons/normalpressure.png");

  ui->back_left->resize(100, 100);
  ui->back_right->resize(100, 100);
  ui->front_left->resize(100, 100);
  ui->front_right->resize(100, 100);

  ui->front_left->move(width * 65 / 100, height * 35 / 100);
  ui->back_left->move(ui->front_left->x(), ui->front_left->y() + height * 20 / 100);
  ui->back_right->move(ui->back_left->x() + width * 20 / 100, ui->back_left->y());
  ui->front_right->move(ui->front_left->x() + width * 20 / 100, ui->front_left->y());



  normal_pressure(FRONT_LEFT);
  normal_pressure(FRONT_RIGHT);
  normal_pressure(BACK_LEFT);
  normal_pressure(BACK_RIGHT);
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
