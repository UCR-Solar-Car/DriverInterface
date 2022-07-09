#include "range.h"

Range::Range() : range(100)
{

}

void Range::setup(Ui::MainWindow* ui) {
    this->ui = ui;
    ui->range->display(range);
}

void Range::decrease_range(int value) {
    if(range - value > -1) {
        this->range -= value;
            ui->range->display(range);
    }

}

void Range::increase_range(int value) {
this->range += value;
    ui->range->display(range);
}
