#ifndef PATHSHOWWIN_H
#define PATHSHOWWIN_H

#include <QWidget>

namespace Ui {
class PathShowWin;
}

class PathShowWin : public QWidget
{
    Q_OBJECT

public:
    explicit PathShowWin(QWidget *parent = 0);
    ~PathShowWin();
    void paintEvent(QPaintEvent *event);    //draw event
    void set_bus_station(const QStringList &stationList); //setting data of draw station name

private:
    Ui::PathShowWin *ui;
    QStringList busStations;    //save stationlist
};

#endif // PATHSHOWWIN_H
