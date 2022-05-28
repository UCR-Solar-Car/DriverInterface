#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dayLight->setPixmap(QPixmap("blank"));
    ui->nightLight->setPixmap(QPixmap("blank"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dayLightButton_clicked()
{
    ui->dayLight->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-light-bulb-48.png"));
    ui->nightLight->setPixmap(QPixmap("blank"));
}


void MainWindow::on_offButton_clicked()
{
    ui->dayLight->setPixmap(QPixmap("blank"));
    ui->nightLight->setPixmap(QPixmap("blank"));
}




void MainWindow::on_pushButton_clicked()
{
    ui->nightLight->setPixmap(QPixmap("C:/Users/justiny/Downloads/icons8-idea-48.png"));
    ui->dayLight->setPixmap(QPixmap("blank"));
}

