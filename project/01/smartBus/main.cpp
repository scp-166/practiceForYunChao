#include "smartbus.h"
#include "hdnetwork.h"
#include "hdnetwork2.h"
#include "common.h"
#include "bus.h"
#include "pathshowwin.h"

#include <QApplication>

QString name;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Common cm;

    HDNetwork* HttpNetWeather = new HDNetwork();
    HttpNetWeather->update_bus_weather();
    //wait
    cm.Delay(500);
    QList<WeatherData>listWeather = HttpNetWeather->get_weather();

    // get network data and save in local list
    hdnetwork2* HttpNet = new hdnetwork2();
    HttpNet->update_bus_weather();
    cm.Delay(500);
    //wait
    QList<BusData>listBus = HttpNet->get_bus_number();

    Bus board;  //board
    PathShowWin draw;   //map
    Weather weatherMode;
    smartBus w;
    board.setParent(&draw);
    weatherMode.setParent(&draw);
    weatherMode.move(600,0);
    weatherMode.setStyleSheet("background-color:rgb(115,169,255)");
//    w.setStyleSheet ("venus--TitleBar {background-color: rgb(115,169,255);}");
    w.setStyleSheet("background-color:rgb(115,169,255)");
    draw.setParent(&w);
    w.show();

    int weatherStart = 0;
    int busStart = 0;

    int weatherEnd = listWeather.size();
    int busEnd = listBus.size();

    while(1)
    {
        cm.Delay(1000);

        board.setBusInfo(listBus[busStart]);
        weatherMode.set_weather_info(listWeather[weatherStart]);

        if(!(name.isEmpty()))
            for (int i=0; i<listBus.size(); i++)
            {
                if (!(name.compare(listBus[i].key_name))) //same with route
                {
                    draw.set_bus_station(listBus[i].station_des);
                    draw.update();//flash to work draw event
                    name.clear();
                }
            }

        busStart++;
        weatherStart++;

        if (busStart == busEnd-1)
            busStart=0;
        if (weatherStart == weatherEnd)
            weatherStart=0;
    }
    return a.exec();
}
