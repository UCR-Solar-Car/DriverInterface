#include "battery.h"
#include "scaler.h"

Battery::Battery() : battery(20){ return; }

void Battery::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  this->ui->battery->setValue(battery);
  range = battery*efficiency_constant;
  ui->range->display(int(range));
  int rangeSize = screenWidth*.05;

  ui->range_label->resize(rangeSize, rangeSize);
  ui->range_label->move(screenWidth/5, screenHeight*.15);
  ui->range->resize(screenWidth/6,rangeSize*1.2);
  ui->range->move(screenWidth/5, screenHeight*.15);
  ui->battery->resize(screenWidth/4, screenHeight*.05);
  ui->battery->move(screenWidth/5,screenHeight*.25);

  double topIconWH = topIconScaler * screenWidth;
  low_battery = QPixmap(":/icons/low-battery.png").scaled(topIconWH,topIconWH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  this->ui->low_battery_label->setText("OFF");
  ui->low_battery_label->move(screenWidth/2-topIconWH*1.5 - hOff*3,vOff+4);


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
