#include "distance.h"

Distance::Distance() : distance(0) {}

void Distance::setup(Ui::MainWindow* ui) {
    this->ui = ui;
    ui->distance->display(distance);
}

void Distance::decrease_distance(int value) {
    if(distance - value > -1){
        this->distance -= value;
            ui->distance->display(distance);
    }

}

void Distance::increase_distance(int value) {
this->distance += value;
    ui->distance->display(distance);
}
