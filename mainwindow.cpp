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
    ui->rightBlinker->setPixmap(QPixmap("icons8-arrow-50 (3).png"));
    ui->LeftBlinker->setPixmap(QPixmap("icons8-arrow-50_2.png"));
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
    number = 100;
    ui->battery->setValue(100);
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


void MainWindow::on_TurnRightBlinker_clicked()
{
   ui->rightBlinker->setPixmap(QPixmap("icons8-arrow-50_1 (1).png"));

}


void MainWindow::on_TurOffBlinkers_clicked()
{
   ui->rightBlinker->setPixmap(QPixmap("icons8-arrow-50 (3).png"));
}



void MainWindow::on_TurnOffLeftBlinker_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap("icons8-arrow-50_2.png"));
}


void MainWindow::on_LeftBlinker_2_clicked()
{
    ui->LeftBlinker->setPixmap(QPixmap("icons8-arrow-50_1 (3).png"));
}

