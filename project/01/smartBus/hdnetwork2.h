#ifndef HDNETWORK2_H
#define HDNETWORK2_H

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
#include "bus.h"

class hdnetwork2 : public QObject
{
    Q_OBJECT
public:
    explicit hdnetwork2(QString name = "UC-S", QObject *parent = 0);
    void set_bus_station_name(QString name);
    const QList<BusData> &get_bus_number()const;

signals:

public slots:
    void update_bus_weather();
    void read_bus_nember(QNetworkReply *reply);
    void read_bus_station(QNetworkReply *reply);

private:
    QString stationName;
    QStringList busNumberlist;
    QList<BusData> buslist;

    QNetworkAccessManager *busOfStationManager;
    QNetworkAccessManager *stationOfBusNumberManager;

};

#endif // HDNETWORK2_H
