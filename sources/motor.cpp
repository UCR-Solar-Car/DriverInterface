#include "../headers/motor.h"

Motor::Motor() {}

void Motor::setup(QLabel *motor_label, uint16_t width, uint16_t height)
{
  motor_fault = QPixmap(":/icons/motor.png");
  this->motor_label = motor_label;
  motor_label->resize(width * 10 / 100, width * 10 / 100);
  motor_label->move((width - (width * ICON_COUNT) / 10) / 2 + (motor_label->width() * MOTOR_WARNING_ICON), height * 0.07);

  off(MOTOR_FAULT);
}

void Motor::on(warnings warning)
{
  if (warning == MOTOR_FAULT)
    motor_label->setPixmap(motor_fault);
}

void Motor::off(warnings warning)
{
  if (warning == MOTOR_FAULT)
    motor_label->setText(" ");
  if (warning == MOTOR_FAULT)
    motor_label->setPixmap(motor_fault);
}
