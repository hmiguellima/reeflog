#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QByteArray>
#include <QImage>
#include "model/aquarium.h"
#include "model/logrecord.h"

class EventBus : public QObject
{
    Q_OBJECT
public:
    EventBus();
    ~EventBus();

    static EventBus* getInstance() {
        return instance;
    }

public slots:
    void fireShowMainScreen();
    void fireShowNewRecord(PAquarium aquarium);
    void fireShowAboutScreen();
    void fireEventsUpdated();
    void fireShowAdviceScreen(PAquarium aquarium, PLogRecord record);
    void fireShowEditRecord(PAquarium aquarium, PLogRecord record);
    void fireShowScheduleScreen(PAquarium aquarium, PAdditive additive, PLevel sourceLevel, PLevel destLevel);
    void fireReturnFromSchedule();
    void fireReturnFromAdvice();

private:
    static EventBus *instance;

signals:
    void showMainScreen();
    void showNewRecord(PAquarium aquarium);
    void eventsUpdated();
    void showAboutScreen();
    void showAdviceScreen(PAquarium aquarium, PLogRecord record);
    void showEditRecord(PAquarium aquarium, PLogRecord record);
    void showScheduleScreen(PAquarium aquarium, PAdditive additive, PLevel sourceLevel, PLevel destLevel);
    void returnFromSchedule();
    void returnFromAdvice();
};

#endif // EVENTBUS_H
