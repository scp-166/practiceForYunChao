#include "bus.h"
#include "ui_bus.h"

#include <QDebug>

extern QString name;

extern QString name;      //声明外部变量
void Bus::setBusInfo(const BusData &busdata)
{
    ui->label_bus_name->setText(busdata.key_name);
    ui->label_start->setText(busdata.front_name);
    ui->label_end->setText(busdata.terminal_name);
    ui->label_time->setText(busdata.time);
    QString info = QString("total have %1 stations").arg(QString::number(busdata.station_des.count()));
    ui->label_info->setText(info);
}

Bus::Bus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bus)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Bus::~Bus()
{
    delete ui;
}

void Bus::on_label_bus_name_clicked()
{
    name = ui->label_bus_name->text();
   //qDebug() << name;
}
