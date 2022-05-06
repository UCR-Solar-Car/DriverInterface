#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->battery->setRange(0, 100);
    ui->battery->setValue(100);
    ui->display->setText("100");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_IncreaseButton_clicked()
{
    if(number > 0 && number < 100){
        number++;
        ui->battery->setValue(number);
        ui->display->setText(QString::number(number));
    }
    else if(number <= 0){
        number = 0;
        number++;
        ui->battery->setValue(number);
        ui->display->setText(QString::number(number));
    }
}


void MainWindow::on_DecreaseButton_clicked()
{
    if(number > 0 && number < 100){
        number--;
        ui->battery->setValue(number);
        ui->display->setText(QString::number(number));
    }
    else if(number >= 100){
        number = 100;
        number--;
        ui->battery->setValue(number);
        ui->display->setText(QString::number(number));
    }
}


void MainWindow::on_ResetButton_clicked()
{
    number = 50;
    ui->battery->setValue(50);
    ui->display->setText(QString::number(number));
}


void MainWindow::on_IncreaseMPH_clicked()
{
    if(mph < 100){
        mph++;
        ui->MPH->display(mph);
    }
}


void MainWindow::on_DecreaseMPH_clicked()
{
    if(mph > 0){
        mph--;
        ui->MPH->display(mph);
    }
}


void MainWindow::on_ResetMPH_clicked()
{
    mph = 0;
    ui->MPH->display(mph);
}
