#ifndef DOSAGEADVICESCREEN_H
#define DOSAGEADVICESCREEN_H

#include "controller/screen.h"
#include "view/dosageadviceview.h"
#include "view/dosageadviceverticalview.h"
#include "model/logrecord.h"
#include "model/aquarium.h"
#include <QVBoxLayout>
#include <QList>
#include "model/additive.h"
#include <QStringListModel>

class DosageAdviceScreen : public Screen
{
    Q_OBJECT
public:
    DosageAdviceScreen(MainWindow* window);
    ~DosageAdviceScreen();

signals:

protected:
    void showHandler();

private:
    DosageAdviceView* view;
    DosageAdviceVerticalView* vView;
    QVBoxLayout* vLayout;
    PLogRecord record;
    PAquarium aquarium;
    QList<PAdditive > calciumAdditives;
    QStringListModel* caAdditiveNamesModel;
    QList<PAdditive > alkalinityAdditives;
    QStringListModel* alkAdditiveNamesModel;
    QList<PAdditive > magnesiumAdditives;
    QStringListModel* mgAdditiveNamesModel;
    int caAdditiveIndex;
    int mgAdditiveIndex;
    int alkAdditiveIndex;
    bool isBack;

private slots:
    void showDosageAdviceScreen(PAquarium aquarium, PLogRecord record);
    void update();
    void handleCalciumAdditiveSelected(int index);
    void handleAlkalinityAdditiveSelected(int index);
    void handleMagnesiumAdditiveSelected(int index);
    void handleOkClicked();
    void handleScheduleCalciumClicked();
    void handleScheduleAlkalinityClicked();
    void handleScheduleMagnesiumClicked();
    void returnFromSchedule();
    void handleBackClicked();
};

#endif // DOSAGEADVICESCREEN_H
