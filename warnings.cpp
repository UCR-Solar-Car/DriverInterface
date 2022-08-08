#include "warnings.h"

Warnings::Warnings(){ return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  WarningLabel* battery = new WarningLabel(OFF,QPixmap(":/icons/battery.png"),ui->batteryWarning);
  WarningLabel* motor= new WarningLabel(OFF,QPixmap(":/icons/motor.png"),ui->motorWarning);
  WarningLabel* lowBattery = new WarningLabel(OFF, QPixmap(":/icons/low-battery.png"), ui->lowBatteryWarning);

  warning_labels.insert({BATTERY, battery});
  warning_labels.insert({MOTOR, motor});
  warning_labels.insert({LOW_BATTERY, lowBattery});
}

void Warnings::on(warnings warning){
  warning_labels[warning]->state = ON;
  warning_labels[warning]->label->setPixmap(warning_labels[warning]->image);
}

void Warnings::off(warnings warning){
  warning_labels[warning]->state = OFF;
  warning_labels[warning]->label->setText("OFF");
}
