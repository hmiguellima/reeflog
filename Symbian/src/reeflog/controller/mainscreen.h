#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "screen.h"
#include "view/mainview.h"
#include "model/recordmodel.h"
#include "model/aquarium.h"
#include <QVBoxLayout>
#include "view/mainverticalview.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QProgressDialog>

class MainWindow;

class MainScreen : public Screen
{
    Q_OBJECT

public:
    explicit MainScreen(MainWindow* window);
    ~MainScreen();

signals:

protected:
    void showHandler();

private:
    MainView* view;
    MainVerticalView* vView;
    PAquarium aquarium;
    PRecordModel model;
    QVBoxLayout* vLayout;
    QList<PAquarium > aquariumList;
    QNetworkAccessManager *network;
    QString getAboutText();
    QProgressDialog* progressDlg;

private slots:
    void handleNewRecordClicked();
    void handleRecordDeleteClicked(int index);
    void handleRecordEditClicked(int index);
    void handleAboutBtnClicked();
    void handleAquariumClicked(int index);
    void handleNewAquariumClicked();
    void handleDeleteAquariumClicked();
    void handleUpdateAdditivesClicked();
    void handleEventsUpdated();
    void updateOrientation(int screen=0);
    void replyFinished(QNetworkReply *reply);
};

#endif // MAINSCREEN_H
