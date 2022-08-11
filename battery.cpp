#include "battery.h"
#include "scaler.h"

Battery::Battery() : battery(100){ return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery*efficiencyConstant;
  ui->range->display(int(range));
  int rangeSize = screenWidth*.05;

  ui->rangeLabel->resize(rangeSize, rangeSize);
  ui->rangeLabel->move(screenWidth/5, screenHeight/4);
  ui->range->resize(screenWidth/6,rangeSize*1.2);
  ui->range->move(screenWidth/5, screenHeight/4);
  ui->battery->resize(screenWidth/4, screenHeight*.05);
  ui->battery->move(screenWidth/5,screenHeight*.35);
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
