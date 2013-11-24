#include "mainview.h"
#include <QMessageBox>

MainView::MainView(Screen *parent) :
    View(parent)
{
}

void MainView::setAquariumList(QList<QSharedPointer<Aquarium> > list)
{
    this->aquariumList=list;
}

void MainView::setCurrentId(int id)
{
    this->currentId=id;
}

void MainView::showAboutBox(QString aboutText)
{
    QMessageBox::about(this, tr("Reef Calculator"), aboutText);
}

void MainView::showErrorBox(QString errorText)
{
    QMessageBox::about(this, tr("Reef Calculator"), errorText);
}
