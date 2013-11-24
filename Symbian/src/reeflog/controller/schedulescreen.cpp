#include "schedulescreen.h"
#include <QScrollArea>
#include "eventbus.h"
#include <QApplication>
#include <QDesktopWidget>
#include "model/calciumlevel.h"
#include "model/alkalinitylevel.h"
#include "model/magnesiumlevel.h"
#include "model/calwrapper.h"
#include <QDateTime>

ScheduleScreen::ScheduleScreen(MainWindow* window) :
    Screen(window), view(0)
{
    QVBoxLayout* containerLayout=new QVBoxLayout(this);
    QScrollArea* scrollArea=new QScrollArea();

    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setFrameShape(QFrame::NoFrame);
    containerLayout->addWidget(scrollArea);
    containerLayout->setMargin(0);
    containerLayout->setSpacing(0);
    vLayout=new QVBoxLayout(scrollArea);
    vLayout->setMargin(0);
    vLayout->setSpacing(0);

    connect(EventBus::getInstance(), SIGNAL(showScheduleScreen(PAquarium,PAdditive,PLevel,PLevel)), this, SLOT(showScheduleScreen(PAquarium,PAdditive,PLevel,PLevel)));
}

void ScheduleScreen::showHandler()
{
    if (view!=0)
        view->deleteLater();
    view=0;
    update();
}

void ScheduleScreen::update()
{
    ScheduleView* oldView=0;

    if (!isCurrent())
        return;

    if (view!=0)
    {
        oldView=view;
        view->deleteLater();
    }


    view=new ScheduleVerticalView();

    view->setProductName(_additive->getName());
    view->setDosageAmount(_dosage->toString());
    view->setDosageAdvice(_additive->getInstructions());
    view->setInterval(2);
    view->setDailyDosageAmount(_dosage->getDailyDosageAmount(2));
    view->setStartDate(QDate::currentDate());

    connect(view, SIGNAL(scheduleBtnClicked()), this, SLOT(handleScheduleBtnClicked()));
    connect(view, SIGNAL(backBtnClicked()), this, SLOT(handleBackBtnClicked()));
    connect(view, SIGNAL(intervalChanged(int)), this, SLOT(handleIntervalChanged(int)));

    vLayout->addWidget(view);
    view->askFocus();
}

void ScheduleScreen::showScheduleScreen(PAquarium aquarium, QSharedPointer<Additive> additive, QSharedPointer<Level> sourceLevel, QSharedPointer<Level> destLevel)
{
    _aquarium=aquarium;
    _dosage=additive->calcDosage(*aquarium->getWaterVolume().data(), sourceLevel, destLevel);
    _additive=additive;
    show();
}

void ScheduleScreen::handleScheduleBtnClicked()
{
    int days;
    QDate startDate;
    QDateTime startDateTime;
    QString msg;
    bool alarmsSet=false;

    days=view->getInterval();
    startDate=view->getStartDate();
    startDateTime=QDateTime::currentDateTime();
    startDateTime.setDate(startDate);

    msg=_aquarium->getName()+" ("+_additive->getName()+") "+_dosage->getDailyDosageAmount(days);

    for (int i=1;i<=days;i++) {
        if (startDateTime.date()>QDate::currentDate()) {
            CalWrapper::setAlarm(startDateTime, startDateTime, msg);
            alarmsSet=true;
        }
        startDateTime=startDateTime.addDays(1);
    }

    if (alarmsSet)
        view->showAlarmSetMsg();
    else
        view->showNoAlarmSetMsg();
    EventBus::getInstance()->fireReturnFromSchedule();
}

void ScheduleScreen::handleBackBtnClicked()
{
    EventBus::getInstance()->fireReturnFromSchedule();
}

void ScheduleScreen::handleIntervalChanged(int days)
{
    view->setDailyDosageAmount(_dosage->getDailyDosageAmount(days));
}
