#include "battery.h"
#include "scaler.h"

Battery::Battery() : battery(100){ return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery*efficiency_constant;
  ui->range->display(int(range));
  int rangeSize = screenWidth*.05;

  ui->rangeLabel->resize(rangeSize, rangeSize);
  ui->rangeLabel->move(screenWidth/5, screenHeight/4);
  ui->range->resize(screenWidth/6,rangeSize*1.2);
  ui->range->move(screenWidth/5, screenHeight/4);
  ui->battery->resize(screenWidth/4, screenHeight*.05);
  ui->battery->move(screenWidth/5,screenHeight*.35);


  low_battery = QPixmap(":/icons/low-battery.png");
  this->ui->low_battery_label->setText("OFF");
}

void Battery::increase_battery(int val) {
  if (battery < 100 && battery > -1) {
    battery += val;
    this->ui->battery->setValue(battery); ui->battery->update();
    this->range += efficiency_constant;
    ui->range->display(int(range));

    check_range(LOW_BATTERY);
  }
  
}

void Battery::decrease_battery(int val) {
  if (battery < 101 && battery > 1) {
    battery -= val;
    this->ui->battery->setValue(battery); ui->battery->update();
    this->range -= efficiency_constant;
    ui->range->display(int(range));

    check_range(LOW_BATTERY);
  }

}

int Battery::get_battery() { return battery; }

int Battery::get_range() { return range; }

void Battery::on(warnings warning) {
  if (warning == LOW_BATTERY) {
    this->ui->low_battery_label->setPixmap(low_battery);
  }
}

void Battery::off(warnings warning) {
  if (warning == LOW_BATTERY) {
    this->ui->low_battery_label->setText("OFF");
  }
}

void Battery::check_range(warnings warning) {
  if (get_range() <= 30) {
    on(warning);
  }
  else {
    off(warning);
  }
}
