#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  indicators.setup(ui);
  battery.setup(ui);
  lights.setup(ui);
  warnings.setup(ui);
  speed.setup(ui);
    distance.setup(ui);

    horn.setup(ui);
    gear.setup(ui);
    cruise.setup(ui);

    this->move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_increaseBattery_clicked() { battery.increase_battery(1); battery.CheckRange(); }

void MainWindow::on_decreaseBattery_clicked() { battery.decrease_battery(1); battery.CheckRange(); }

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

void MainWindow::on_batteryWarningON_clicked() { warnings.on(BATTERY); }

void MainWindow::on_batteryWarningOFF_clicked() { warnings.off(BATTERY); }

void MainWindow::on_motorWarningON_clicked() { warnings.on(MOTOR); }

void MainWindow::on_motorWarningOFF_clicked() { warnings.off(MOTOR); }

void MainWindow::on_increaseMPH_clicked() { speed.increaseSpeed(1); distance.increase_distance(1); }

void MainWindow::on_hornSignalON_clicked() {horn.horn_on();}

void MainWindow::on_hornSignalOFF_clicked() {horn.horn_off();}

void MainWindow::on_decreaseMPH_clicked() { speed.decreaseSpeed(1); distance.decrease_distance(1); }

void MainWindow::on_parkingSignalON_clicked() { gear.switchGears(PARK); }

void MainWindow::on_drivingSignalON_clicked() { gear.switchGears(DRIVE); }

void MainWindow::on_neutralSignalON_clicked() { gear.switchGears(NEUTRAL); }

void MainWindow::on_reversingSignalON_clicked() { gear.switchGears(REVERSE); }

void MainWindow::on_cruiseControlON_clicked() { cruise.cruise_on(); }

void MainWindow::on_cruiseControlOFF_clicked() { cruise.cruise_off(); }
