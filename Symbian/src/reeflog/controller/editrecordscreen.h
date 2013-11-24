#ifndef EDITRECORDSCREEN_H
#define EDITRECORDSCREEN_H

#include "controller/screen.h"
#include "view/editrecordview.h"
#include "view/editrecordverticalview.h"
#include <QVBoxLayout>
#include "model/logrecord.h"
#include "model/aquarium.h"

class EditRecordScreen : public Screen
{
    Q_OBJECT

public:
    explicit EditRecordScreen(MainWindow* window);
    ~EditRecordScreen();

signals:

protected:
    void showHandler();

private:
    EditRecordView* view;
    EditRecordVerticalView* vView;
    QVBoxLayout* vLayout;
    PLogRecord record;
    PAquarium aquarium;
    QString _title;
    bool isBack;

private slots:
    void showNewRecord(PAquarium aquarium);
    void showEditRecord(PAquarium aquarium, PLogRecord record);
    void update();
    void goBackToHome();
    void saveRecord();
    void handleReturnFromAdvice();
};

#endif // EDITRECORDSCREEN_H
