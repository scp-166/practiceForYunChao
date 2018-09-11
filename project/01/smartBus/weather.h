#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>

namespace Ui {
class Weather;
}

//weather data class(save data from network)
class WeatherData
{
public:
    QString week;
    QString temp;
    QString wind;
    QString weatherinfo;
    QString weatherpic;
    QString date;
};


class Weather : public QWidget
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = 0);
    ~Weather();
    void set_weather_info(const WeatherData &weather);

private:
    Ui::Weather *ui;
};



#endif // WEATHER_H
