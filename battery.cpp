#include "battery.h"

Battery::Battery() : battery_val(100) { }

void Battery::setup(QProgressBar* battery_ptr, QLabel* range_label_ptr, QLabel* low_battery_label_ptr, QLabel* battery_label_ptr, QLCDNumber* range_ptr, uint16_t height, uint16_t width) {
  battery = battery_ptr;
  range_label = range_label_ptr;
  low_battery_label = low_battery_label_ptr;
  battery_label = battery_label_ptr;
  range = range_ptr;
  
  battery->setValue(battery_val);
  range_val = battery_val * efficiency_constant;
  range->display(float(range_val));

  battery->resize(width * 10 / 100, height * 30 / 100);
  battery->move(width * 20 / 100, height * 50 / 100 - battery->height() / 2);
  range_label->resize(width * 15 / 100, height * 8 / 100);
  range->resize(width * 15 / 100, height * 15 / 100);
  range_label->move(width - width * 90 / 100, height - height * 20 / 100);
  range->move(width - width * 90 / 100 + range_label->width(), height - height * 15 / 100 - range_label->height());
  range->resize(width * 15 / 100, height * 5 / 100);
  range_label->move(range_label->x(), range_label->y() - range->height());
  low_battery_label->resize(width * 10 / 100, width * 10 / 100);
  low_battery_label->move((width - (width * ICON_COUNT) / 10) / 2 +(low_battery_label->width() * LOW_BATTERY_WARNING_ICON), 0);

  low_battery = QPixmap(":/icons/low-battery.png");
  low_battery_label->setText("OFF");

  battery_label->resize(width * 10 / 100, width * 10 / 100);
  battery_label->move((width - (width * ICON_COUNT) / 10) / 2 +(battery_label->width() * BATTERY_WARNING_ICON), 0);

  battery_fault = QPixmap(":/icons/battery.png");
  battery_label->setText("OFF");
}

void Battery::increase_battery(uint8_t val) {
  if (battery_val < 100 && battery_val > -1) {
    battery_val += val;
    battery->setValue(battery_val);
    battery->update();
    range_val += efficiency_constant;
    range->display(uint8_t(range_val));
    check_range();
  }
}

void Battery::decrease_battery(uint8_t val) {
  if (battery_val < 101 && battery_val > 1) {
    battery_val -= val;
    battery->setValue(battery_val);
    battery->update();
    range_val -= efficiency_constant;
    range->display(uint8_t(range_val));
    check_range();
  }
}

uint8_t Battery::get_battery() { return battery_val; }

uint8_t Battery::get_range() { return range_val; }

void Battery::on(warnings warning) {
  if (warning == LOW_BATTERY)
    low_battery_label->setPixmap(low_battery);
  else if (warning == BATTERY_FAULT)
    battery_label->setPixmap(battery_fault);
}

void Battery::off(warnings warning) {
  if (warning == LOW_BATTERY)
    low_battery_label->setText("OFF");
  if (warning == BATTERY_FAULT)
    battery_label->setText("OFF");
}

void Battery::check_range() {
  if (get_range() <= 30)
    on(LOW_BATTERY);
  else
    off(LOW_BATTERY);
}
