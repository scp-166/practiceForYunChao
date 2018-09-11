#ifndef HDNETWORK_H
#define HDNETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include "weather.h"

class HDNetwork : public QObject
{
    Q_OBJECT
public:
    explicit HDNetwork(QObject *parent = 0);
    const QList<WeatherData> get_weather()const; //get weather

signals:
public slots:
    void update_bus_weather();
    void read_weather(QNetworkReply *reply);

private:
    QList<WeatherData> weatherlist;
    QNetworkAccessManager *weatherManager;

};

#endif // HDNETWORK_H
