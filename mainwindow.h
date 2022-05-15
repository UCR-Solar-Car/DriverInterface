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
};
#endif // MAINWINDOW_H
