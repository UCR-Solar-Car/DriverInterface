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
    renderOverheatWarning();
    ui->warnLabelBatteryHeat->setPixmap(warnOverheatBattery_ON);
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


void MainWindow::renderOverheatWarning()
{
    //   warnOverheatBattery_ON
    //  warnOverheatBattery_OFF
    int h = ui->warnLabelBatteryHeat->height();
    int w = ui->warnLabelBatteryHeat->width();
    QColor warningRed = QColor(255,0,0);
    QColor softBlackBG = QColor(27,30,35);
    QColor batteryGreen = QColor(0,169,0);
    QColor softGray = QColor(130, 140, 130, 1);

    //rendering: warnOverheatBattery_ON
    warnOverheatBattery_ON = QPixmap(w, h);
    QPainter paint(&warnOverheatBattery_ON);
    warnOverheatBattery_ON.fill( softBlackBG);
    paint.setBrush(warningRed);
    paint.setPen(warningRed);
    paint.drawRect(0,0,w,1); //TOP RED LINE
    paint.drawRect(0,h-2,w,h); //BOTTOM RED LINE
    QVector<QPoint> rhombusPattern;
    for(int vOffset = 5; vOffset < h; vOffset = vOffset + h - 15){
        for(int hOffset = 0; hOffset < w+10; hOffset = hOffset + 16){
            rhombusPattern.append(QPoint(0 + hOffset, 0 + vOffset)); //top left corner
            rhombusPattern.append(QPoint(-4 + hOffset, 4 + vOffset)); //bottom left corner
            rhombusPattern.append(QPoint(4 + hOffset, 4 + vOffset)); //bottom right corner
            rhombusPattern.append(QPoint(8 + hOffset, 0 + vOffset)); //top right corner
            paint.drawPolygon(QPolygon(rhombusPattern));
            rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back(); rhombusPattern.pop_back();
        }
    }
    paint.drawText(0,0,w,h,Qt::AlignRight | Qt::AlignVCenter,QString("OVERHEAT        "));
    paint.setBrush(softGray);
    paint.setPen(batteryGreen);
    paint.drawRoundedRect(w*.095, h*.38, 30,10,2,2);//Battery Case
    paint.setBrush(batteryGreen);
    paint.drawRect(w*.095-2, h*.38+3, 2,5);// Left end of battery
    paint.drawRect(w*.095+9, h*.38, 1,9);//Battery Line1
    paint.drawRect(w*.095+19, h*.38, 1,9);
    paint.end();

}

