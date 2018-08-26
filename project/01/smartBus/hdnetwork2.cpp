#include "hdnetwork2.h"

hdnetwork2::hdnetwork2(QString name, QObject *parent) : QObject(parent)
{
    this->stationName = name;
    busOfStationManager = new QNetworkAccessManager();
    stationOfBusNumberManager = new QNetworkAccessManager();

    connect(busOfStationManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(read_bus_nember(QNetworkReply*)));
    connect(stationOfBusNumberManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(read_bus_station(QNetworkReply*)));
}


void hdnetwork2::set_bus_station_name(QString name)
{
    this->stationName = name;
}

//get bus by bus station name
const QList<BusData> &hdnetwork2::get_bus_number()const
{
    return buslist;
}

void hdnetwork2::update_bus_weather()
{
    QUrl url;
    QNetworkRequest request;

    url.setUrl("http://192.168.0.16/stations/stationGZYGY");
    request.setUrl(url);
    busOfStationManager->get(request);

}

//get each station the bus has pass
void hdnetwork2::read_bus_nember(QNetworkReply *reply)
{
    QString array = reply->readAll();

    QJsonParseError err;
    QJsonDocument Doc = QJsonDocument::fromJson(array.toUtf8(), &err);
    if (err.error != QJsonParseError::NoError)
        {
            return;
        }
        QJsonObject obj = Doc.object();
        QJsonArray arr = obj.value("result").toArray();

        QStringList blist;
        for(int i=0;i<arr.size();i++)
        {
            QJsonObject aobj = arr.at(i).toObject();
            blist.append(aobj.value("key_name").toString().toUtf8());
        }
   //qDebug()<<blist;

    QUrl url;
    QNetworkRequest request;
//    weatherManager->get(request);
    for (int i=0; i<blist.size(); i++)
    {
        url.setUrl(QString("http://192.168.0.16/buslines/%1")
                   .arg(blist.at(i)));
        request.setUrl(url);
        stationOfBusNumberManager->get(request);

    }//http://op.juhe.cn/189/bus/busline?dtype=json&city=广州&bus=%1&key=818f53f041725a71c33cc2e65837af37
}

void hdnetwork2::read_bus_station(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    QJsonParseError err;
    QJsonDocument Doc =QJsonDocument::fromJson(array,&err);
    if(err.error != QJsonParseError::NoError)
    {
        return;
    }
    QJsonObject obj = Doc.object();
    QJsonArray arr =obj.value("result").toArray();
    obj = arr.at(0).toObject();

    BusData bus;
    bus.terminal_name = obj.value("terminal_name").toString();
    bus.key_name = obj.value("key_name").toString();
    bus.front_name = obj.value("front_name").toString();
    bus.time = obj.value("start_time").toString();
    bus.time.append("--").append(obj.value("end_time").toString());

    arr = obj.value("stationdes").toArray();
    for(int i=0; i<arr.size(); i++)
    {
        obj = arr.at(i).toObject();
        bus.station_des.append(obj.value("name").toString());
    }

    buslist.append(bus);

}
