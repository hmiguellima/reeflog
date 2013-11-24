#include "eventbus.h"

EventBus *EventBus::instance=new EventBus();

EventBus::EventBus() : QObject()
{
}

EventBus::~EventBus()
{
}

void EventBus::fireShowMainScreen()
{
    emit showMainScreen();
}

void EventBus::fireShowNewRecord(PAquarium aquarium)
{
    emit showNewRecord(aquarium);
}

void EventBus::fireShowAboutScreen()
{
    emit showAboutScreen();
}

void EventBus::fireEventsUpdated()
{
    emit eventsUpdated();
}

void EventBus::fireShowAdviceScreen(PAquarium aquarium, PLogRecord record)
{
    emit showAdviceScreen(aquarium, record);
}

void EventBus::fireShowEditRecord(PAquarium aquarium, PLogRecord record)
{
    emit showEditRecord(aquarium, record);
}

void EventBus::fireShowScheduleScreen(QSharedPointer<Aquarium> aquarium, QSharedPointer<Additive> additive, QSharedPointer<Level> sourceLevel, QSharedPointer<Level> destLevel)
{
    emit showScheduleScreen(aquarium, additive, sourceLevel, destLevel);
}

void EventBus::fireReturnFromSchedule()
{
    emit returnFromSchedule();
}

void EventBus::fireReturnFromAdvice()
{
    emit returnFromAdvice();
}
