#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    indicators.setup(ui);
    battery.setup(ui);
    lights.setup(ui);
    warnings.setup(ui);
    speed.setup(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_increaseBattery_clicked()
{
    battery.increase_battery(1);
}

void MainWindow::on_decreaseBattery_clicked()
{
    battery.decrease_battery(1);
}

void MainWindow::on_leftIndicatorON_clicked()
{
    indicators.left_on();
}

void MainWindow::on_leftIndicatorOFF_clicked()
{
    indicators.left_off();
}

void MainWindow::on_rightIndicatorON_clicked()
{
    indicators.right_on();
}

void MainWindow::on_rightIndicatorOFF_clicked()
{
    indicators.right_off();
}

void MainWindow::on_hazardIndicatorON_clicked()
{
    indicators.hazard_on();
}

void MainWindow::on_hazardIndicatorOFF_clicked()
{
    indicators.hazard_off();
}

void MainWindow::on_dayLightsON_clicked()
{
    lights.day_on();
}

void MainWindow::on_dayLightsOFF_clicked()
{
    lights.day_off();
}

void MainWindow::on_nightLightsON_clicked()
{
    lights.night_on();
}

void MainWindow::on_nightLightsOFF_clicked()
{
    lights.night_off();
}

void MainWindow::on_lightsOFF_clicked()
{
    lights.off();
}

void MainWindow::on_batteryWarningON_clicked(){
    warnings.battery_on();
}

void MainWindow::on_batteryWarningOFF_clicked(){
    warnings.battery_off();
}

void MainWindow::on_motorWarningON_clicked(){
    warnings.motor_on();
}

void MainWindow::on_motorWarningOFF_clicked(){
    warnings.motor_off();
}

void MainWindow::on_increaseMPH_clicked() {
    speed.increaseSpeed(1);
}

void MainWindow::on_decreaseMPH_clicked() {
    speed.decreaseSpeed(1);
}
