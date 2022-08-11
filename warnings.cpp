#include "warnings.h"
#include "scaler.h"

Warnings::Warnings(){ return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  int topIconWH = topIconScaler * screenWidth;
  WarningLabel* battery = new WarningLabel(OFF,QPixmap(":/icons/battery.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation),ui->battery_label);
  WarningLabel* motor= new WarningLabel(OFF,QPixmap(":/icons/motor.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation),ui->motor_label);

  ui->battery_label->move(screenWidth/2-topIconWH*3.5-hOff*4,vOff);
  ui->motor_label->move(screenWidth/2-topIconWH*2.5-hOff*3, vOff);

  warning_labels.insert({BATTERY, battery});
  warning_labels.insert({MOTOR, motor});

  off(BATTERY);
  off(MOTOR);
}

void Warnings::on(warnings warning) {
  warning_labels[warning]->state = ON;
  warning_labels[warning]->label->setPixmap(warning_labels[warning]->image);
}

void Warnings::off(warnings warning) {
  warning_labels[warning]->state = OFF;
  warning_labels[warning]->label->setText("OFF");
}
