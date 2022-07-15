#include "battery.h"

Battery::Battery() : battery(100), range(100) { return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  ui->range->display(range);
}

void Battery::increase_battery(int val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    this->ui->battery->setValue(battery);
    this->range += val;
  ui->range->display(range);
  }
  
}

void Battery::decrease_battery(int val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    this->ui->battery->setValue(battery);

    if (range - val > -1) {
    this->range -= val;
    ui->range->display(range);
  }
  }

  
}

int Battery::get_battery() { return battery; }

int Battery::get_range() { return range; }
