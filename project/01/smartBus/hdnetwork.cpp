#include "hdnetwork.h"

HDNetwork::HDNetwork(QObject *parent) : QObject(parent)
{
    weatherManager = new QNetworkAccessManager();

    //slot
    connect(weatherManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(read_weather(QNetworkReply*)));

}

//return weather data
const QList<WeatherData> HDNetwork::get_weather()const
{
    return weatherlist;
}

//update weather and bus info
void HDNetwork::update_bus_weather()
{
    QUrl url;
    QNetworkRequest request;

    //get weather
    url.setUrl("http://wthrcdn.etouch.cn/weather_mini?citykey=101280101");
    request.setUrl(url);
    weatherManager->get(request);
}

// download pro weather info
void HDNetwork::read_weather(QNetworkReply *reply)
{
    QString array = reply->readAll();
    QJsonParseError err;
    QJsonDocument Doc = QJsonDocument::fromJson(array.toUtf8(), &err);
    if (err.error != QJsonParseError::NoError)
    {
        qDebug() << "error";
        return;
    }
    QJsonObject obj = Doc.object();
    obj = obj.value("data").toObject();
    QJsonArray arr = obj.value("forecast").toArray();

    for (int i=0; i<arr.size(); i++)
    {
        obj = arr.at(i).toObject();
        WeatherData wdata;
        wdata.date = obj.value("date").toString();
        wdata.temp = obj.value("low").toString();
        wdata.temp.append("~").append(obj.value("high").toString());
        wdata.weatherinfo = obj.value("type").toString();
        wdata.weatherpic = obj.value("type").toString();
        wdata.week = obj.value("date").toString();
        wdata.wind = obj.value("fengxiang").toString();
        weatherlist.append(wdata);
    }

}
