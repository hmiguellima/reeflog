#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "view.h"
#include "controller/screen.h"
#include <QList>
#include "model/recordmodel.h"
#include "model/aquarium.h"

class MainView : public View
{
    Q_OBJECT
public:
    explicit MainView(Screen *parent = 0);
    virtual void setTitle(QString title)=0;
    void setAquariumList(QList<PAquarium> list);
    void setCurrentId(int id);
    void showAboutBox(QString aboutText);
    void showErrorBox(QString errorText);

signals:
    void newBtnClicked();
    void aboutClicked();
    void quitBtnClicked();
    void recordDeleteClicked(int index);
    void recordEditClicked(int index);
    void aquariumClicked(int index);
    void aquariumDeleteClicked();
    void newAquariumClicked();
    void updateaAdditivesClicked();

public slots:
    virtual void setEvents(PRecordModel eventsModel)=0;

protected:
    QList<PAquarium> aquariumList;
    int currentId;
};

#endif // MAINVIEW_H
