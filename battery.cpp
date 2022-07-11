#include "battery.h"

Battery::Battery() : battery(100), range(battery) { return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(100);
}

void Battery::increase_battery(int val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    range += val;
    this->ui->battery->setValue(battery);
  }
}

void Battery::decrease_battery(int val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    range -= val;
    this->ui->battery->setValue(battery);
  }
}

int Battery::get_battery() { return battery; }

int Battery::get_range() { return range; }
