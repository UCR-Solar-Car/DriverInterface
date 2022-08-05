#include "warnings.h"

Warnings::Warnings(){ return; }

void Warnings::setup(Ui::MainWindow *ui) {
  this->ui = ui;
  // Battery Warning
  warningLabels.push_back(WarningLabel(OFF,
                          QPixmap(":/icons/battery.png"),
                          ui->batteryWarning));
  // Motor Warning
  warningLabels.push_back(WarningLabel(OFF,
                          QPixmap(":/icons/motor.png"),
                          ui->motorWarning));


  for(unsigned i = 0; i < warningLabels.size(); ++i){
      warningLabels.at(i).label->setText("OFF");
  }
}

void Warnings::on(QLabel* inputLabel){
    int index = 0;
    for(WarningLabel checkLabel: warningLabels){
        if(checkLabel.label == inputLabel){
            break;
        }
        index++;
    }

    warningLabels.at(index).state = ON;
    inputLabel->setPixmap(warningLabels.at(index).image);
}

void Warnings::off(QLabel* inputLabel){
    int index = 0;
    for(WarningLabel checkLabel: warningLabels){
        if(checkLabel.label == inputLabel){
            break;
        }
        index++;
    }

    warningLabels.at(index).state = OFF;
    inputLabel->setText("OFF");
}
