#include "dosageadviceverticalview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QIcon>

DosageAdviceVerticalView::DosageAdviceVerticalView(Screen* parent) :
    DosageAdviceView(parent)
{
    QVBoxLayout* vLayout=new QVBoxLayout(this);
    QVBoxLayout* panelLayout;
    QHBoxLayout* hLayout=new QHBoxLayout();
    QLabel* titleLabel=new QLabel("Dosage advice");
    QWidget* panel=new QWidget();
    QLabel* productsLabel=new QLabel("Products / Additives");


    calciumPanel=new QWidget();
    alkalinityPanel=new QWidget();
    magnesiumPanel=new QWidget();
    tabs=new QTabWidget();


    setObjectName("dosageadviceverticalview");
    // Crazy hack to allow styling
    setAttribute(Qt::WA_StyledBackground);

    panel->setObjectName("panel");
    titleLabel->setObjectName("titlelabel");

    vLayout->setSpacing(0);
    vLayout->setMargin(0);
    vLayout->addWidget(titleLabel);
    vLayout->addWidget(panel, 1);

    okBtn->setObjectName("okbtn");
    hLayout->addWidget(okBtn);
    backBtn->setObjectName("backbtn");
    hLayout->addStretch(1);
    hLayout->addWidget(backBtn);
    vLayout->addLayout(hLayout);

    vLayout=new QVBoxLayout(panel);
    vLayout->setSpacing(0);
    vLayout->setMargin(0);

    // System parameters
    waterVolLbl->setObjectName("watervollbl");
    vLayout->addWidget(waterVolLbl);
    desiredParamsLbl->setObjectName("desiredparamslbl");
    vLayout->addWidget(desiredParamsLbl);
    currentParamsLbl->setWordWrap(true);
    currentParamsLbl->setObjectName("currentparamslbl");
    vLayout->addWidget(currentParamsLbl);
    vLayout->addSpacing(2);

    // Products
    productsLabel->setObjectName("productslabel");
    vLayout->addWidget(productsLabel);
    vLayout->addWidget(tabs);
    tabs->addTab(calciumPanel, QIcon(":/icons/icons/ca.png"), "");
    tabs->addTab(alkalinityPanel, QIcon(":/icons/icons/alk.png"), "");
    tabs->addTab(magnesiumPanel, QIcon(":/icons/icons/mg.png"), "");

    vLayout->setStretchFactor(tabs, 1);

    // Calcium panel
    panelLayout=new QVBoxLayout(calciumPanel);
    panelLayout->addWidget(calciumBox);
    caDosageAmountLbl->setWordWrap(true);
    caDosageAmountLbl->setObjectName("dosageamountlabel");
    panelLayout->addWidget(caDosageAmountLbl);
    panelLayout->addWidget(scheduleCalciumBtn);
    caDosageAdviceLbl->setWordWrap(true);
    caDosageAdviceLbl->setObjectName("dosageadvicelabel");
    panelLayout->addWidget(caDosageAdviceLbl);
    panelLayout->addStretch(1);

    // Alkalinity panel
    panelLayout=new QVBoxLayout(alkalinityPanel);
    panelLayout->addWidget(alkalinityBox);
    alkDosageAmountLbl->setWordWrap(true);
    alkDosageAmountLbl->setObjectName("dosageamountlabel");
    panelLayout->addWidget(alkDosageAmountLbl);
    panelLayout->addWidget(scheduleAlkalinityBtn);
    alkDosageAdviceLbl->setWordWrap(true);
    alkDosageAdviceLbl->setObjectName("dosageadvicelabel");
    panelLayout->addWidget(alkDosageAdviceLbl);
    panelLayout->addStretch(1);

    // Magnesium panel
    panelLayout=new QVBoxLayout(magnesiumPanel);
    panelLayout->addWidget(magnesiumBox);
    mgDosageAmountLbl->setWordWrap(true);
    mgDosageAmountLbl->setObjectName("dosageamountlabel");
    panelLayout->addWidget(mgDosageAmountLbl);
    panelLayout->addWidget(scheduleMagnesiumBtn);
    mgDosageAdviceLbl->setWordWrap(true);
    mgDosageAdviceLbl->setObjectName("dosageadvicelabel");
    panelLayout->addWidget(mgDosageAdviceLbl);
    panelLayout->addStretch(1);

    connect(okBtn, SIGNAL(clicked()), this, SLOT(handleOk()));
    connect(backBtn, SIGNAL(clicked()), this, SLOT(handleBack()));
}


void DosageAdviceVerticalView::showPanelByIndex(int index)
{
    tabs->setCurrentIndex(index);
}

int DosageAdviceVerticalView::getVisiblePanelIndex()
{
    return tabs->currentIndex();
}
