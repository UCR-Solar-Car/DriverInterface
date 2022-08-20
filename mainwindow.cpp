#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScreen>
#include <QTimer>
#include <QScreen>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  ui->ucr_solar_car_logo->setPixmap(QPixmap(":/icons/logo.png"));
  QScreen* screen = QGuiApplication::primaryScreen();

  ui->stackedWidget->resize(screen->geometry().width(), screen->geometry().height());
  ui->stackedWidget->move(0,0);

  int center_width= screen->geometry().width()/2 - ui->ucr_solar_car_logo->width()/2;
  int center_height= screen->geometry().height()/2 - ui->ucr_solar_car_logo->height()/2;
  ui->ucr_solar_car_logo->move(center_width, center_height);

  ui->ucr_solar_car_logo->setScaledContents(true);
  ui->stackedWidget->setCurrentIndex(1);

    ui->warnings_icons->move(0,0);

  indicators.setup(ui, screen->geometry().height(), screen->geometry().width());
  battery.setup(ui, screen->geometry().height(), screen->geometry().width());
  lights.setup(ui, screen->geometry().height(), screen->geometry().width());
  motors.setup(ui, screen->geometry().height(), screen->geometry().width());
  speed.setup(ui, screen->geometry().height(), screen->geometry().width());
  distance.setup(ui, screen->geometry().height(), screen->geometry().width());
  timer = new QTimer();
  blink = true;
  connect(timer, SIGNAL(timeout()), this, SLOT(flash()));
  timer->start(500);

  horn.setup(ui, screen->geometry().height(), screen->geometry().width());
  gear.setup(ui, screen->geometry().height(), screen->geometry().width());
  tire.setup(ui, screen->geometry().height(), screen->geometry().width());

  this->move(QGuiApplication::screens().at(0)->geometry().center() -
             frameGeometry().center());

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

void MainWindow::on_increaseMPH_clicked() {
  speed.increase_speed(1);
  distance.increase_distance(1);
}

void MainWindow::on_hornSignalON_clicked() { horn.horn_on(); }

void MainWindow::on_hornSignalOFF_clicked() { horn.horn_off(); }

void MainWindow::on_decreaseMPH_clicked() {
  speed.decrease_speed(1);
  distance.decrease_distance(1);
}

void MainWindow::flash() {
  if (indicators.get_right_indicator_state() == OFF &&
      indicators.get_left_indicator_state() == ON && blink)
    indicators.left_on();

  if (indicators.get_right_indicator_state() == ON &&
      indicators.get_left_indicator_state() == OFF && blink)
    indicators.right_on();

  if (indicators.get_right_indicator_state() == ON &&
      indicators.get_left_indicator_state() == ON && blink)
    indicators.hazard_on();

  if (!blink)
    indicators.off();

  if (seconds == 10)
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

void MainWindow::on_frontLeftON_clicked() { tire.low_pressure(FRONT_LEFT); }

void MainWindow::on_frontLeftOFF_clicked() { tire.normal_pressure(FRONT_LEFT); }

void MainWindow::on_frontRightON_clicked() { tire.low_pressure(FRONT_RIGHT); }

void MainWindow::on_frontRightOFF_clicked() {
  tire.normal_pressure(FRONT_RIGHT);
}

void MainWindow::on_backLeftON_clicked() { tire.low_pressure(BACK_LEFT); }

void MainWindow::on_backLeftOFF_clicked() { tire.normal_pressure(BACK_LEFT); }

void MainWindow::on_backRightON_clicked() { tire.low_pressure(BACK_RIGHT); }

void MainWindow::on_backRightOFF_clicked() { tire.normal_pressure(BACK_RIGHT); }
