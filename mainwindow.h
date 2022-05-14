#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>

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

    void on_IncreaseMPH_clicked();

    void on_DecreaseMPH_clicked();

    void on_ResetMPH_clicked();

    void on_TurnRightBlinker_clicked();

    void on_TurOffBlinkers_clicked();

    void on_TurnOffLeftBlinker_clicked();

    void on_LeftBlinker_2_clicked();
    void renderBattery();

    void on_decreaseBattery_clicked();

    void on_resetBattery_clicked();

    void on_increaseBattery_clicked();

private:
    Ui::MainWindow *ui;
private:
    int percentage = 100;
    int mph = 0;
    double decrement = 25.0/33.3;
    double Height2 = 14;
    double Height3 = 52;
    double batteryHeight1 = 25;
    double batteryHeight2 = 25;
    double batteryHeight3 = 25;
    double increaseHeight3 = 0;
    double increaseHeight2 = 0;
    double increaseHeight1 = 0;
    double lower3 = 25;
    double lower2 = 25;
    double lower1 = 25;
    QPixmap fullBattery;
};
#endif // MAINWINDOW_H
