#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScreen>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->ucr_solar_car_logo->setPixmap(QPixmap(":/icons/logo(1).png"));
  QScreen *screen = QGuiApplication::primaryScreen();
  uint16_t screen_width = screen->geometry().width();
  uint16_t screen_height = screen->geometry().height();

  ui->stackedWidget->resize(screen_width, screen_height);
  ui->stackedWidget->move(0, 0);

//  uint16_t center_width = screen_width / 2 - ui->ucr_solar_car_logo->width() / 2;
//  uint16_t center_height = screen_height / 2 - ui->ucr_solar_car_logo->height() / 2;

    uint16_t center_width = screen_width / 2 - (0.4*screen_width) / 2;
    uint16_t center_height = screen_height / 2 - (0.4*screen_height) / 2;

  ui->ucr_solar_car_logo->resize(0.4*screen_width, 0.4*screen_height);
  ui->ucr_solar_car_logo->move(center_width, center_height);


  ui->ucr_solar_car_logo->setScaledContents(true);
  ui->stackedWidget->setCurrentIndex(1);

  indicators.setup(ui->left_indicator, ui->right_indicator, screen_height, screen_width);
  lights.setup(ui->day_lights, ui->night_lights, screen_width, screen_height);
  motors.setup(ui->motor_label, screen_width, screen_height);
  speed.setup(ui->speed, ui->mph, screen_height, screen_width);
  distance.setup(ui->distance_label, ui->distance, screen_height, screen_width);
  battery.setup(ui->battery, ui->range_label, ui->low_battery_label, ui->battery_label, ui->range, ui->distance_label, ui->battery_line_1, ui->battery_line_2, ui->battery_line_3, ui->battery_line_4, screen_height, screen_width);

  timer = new QTimer();
  blink = true;
  connect(timer, SIGNAL(timeout()), this, SLOT(gather_info()));
  timer->start(500);

  horn.setup(ui->horn_label, screen_width, screen_height);
  gear.setup(ui->park_label, ui->cruise_control, screen_height, screen_width);
  tire.setup(ui->front_left, ui->front_right, ui->back_left, ui->back_right,
             ui->front_left_lcd, ui->front_right_lcd, ui->back_left_lcd, ui->back_right_lcd, screen_height, screen_width);

  move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

  seconds = 0;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_increaseBattery_clicked() { battery.increase_battery(1); }

void MainWindow::on_decreaseBattery_clicked() { battery.decrease_battery(1); }

void MainWindow::on_leftIndicatorON_clicked() { indicators.left_on(); }

void MainWindow::on_leftIndicatorOFF_clicked() { indicators.left_off(); }

void MainWindow::on_rightIndicatorON_clicked() { indicators.right_on(); }

void MainWindow::on_rightIndicatorOFF_clicked() { indicators.right_off(); }

void MainWindow::on_hazardIndicatorON_clicked() { indicators.hazard_on(); }

void MainWindow::on_hazardIndicatorOFF_clicked() { indicators.hazard_off(); }

void MainWindow::on_dayLightsON_clicked() { lights.day_on(); }

void MainWindow::on_dayLightsOFF_clicked() { lights.day_off(); }

void MainWindow::on_nightLightsON_clicked() { lights.night_on(); }

void MainWindow::on_nightLightsOFF_clicked() { lights.night_off(); }

void MainWindow::on_lightsOFF_clicked() { lights.off(); }

void MainWindow::on_batteryWarningON_clicked() { battery.on(BATTERY_FAULT); }

void MainWindow::on_batteryWarningOFF_clicked() { battery.off(BATTERY_FAULT); }

void MainWindow::on_motorWarningON_clicked() { motors.on(MOTOR_FAULT); }

void MainWindow::on_motorWarningOFF_clicked() { motors.off(MOTOR_FAULT); }

void MainWindow::on_increaseMPH_clicked()
{
  speed.increase_speed(1);
  distance.increase_distance(1);
}

void MainWindow::on_decreaseMPH_clicked()
{
  speed.decrease_speed(1);
  distance.decrease_distance(1);
}

void MainWindow::on_hornSignalON_clicked() { horn.horn_on(); }

void MainWindow::on_hornSignalOFF_clicked() { horn.horn_off(); }

void MainWindow::gather_info() {

  if (indicators.get_right_indicator_state() == OFF && indicators.get_left_indicator_state() == ON && blink)
    indicators.left_on();

  if (indicators.get_right_indicator_state() == ON && indicators.get_left_indicator_state() == OFF && blink)
    indicators.right_on();

  if (indicators.get_right_indicator_state() == ON && indicators.get_left_indicator_state() == ON && blink)
    indicators.hazard_on();

  if (!blink)
    indicators.off();

  if (seconds == 2)
    ui->stackedWidget->setCurrentIndex(0);

  blink = !blink;
  seconds += 1;
}

void MainWindow::on_parkingSignalON_clicked() { gear.switch_gears(PARK); }

void MainWindow::on_drivingSignalON_clicked() { gear.switch_gears(DRIVE); }

void MainWindow::on_neutralSignalON_clicked() { gear.switch_gears(NEUTRAL); }

void MainWindow::on_reversingSignalON_clicked() { gear.switch_gears(REVERSE); }

void MainWindow::on_cruiseControlON_clicked() { gear.cruise_on(); }

void MainWindow::on_cruiseControlOFF_clicked() { gear.cruise_off(); }

void MainWindow::on_frontLeftON_clicked() { tire.increasePressure(FRONT_LEFT); }

void MainWindow::on_frontLeftOFF_clicked() { tire.decreasePressure(FRONT_LEFT); }

void MainWindow::on_frontRightON_clicked() { tire.increasePressure(FRONT_RIGHT); }

void MainWindow::on_frontRightOFF_clicked() { tire.decreasePressure(FRONT_RIGHT); }

void MainWindow::on_backLeftON_clicked() { tire.increasePressure(BACK_LEFT); }

void MainWindow::on_backLeftOFF_clicked() { tire.decreasePressure(BACK_LEFT); }

void MainWindow::on_backRightON_clicked() { tire.increasePressure(BACK_RIGHT); }

void MainWindow::on_backRightOFF_clicked() { tire.decreasePressure(BACK_RIGHT); }
