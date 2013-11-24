#include "dosageadvicescreen.h"
#include <QScrollArea>
#include "eventbus.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStringList>
#include <QStringListModel>
#include "model/calciumlevel.h"
#include "model/alkalinitylevel.h"
#include "model/magnesiumlevel.h"
#include "view/editrecordverticalview.h"

DosageAdviceScreen::DosageAdviceScreen(MainWindow* window) :
    Screen(window), view(0), caAdditiveIndex(0), mgAdditiveIndex(0), alkAdditiveIndex(0)
{
    QVBoxLayout* containerLayout=new QVBoxLayout(this);
    QScrollArea* scrollArea=new QScrollArea();
    PLevel level;
    QStringList caAdditiveNames;
    QStringList alkAdditiveNames;
    QStringList mgAdditiveNames;
    PAdditive additive;

    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setFrameShape(QFrame::NoFrame);
    containerLayout->addWidget(scrollArea);
    containerLayout->setMargin(0);
    containerLayout->setSpacing(0);
    vLayout=new QVBoxLayout(scrollArea);
    vLayout->setMargin(0);
    vLayout->setSpacing(0);

    level=PLevel(new CalciumLevel());
    calciumAdditives=level->listPossibleAdditives();
    caAdditiveNames << "<Select>";
    foreach(additive, calciumAdditives)
        caAdditiveNames << additive->getName();
    caAdditiveNamesModel=new QStringListModel(caAdditiveNames, this);

    level=PLevel(new AlkalinityLevel());
    alkalinityAdditives=level->listPossibleAdditives();
    alkAdditiveNames << "<Select>";
    foreach(additive, alkalinityAdditives)
        alkAdditiveNames << additive->getName();
    alkAdditiveNamesModel=new QStringListModel(alkAdditiveNames, this);


    level=PLevel(new MagnesiumLevel());
    magnesiumAdditives=level->listPossibleAdditives();
    mgAdditiveNames << "<Select>";
    foreach(additive, magnesiumAdditives)
        mgAdditiveNames << additive->getName();
    mgAdditiveNamesModel=new QStringListModel(mgAdditiveNames, this);

    isBack=false;

    connect(EventBus::getInstance(), SIGNAL(showAdviceScreen(PAquarium, PLogRecord)), this, SLOT(showDosageAdviceScreen(PAquarium, PLogRecord)));
    connect(EventBus::getInstance(), SIGNAL(returnFromSchedule()), this, SLOT(returnFromSchedule()));
}

DosageAdviceScreen::~DosageAdviceScreen()
{
}

void DosageAdviceScreen::showHandler()
{
    if (!isBack) {
        if (view!=0)
            view->deleteLater();
        view=0;
        update();
    } else {
        isBack=false;
    }
}

void DosageAdviceScreen::showDosageAdviceScreen(PAquarium aquarium, PLogRecord record)
{
    this->aquarium=aquarium;
    this->record=record;
    show();
}

void DosageAdviceScreen::update()
{
    DosageAdviceView* oldView=0;

    if (!isCurrent())
        return;

    if (view!=0)
    {
        oldView=view;
        view->deleteLater();
    }


    view=new DosageAdviceVerticalView();

    view->setWaterVolume(aquarium->getWaterVolume()->toString());
    view->setDesiredParams(aquarium->getTargetParameters()->toString("Desired"));
    view->setCurrentParams(QString("%0 (%1)").arg(record->getParameters()->toString("Current")).arg(record->getDate().date().toString(Qt::SystemLocaleShortDate)));
    view->setCalciumAdditives(caAdditiveNamesModel);
    view->setAlkalinityAdditives(alkAdditiveNamesModel);
    view->setMagnesiumAdditives(mgAdditiveNamesModel);
    view->setCaDosageAdvice("Dosage advice (select additive)");
    view->setAlkDosageAdvice("Dosage advice (select additive)");
    view->setMgDosageAdvice("Dosage advice (select additive)");
    view->setCaDosageAmount("Dosage amount (select additive)");
    view->setAlkDosageAmount("Dosage amount (select additive)");
    view->setMgDosageAmount("Dosage amount (select additive)");

    vLayout->addWidget(view);
    view->askFocus();

    connect(view, SIGNAL(okClicked()), this, SLOT(handleOkClicked()));
    connect(view, SIGNAL(calciumAdditiveSelected(int)), this, SLOT(handleCalciumAdditiveSelected(int)));
    connect(view, SIGNAL(alkalinityAdditiveSelected(int)), this, SLOT(handleAlkalinityAdditiveSelected(int)));
    connect(view, SIGNAL(magnesiumAdditiveSelected(int)), this, SLOT(handleMagnesiumAdditiveSelected(int)));
    connect(view, SIGNAL(scheduleAlkalinityClicked()), this, SLOT(handleScheduleAlkalinityClicked()));
    connect(view, SIGNAL(scheduleCalciumClicked()), this, SLOT(handleScheduleCalciumClicked()));
    connect(view, SIGNAL(scheduleMagnesiumClicked()), this, SLOT(handleScheduleMagnesiumClicked()));
    connect(view, SIGNAL(backClicked()), this, SLOT(handleBackClicked()));
}

void DosageAdviceScreen::handleCalciumAdditiveSelected(int index)
{
    caAdditiveIndex=index;
    if (index==0)
    {
        view->setCaDosageAdvice("Dosage advice (select additive)");
        view->setCaDosageAmount("Dosage amount (select additive)");
    }
    else
    {
        PDosage dosage=calciumAdditives.at(index-1)->calcDosage(*aquarium->getWaterVolume(), record->getParameters()->getCalcium(), aquarium->getTargetParameters()->getCalcium());
        view->setCaDosageAmount(dosage->toString());
        view->setCaDosageAdvice(calciumAdditives.at(index-1)->getInstructions());
    }
}

void DosageAdviceScreen::handleAlkalinityAdditiveSelected(int index)
{
    alkAdditiveIndex=index;
    if (index==0)
    {
        view->setAlkDosageAdvice("Dosage advice (select additive)");
        view->setAlkDosageAmount("Dosage amount (select additive)");
    }
    else
    {
        PDosage dosage=alkalinityAdditives.at(index-1)->calcDosage(*aquarium->getWaterVolume(), record->getParameters()->getAlkalinity(), aquarium->getTargetParameters()->getAlkalinity());
        view->setAlkDosageAmount(dosage->toString());
        view->setAlkDosageAdvice(alkalinityAdditives.at(index-1)->getInstructions());
    }
}

void DosageAdviceScreen::handleMagnesiumAdditiveSelected(int index)
{
    mgAdditiveIndex=index;
    if (index==0)
    {
        view->setMgDosageAdvice("Dosage advice (select additive)");
        view->setMgDosageAmount("Dosage amount (select additive)");
    }
    else
    {
        PDosage dosage=magnesiumAdditives.at(index-1)->calcDosage(*aquarium->getWaterVolume(), record->getParameters()->getMagnesium(), aquarium->getTargetParameters()->getMagnesium());
        view->setMgDosageAmount(dosage->toString());
        view->setMgDosageAdvice(magnesiumAdditives.at(index-1)->getInstructions());
    }
}

void DosageAdviceScreen::handleOkClicked()
{
    EventBus::getInstance()->fireShowMainScreen();
}

void DosageAdviceScreen::handleScheduleCalciumClicked()
{
    if (caAdditiveIndex!=0) {
        EventBus::getInstance()->fireShowScheduleScreen(aquarium, calciumAdditives.at(caAdditiveIndex-1), record->getParameters()->getCalcium(), aquarium->getTargetParameters()->getCalcium());
    }
}

void DosageAdviceScreen::handleScheduleAlkalinityClicked()
{
    if (alkAdditiveIndex!=0) {
        EventBus::getInstance()->fireShowScheduleScreen(aquarium, alkalinityAdditives.at(alkAdditiveIndex-1), record->getParameters()->getAlkalinity(), aquarium->getTargetParameters()->getAlkalinity());
    }
}

void DosageAdviceScreen::handleScheduleMagnesiumClicked()
{
    if (mgAdditiveIndex!=0) {
        EventBus::getInstance()->fireShowScheduleScreen(aquarium, magnesiumAdditives.at(mgAdditiveIndex-1), record->getParameters()->getMagnesium(), aquarium->getTargetParameters()->getMagnesium());
    }
}

void DosageAdviceScreen::returnFromSchedule()
{
    isBack=true;
    show();
}

void DosageAdviceScreen::handleBackClicked()
{
    EventBus::getInstance()->fireReturnFromAdvice();
}
