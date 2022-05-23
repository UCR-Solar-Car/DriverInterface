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

    void on_decreaseBattery_clicked();

    void on_resetBattery_clicked();

    void on_increaseBattery_clicked();

    void on_IncreaseButton_clicked();

    void on_DecreaseButton_clicked();

    void on_ResetButton_clicked();

    void on_IncreaseMPH_clicked();

    void on_DecreaseMPH_clicked();

    void on_ResetMPH_clicked();

    void on_TurnRightBlinker_clicked();

    void on_TurOffBlinkers_clicked();

    void on_TurnOffLeftBlinker_clicked();

    void on_LeftBlinker_2_clicked();


private:
    Ui::MainWindow *ui;
private:
    int percentage = 100;
    int height1 = 33;
    int verticalShift1 = 0;
    int height2 = 33;
    int verticalShift2 = 0;
    int height3 = 33;
    int verticalShift3 = 0;
    int number = 100;
    int mph = 0;
    long unsigned delay = 500;

};
#endif // MAINWINDOW_H
