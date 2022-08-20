#include "motor.h"
#include "scaler.h"

Motor::Motor() { return; }

void Motor::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  motor_fault = QPixmap(":/icons/motor.png");


  ui->motor_label->resize(width * 10 / 100, width * 10 / 100);
  ui->motor_label->move((width - (width * ICON_COUNT) / 10) / 2 + (ui->motor_label->width() * MOTOR_WARNING_ICON), 0);

  qDebug() << width << ui->motor_label->width() << ui->motor_label->x() << ui->motor_label->y();


  off(MOTOR_FAULT);
}

void Motor::on(warnings warning) {
  if (warning == MOTOR_FAULT) {
    ui->motor_label->setPixmap(motor_fault);
  }
}

void Motor::off(warnings warning) {
  if (warning == MOTOR_FAULT) {
    ui->motor_label->setText("OFF");
  }
}
