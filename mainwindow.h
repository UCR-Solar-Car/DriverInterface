#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "battery.h"
#include "indicators.h"
#include "lights.h"
#include "warnings.h"
#include "speed.h"
#include "distance.h"
#include "horn.h"
#include "gears.h"
#include "cruise.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_increaseBattery_clicked();

    void on_decreaseBattery_clicked();

    void on_leftIndicatorON_clicked();

    void on_leftIndicatorOFF_clicked();

    void on_rightIndicatorON_clicked();

    void on_rightIndicatorOFF_clicked();

    void on_hazardIndicatorON_clicked();

    void on_hazardIndicatorOFF_clicked();

    void on_dayLightsON_clicked();

    void on_dayLightsOFF_clicked();

    void on_nightLightsON_clicked();

    void on_nightLightsOFF_clicked();

    void on_lightsOFF_clicked();

    void on_batteryWarningON_clicked();

    void on_batteryWarningOFF_clicked();

    void on_motorWarningON_clicked();

    void on_motorWarningOFF_clicked();

    void on_increaseMPH_clicked();

    void on_decreaseMPH_clicked();

    void on_hornSignalON_clicked();

    void on_hornSignalOFF_clicked();

    void on_parkingSignalON_clicked();

    void on_drivingSignalON_clicked();

    void on_neutralSignalON_clicked();

    void on_reversingSignalON_clicked();

    void on_cruiseControlON_clicked();

    void on_cruiseControlOFF_clicked();
private:
    Ui::MainWindow *ui;
    Battery battery;
    Indicators indicators;
    Lights lights;
    Warnings warnings;
    Speed speed;
    Distance distance;
    Horn horn;
    Gears gear;
    CruiseControl cruise;

};
#endif // MAINWINDOW_H
