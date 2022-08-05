#include "warnings.h"

Warnings::Warnings(){ return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  // Battery Warning
  warningPixmap.push_back(QPixmap(":/icons/battery.png"));
  warningLabels.push_back(ui->batteryWarning);

  // Motor Warning
  warningPixmap.push_back(QPixmap(":/icons/motor.png"));
  warningLabels.push_back(ui->motorWarning);

  for(unsigned i = 0; i < warningPixmap.size(); ++i){
      warningState.push_back(OFF);
      warningLabels.at(i)->setText("OFF");
  }
}

void Warnings::on(QLabel* inputLabel){
    int index = 0;
    for(QLabel* checkLabel: warningLabels){
        if(checkLabel == inputLabel){
            break;
        }
        index++;
    }

    warningState.at(index) = ON;
    inputLabel->setPixmap(warningPixmap.at(index));
}

void Warnings::off(QLabel* inputLabel){
    int index = 0;
    for(QLabel* checkLabel: warningLabels){
        if(checkLabel == inputLabel){
            break;
        }
        index++;
    }

    warningState.at(index) = OFF;
    inputLabel->setText("OFF");
}
