#include "mainverticalview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include "model/recordmodel.h"
#include "recorddelegate.h"
#include <QAbstractItemView>
#include <QWidget>
#include <QPushButton>
#include "qtkineticscroller/qtscroller.h"
#include <QMessageBox>
#include "mycombobox.h"
#include <QMessageBox>

MainVerticalView::MainVerticalView(Screen* parent) :
    MainView(parent)
{
    QVBoxLayout* vLayout=new QVBoxLayout(this);
    RecordDelegate* delegate=new RecordDelegate(this);
    QHBoxLayout* hLayout=new QHBoxLayout();
    QPushButton* newBtn=new QPushButton("");
    QPushButton* aboutBtn=new QPushButton("");
    QPushButton* quitBtn=new QPushButton("");

    setObjectName("baseverticalview");
    // Crazy hack to allow styling
    setAttribute(Qt::WA_StyledBackground);

    titleLabel=new QLabel("");
    titleLabel->setObjectName("titlelabel");

    _recordList = new QListView();
    _recordOptionsBox = new MyComboBox(this);
    _recordOptionsBox->setVisible(false);
    _recordOptionsBox->addItem("Edit");
    _recordOptionsBox->addItem("Delete");

    _mainOptionsBox = new MyComboBox(this);
    _mainOptionsBox->setVisible(false);

    QtScroller::grabGesture(_recordList->viewport(), QtScroller::LeftMouseButtonGesture);

    vLayout->setSpacing(0);
    vLayout->setMargin(0);
    vLayout->addWidget(titleLabel);
    vLayout->addWidget(_recordList);
    _recordList->setItemDelegate(delegate);
    _recordList->setSelectionRectVisible(false);
    _recordList->setSelectionMode(QAbstractItemView::NoSelection);
    _recordList->setVerticalScrollMode(QListView::ScrollPerPixel);
    vLayout->addSpacing(15);
    vLayout->addLayout(hLayout);

    newBtn->setObjectName("newbtn");
    newBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout->addWidget(newBtn);

    hLayout->addStretch(1);

    aboutBtn->setObjectName("aboutbtn");
    aboutBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout->addWidget(aboutBtn);

    hLayout->addSpacing(5);

    quitBtn->setObjectName("quitbtn");
    quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout->addWidget(quitBtn);

    connect(_recordList, SIGNAL(clicked(QModelIndex)), this, SLOT(handleListClicked(QModelIndex)));
    connect(newBtn, SIGNAL(clicked()), this, SLOT(handleNewBtnClicked()));
    connect(aboutBtn, SIGNAL(clicked()), this, SLOT(handleAboutBtnClicked()));
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(handleQuitBtnClicked()));
    connect(_recordOptionsBox, SIGNAL(activated(int)), this, SLOT(handleRecordOptionSelected(int)));
    connect(_mainOptionsBox, SIGNAL(activated(int)), this, SLOT(handleMainOptionSelected(int)));
}

void MainVerticalView::setEvents(PRecordModel eventsModel)
{
    _recordList->setModel(eventsModel.data());
    _recordList->setCurrentIndex(QModelIndex());
}

void MainVerticalView::handleListClicked(QModelIndex index)
{
    if (index.data(RecordModel::DateRole).isValid()) {
        _selectedRow=index.row();
        _recordList->setCurrentIndex(QModelIndex());
        _recordOptionsBox->showPopup();
    }
}

void MainVerticalView::handleNewBtnClicked()
{
    playBtnSound();
    emit newBtnClicked();
}

void MainVerticalView::handleAboutBtnClicked()
{
    PAquarium aquarium;

    playBtnSound();
    _mainOptionsBox->clear();
    foreach (aquarium, aquariumList)
        _mainOptionsBox->addItem(aquarium->getName(), QVariant(0));
    _mainOptionsBox->addItem("New Reef", QVariant(1));
    if (currentId!=1)
        _mainOptionsBox->addItem("Delete Reef", QVariant(2));
    _mainOptionsBox->addItem("Update additives", QVariant(3));
    _mainOptionsBox->addItem("About", QVariant(4));

    _mainOptionsBox->showPopup();
}

void MainVerticalView::handleQuitBtnClicked()
{
    playBtnSound();
    emit quitBtnClicked();
}

void MainVerticalView::handleRecordOptionSelected(int index)
{
    if (index==0) {
        emit recordEditClicked(_selectedRow);
    } else {
        if (QMessageBox::question(this, "Reef Calculator", "Remove this record?", QMessageBox::Ok | QMessageBox::Cancel)==QMessageBox::Ok)
            emit recordDeleteClicked(_selectedRow);
    }
}

void MainVerticalView::setTitle(QString title)
{
    titleLabel->setText(title);
}

void MainVerticalView::handleMainOptionSelected(int index)
{
    int optionType;

    optionType=_mainOptionsBox->itemData(index).toInt();

    switch (optionType) {
    case 0:
        emit aquariumClicked(index);
        return;
    case 1:
        emit newAquariumClicked();
        return;
    case 2:
        if (QMessageBox::question(this, "Reef Calculator", "Remove this reef?", QMessageBox::Ok | QMessageBox::Cancel)==QMessageBox::Ok)
            emit aquariumDeleteClicked();
        return;
    case 3:
        emit updateaAdditivesClicked();
        return;
    case 4:
        emit aboutClicked();
        return;
    }
}
