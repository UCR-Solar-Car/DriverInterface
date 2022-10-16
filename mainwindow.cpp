#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScreen>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->ucr_solar_car_logo->setPixmap(QPixmap(":/icons/logo.png"));
  QScreen *screen = QGuiApplication::primaryScreen();
  uint16_t screen_width = 800;
  uint16_t screen_height = 480;

  ui->stackedWidget->resize(screen_width, screen_height);
  ui->stackedWidget->move(0, 0);

  uint16_t center_width = screen_width / 2 - (0.6*screen_width) / 2;
  uint16_t center_height = screen_height / 2 - (0.3*screen_height) / 2;

  ui->ucr_solar_car_logo->resize(0.6*screen_width, 0.3*screen_height);
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
