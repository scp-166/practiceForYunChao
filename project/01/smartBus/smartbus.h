#ifndef SMARTBUS_H
#define SMARTBUS_H

#include <QWidget>

namespace Ui {
class smartBus;
}

class smartBus : public QWidget
{
    Q_OBJECT

public:
    explicit smartBus(QWidget *parent = 0);
    ~smartBus();

private:
    Ui::smartBus *ui;
};

#endif // SMARTBUS_H
