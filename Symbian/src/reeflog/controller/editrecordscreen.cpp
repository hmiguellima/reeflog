#include "editrecordscreen.h"
#include "eventbus.h"
#include "view/editrecordverticalview.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QRect>
#include <QScrollArea>
#include <QDateTime>
#include <QVariant>
#include <QSharedPointer>
#include "model/unittype.h"

EditRecordScreen::EditRecordScreen(MainWindow* window) : Screen(window), view(0)
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

    connect(EventBus::getInstance(), SIGNAL(showNewRecord(PAquarium)), this, SLOT(showNewRecord(PAquarium)));
    connect(EventBus::getInstance(), SIGNAL(showEditRecord(PAquarium, PLogRecord)), this, SLOT(showEditRecord(PAquarium, PLogRecord)));
    connect(EventBus::getInstance(), SIGNAL(returnFromAdvice()), this, SLOT(handleReturnFromAdvice()));
}

EditRecordScreen::~EditRecordScreen()
{
}

void EditRecordScreen::showHandler()
{
    if (!isBack) {
        if (view!=0)
            view->deleteLater();
        view=0;
        update();
    } else
        isBack=false;
}

void EditRecordScreen::showNewRecord(PAquarium aquarium)
{
    this->aquarium=aquarium;
    record=PLogRecord(new LogRecord());
    _title="New record";

    if (view!=0)
    {
        view->deleteLater();
        view=0;
    }

    show();
}

void EditRecordScreen::update()
{
    EditRecordView* oldView=0;

    if (!isCurrent())
        return;

    if (view!=0)
    {
        oldView=view;
        view->deleteLater();
    }


    view=new EditRecordVerticalView();

    // Water volume
    view->setTargetWaterVol(QVariant(aquarium->getWaterVolume()->getValue()).toString());
    view->setTargetWaterVolType(aquarium->getWaterVolume()->getVolumeType()->getKey());

    // Aquarium parameters
    view->setTargetCalciumLevel(QVariant(aquarium->getTargetParameters()->getCalcium()->getValue()).toString());
    view->setTargetCalciumLevelType(aquarium->getTargetParameters()->getCalcium()->getLevelType()->getKey().toAscii().at(0));

    view->setTargetAlkalinityLevel(QVariant(aquarium->getTargetParameters()->getAlkalinity()->getValue()).toString());
    view->setTargetAlkalinityLevelType(aquarium->getTargetParameters()->getAlkalinity()->getLevelType()->getKey().toAscii().at(0));

    view->setTargetMagnesiumLevel(QVariant(aquarium->getTargetParameters()->getMagnesium()->getValue()).toString());
    view->setTargetMagnesiumLevelType(aquarium->getTargetParameters()->getMagnesium()->getLevelType()->getKey().toAscii().at(0));


    // Record parameters
    view->setCurrentCalciumLevel(QVariant(record->getParameters()->getCalcium()->getValue()).toString());
    view->setCurrentCalciumLevelType(record->getParameters()->getCalcium()->getLevelType()->getKey().toAscii().at(0));

    view->setCurrentAlkalinityLevel(QVariant(record->getParameters()->getAlkalinity()->getValue()).toString());
    view->setCurrentAlkalinityLevelType(record->getParameters()->getAlkalinity()->getLevelType()->getKey().toAscii().at(0));

    view->setCurrentMagnesiumLevel(QVariant(record->getParameters()->getMagnesium()->getValue()).toString());
    view->setCurrentMagnesiumLevelType(record->getParameters()->getMagnesium()->getLevelType()->getKey().toAscii().at(0));

    view->setShowAdviceToogle(true);

    vLayout->addWidget(view);
    view->askFocus();
    view->setTitle(_title);

    connect(view, SIGNAL(backBtnClicked()), this, SLOT(goBackToHome()));
    connect(view, SIGNAL(saveBtnClicked()), this, SLOT(saveRecord()));
}

void EditRecordScreen::goBackToHome()
{
    EventBus::getInstance()->fireShowMainScreen();
}

void EditRecordScreen::saveRecord()
{
    PVolume newVolume=PVolume(new Volume());

    // Save target parameters
    aquarium->getTargetParameters()->getCalcium()->setValue(QVariant(view->getTargetCalciumLevel()).toReal());
    aquarium->getTargetParameters()->getCalcium()->setLevelType(LevelType::createLevelTypeFromKey(QString((view->getTargetCalciumLevelType()))));

    aquarium->getTargetParameters()->getAlkalinity()->setValue(QVariant(view->getTargetAlkalinityLevel()).toReal());
    aquarium->getTargetParameters()->getAlkalinity()->setLevelType(LevelType::createLevelTypeFromKey(QString((view->getTargetAlkalinityLevelType()))));

    aquarium->getTargetParameters()->getMagnesium()->setValue(QVariant(view->getTargetMagnesiumLevel()).toReal());
    aquarium->getTargetParameters()->getMagnesium()->setLevelType(LevelType::createLevelTypeFromKey(QString((view->getTargetMagnesiumLevelType()))));

    aquarium->getTargetParameters()->save();

    newVolume->setValue(QVariant(view->getTargetWaterVol()).toReal());
    newVolume->setVolumeType(VolumeType::createFromKey(QString(view->getTargetWaterVolType())));

    aquarium->setWaterVolume(newVolume);

    // Save log record
    if (record->getId()==0)
        record->setDate(QDateTime::currentDateTime());

    record->getParameters()->getCalcium()->setValue(QVariant(view->getCurrentCalciumLevel()).toReal());
    record->getParameters()->getCalcium()->setLevelType(LevelType::createLevelTypeFromKey(QString((view->getCurrentCalciumLevelType()))));

    record->getParameters()->getAlkalinity()->setValue(QVariant(view->getCurrentAlkalinityLevel()).toReal());
    record->getParameters()->getAlkalinity()->setLevelType(LevelType::createLevelTypeFromKey(QString(view->getCurrentAlkalinityLevelType())));

    record->getParameters()->getMagnesium()->setValue(QVariant(view->getCurrentMagnesiumLevel()).toReal());
    record->getParameters()->getMagnesium()->setLevelType(LevelType::createLevelTypeFromKey(QString(view->getCurrentMagnesiumLevelType())));

    if (record->getId()==0)
        aquarium->addLogRecord(record);
    else
        record->save();

    EventBus::getInstance()->fireEventsUpdated();

    if (view->getShowAdviceToogle())
        EventBus::getInstance()->fireShowAdviceScreen(aquarium, record);
    else
        EventBus::getInstance()->fireShowMainScreen();
}

void EditRecordScreen::showEditRecord(QSharedPointer<Aquarium> aquarium, QSharedPointer<LogRecord> record)
{
    this->aquarium=aquarium;
    this->record=record;
    _title="Edit record";


    if (view!=0)
    {
        view->deleteLater();
        view=0;
    }
    show();
}

void EditRecordScreen::handleReturnFromAdvice()
{
    isBack=true;
    show();
}
