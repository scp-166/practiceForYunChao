#ifndef BUS_H
#define BUS_H

#include <QWidget>
#include <pathshowwin.h>

//bus display data(will get from network after)
class BusData
{
public:
    QString terminal_name;
    QString front_name;
    QString key_name;
    QString time;
    QStringList station_des;
};

namespace Ui {
class Bus;
}

class Bus : public QWidget
{
    Q_OBJECT

public:
    explicit Bus(QWidget *parent = 0);
    ~Bus();
    void setBusInfo(const BusData &busdata);

private slots:
    void on_label_bus_name_clicked();

private:
    Ui::Bus *ui;

};

#endif // BUS_H
