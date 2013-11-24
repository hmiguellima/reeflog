#include "mainscreen.h"
#include "mainwindow.h"
#include "view/mainverticalview.h"
#include "eventbus.h"
#include <QScrollArea>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>

MainScreen::MainScreen(MainWindow* window) :
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

    aquarium=PAquarium(new Aquarium(1));
    model=PRecordModel(new RecordModel());
    model->setLogData(aquarium->getLogHistory());
    aquariumList=Aquarium::listAquariums();

    network=new QNetworkAccessManager(this);
    progressDlg=new QProgressDialog("Downloading additives", "Cancel", 0, 0, this);
    //progressDlg->setWindowModality(Qt::WindowModal);

    connect(network, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(updateOrientation(int)));
    connect(EventBus::getInstance(), SIGNAL(eventsUpdated()), this, SLOT(handleEventsUpdated()));
}

MainScreen::~MainScreen()
{
}

void MainScreen::showHandler()
{
    updateOrientation();
}

void MainScreen::handleNewRecordClicked()
{
    EventBus::getInstance()->fireShowNewRecord(aquarium);
}

void MainScreen::updateOrientation(int screen)
{
    MainView* oldView=0;

    if (view!=0)
    {
        oldView=view;
        view->deleteLater();
    }


    view=new MainVerticalView();

    if (oldView !=0)
    {
    }

    vLayout->addWidget(view);
    view->askFocus();
    view->setEvents(model);
    view->setTitle(aquarium->getName());
    view->setCurrentId(aquarium->getId());
    view->setAquariumList(aquariumList);

    connect(view, SIGNAL(quitBtnClicked()), qApp, SLOT(quit()));
    connect(view, SIGNAL(newBtnClicked()), this, SLOT(handleNewRecordClicked()));
    connect(view, SIGNAL(aboutClicked()), this, SLOT(handleAboutBtnClicked()));
    connect(view, SIGNAL(recordDeleteClicked(int)), this, SLOT(handleRecordDeleteClicked(int)));
    connect(view, SIGNAL(recordEditClicked(int)), this, SLOT(handleRecordEditClicked(int)));
    connect(view, SIGNAL(newAquariumClicked()), this, SLOT(handleNewAquariumClicked()));
    connect(view, SIGNAL(aquariumClicked(int)), this, SLOT(handleAquariumClicked(int)));
    connect(view, SIGNAL(aquariumDeleteClicked()), this, SLOT(handleDeleteAquariumClicked()));
    connect(view, SIGNAL(updateaAdditivesClicked()), this, SLOT(handleUpdateAdditivesClicked()));
}

void MainScreen::handleAboutBtnClicked()
{
    view->showAboutBox(getAboutText());
}

void MainScreen::handleRecordDeleteClicked(int index)
{
    PLogRecord record;

    record=model->getRecordAt(index);
    aquarium->deleteLogRecord(record);
    model->setLogData(aquarium->getLogHistory());
}

void MainScreen::handleRecordEditClicked(int index)
{
    PLogRecord record;

    record=model->getRecordAt(index);
    EventBus::getInstance()->fireShowEditRecord(aquarium, record);
}

void MainScreen::handleAquariumClicked(int index)
{
    aquarium=aquariumList.at(index);
    model->setLogData(aquarium->getLogHistory());
    updateOrientation();
}

void MainScreen::handleNewAquariumClicked()
{
    Aquarium::newAquarium();
    aquariumList=Aquarium::listAquariums();
    aquarium=aquariumList.at(aquariumList.length()-1);
    model->setLogData(aquarium->getLogHistory());
    updateOrientation();
}

void MainScreen::handleDeleteAquariumClicked()
{
    aquarium->remove();
    aquariumList=Aquarium::listAquariums();
    aquarium=aquariumList.at(0);
    model->setLogData(aquarium->getLogHistory());
    updateOrientation();
}

void MainScreen::handleUpdateAdditivesClicked()
{
    progressDlg->reset();
    progressDlg->show();
    network->get(QNetworkRequest(QUrl("http://www.hlimasoft.com/reefcalculator/updatescript.txt")));
}

void MainScreen::replyFinished(QNetworkReply *reply)
{
    QString sql;
    QSqlQuery query;
    QNetworkReply::NetworkError error;

    error=reply->error();
    progressDlg->accept();

    if (!progressDlg->wasCanceled())
    {
        if (error!=QNetworkReply::NoError)
        {
            view->showErrorBox("Update failed: "+reply->errorString());
        }
        else
        {
            QTextStream textStream(reply->readAll());

            while (!(sql=textStream.readLine()).isNull())
                query.exec(sql);
            view->showAboutBox("Additives updated");
        }
    }

    reply->deleteLater();
}

QString MainScreen::getAboutText()
{
    QFile file(":/txt/about.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    return in.readAll();
}

void MainScreen::handleEventsUpdated()
{
    model->setLogData(aquarium->getLogHistory());
}
