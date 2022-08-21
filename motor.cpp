#include "motor.h"
#include "scaler.h"

Motor::Motor() {}

void Motor::setup(Ui::MainWindow *ui, int height, int width) {
  this->ui = ui;
  int topIconWH = topIconScaler * screenWidth;

  motor_fault = QPixmap(":/icons/motor.png")
                    .scaled(topIconWH, topIconWH, Qt::KeepAspectRatio,
                            Qt::SmoothTransformation);

  ui->motor_label->move(screenWidth / 2 - topIconWH * 2.5 - hOff * 3, vOff);

  off(MOTOR_FAULT);
}

void Motor::on(warnings warning) {
  if (warning == MOTOR_FAULT) 
    ui->motor_label->setPixmap(motor_fault);
}

void Motor::off(warnings warning) {
  if (warning == MOTOR_FAULT) 
    ui->motor_label->setText("OFF");
}
