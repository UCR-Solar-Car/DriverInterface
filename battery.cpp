#include "battery.h"

Battery::Battery() : battery(100){ return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery*efficiencyConstant;
  ui->range->display(int(range));
}

void Battery::increase_battery(int val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    this->ui->battery->setValue(battery); ui->battery->update();
    this->range += efficiencyConstant;
    ui->range->display(int(range));
  }
  
}

void Battery::decrease_battery(int val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    this->ui->battery->setValue(battery); ui->battery->update();
    this->range -= efficiencyConstant;
    ui->range->display(int(range));
  }

}

int Battery::get_battery() { return battery; }

int Battery::get_range() { return range; }
