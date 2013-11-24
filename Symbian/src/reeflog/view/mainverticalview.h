#ifndef MAINVERTICALVIEW_H
#define MAINVERTICALVIEW_H

#include <QListView>
#include <QAbstractListModel>
#include "controller/screen.h"
#include "mainview.h"
#include <QModelIndex>
#include <QComboBox>
#include <QLabel>

class MainVerticalView : public MainView
{
    Q_OBJECT
public:
    MainVerticalView(Screen* parent=0);

    void setEvents(PRecordModel eventsModel);
    virtual void setTitle(QString title);

private:
    QListView* _recordList;
    QComboBox* _recordOptionsBox;
    QComboBox* _mainOptionsBox;
    RecordModel* _eventsModel;
    QLabel* titleLabel;
    int _selectedRow;

private slots:
    void handleListClicked(QModelIndex index);
    void handleRecordOptionSelected(int index);
    void handleMainOptionSelected(int index);
    void handleNewBtnClicked();
    void handleAboutBtnClicked();
    void handleQuitBtnClicked();
};

#endif // MAINVERTICALVIEW_H
