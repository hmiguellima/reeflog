#ifndef SCHEDULESCREEN_H
#define SCHEDULESCREEN_H

#include "screen.h"
#include "view/scheduleview.h"
#include "view/scheduleverticalview.h"
#include "model/logrecord.h"
#include <QVBoxLayout>
#include <QList>
#include "model/additive.h"
#include <QStringListModel>
#include "model/aquarium.h"

class ScheduleScreen : public Screen
{
    Q_OBJECT
public:
    ScheduleScreen(MainWindow* window);

signals:

protected:
    void showHandler();

private slots:
    void showScheduleScreen(PAquarium aquarium, PAdditive additive, PLevel sourceLevel, PLevel destLevel);
    void update();
    void handleScheduleBtnClicked();
    void handleBackBtnClicked();
    void handleIntervalChanged(int days);

private:
    ScheduleView* view;
    ScheduleVerticalView* vView;
    QVBoxLayout* vLayout;
    PAquarium _aquarium;
    PDosage _dosage;
    PAdditive _additive;
};

#endif // SCHEDULESCREEN_H
