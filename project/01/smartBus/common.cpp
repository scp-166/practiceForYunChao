#include "common.h"

Common::Common()
{

}

void Common::Delay(unsigned int ms)
{
    QTime reachTime = QTime::currentTime().addMSecs(ms);

    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
