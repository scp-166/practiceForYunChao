#include "smartbus.h"
#include "ui_smartbus.h"

smartBus::smartBus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smartBus)
{
    ui->setupUi(this);
}

smartBus::~smartBus()
{
    delete ui;
}
