#include "weather.h"
#include "ui_weather.h"
#include <QDate>

void Weather::set_weather_info(const WeatherData &weather)
{
    //get system currently mouth
    QString mouth = QDate::currentDate().toString("MM");
    QString date = weather.date;
    ui->label_date->setText(mouth+"月"+date.mid(0,date.indexOf("日")+1));

    ui->label_temp->setText(weather.temp);
    ui->label_info->setText(weather.weatherinfo);

    int pos = date.indexOf("日")+1;
    ui->label_week->setText(date.mid(pos,date.size()-pos));
    ui->label_wind->setText(weather.wind);
    QString msg = QString("border-image: url(:/images/%1.png);").arg(weather.weatherpic);
    ui->label_weather_pic->setStyleSheet(msg);
}

Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Weather::~Weather()
{
    delete ui;
}
