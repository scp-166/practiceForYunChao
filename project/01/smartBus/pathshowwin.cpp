#include "pathshowwin.h"
#include "ui_pathshowwin.h"
#include <QPainter>
#include <QDebug>

//style func: setting data of paint bus station name
void PathShowWin::set_bus_station(const QStringList &stationList)
{
    this->busStations = stationList;
}

void PathShowWin::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //setting background color
    painter.setBrush(QBrush(QColor(115,169,255)));
    painter.drawRect(0,0,this->width(), this->height());

    //setting draw pen to draw route axis
    QPen pen = painter.pen();
    painter.drawLine(30,180,500,180);
    //drawLine(length from left, length of start from top, lengt from start to end ,length of end from top)
    painter.drawLine(30,230,500,230);
    painter.drawArc(475,180,50,50, -90*16, 180*16);

    //save drawing board attribute
    painter.save();
    pen.setColor(Qt::red);
    painter.setPen(pen);

    // drawing: ------>
    painter.drawLine(150,190,400,190);
    painter.drawLine(380,180,400,190);
    painter.drawLine(380,200,400,190);

    // drawing: <------
    painter.drawLine(150,220,400,220);
    painter.drawLine(180,210,150,220);
    painter.drawLine(180,230,150,220);

    // resume attribute
    painter.restore();

    //get station numbers
    int busStationNumber = busStations.count();

    // the station number to draw of frist rows
    int firstStation = 0;

    // the station number to draw of second rows
    int secondStation = 0;

    // if even numbers are evenly divided
    if (busStationNumber % 2 == 0)
    {
        firstStation = busStationNumber/2;
        secondStation = firstStation;
    } else // if not, second rows reduce one
    {
        firstStation = busStationNumber/2+1;
        secondStation = firstStation-1;
    }

    //the coordinate system rotates 90 degrees clockwise and draws second rows.
    painter.rotate(90);
    for (int i=0; i<secondStation; i++)
    {
        painter.drawText(230,-40-(500.0/firstStation) *(secondStation-i-1), busStations.at(i+firstStation));
    }

    //the coordinate system rotates 180 degrees clockwise and draws first rows.
    painter.rotate(180);
    for (int i=0; i<firstStation; i++)
    {
        painter.drawText(-180,(40+(500.0/secondStation)*i), busStations.at(i));
    }

}

PathShowWin::PathShowWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathShowWin)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);


}

PathShowWin::~PathShowWin()
{
    delete ui;
}
