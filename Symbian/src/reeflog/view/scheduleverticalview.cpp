#include "scheduleverticalview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QIcon>

ScheduleVerticalView::ScheduleVerticalView(Screen* parent) :
    ScheduleView(parent)
{
    QVBoxLayout* vLayout=new QVBoxLayout(this);
    QHBoxLayout* hLayout;
    QLabel* titleLabel=new QLabel("Scheduler");
    QLabel* productTitleLbl=new QLabel("Product required");
    QLabel* startDateLbl=new QLabel("Start date:");
    QLabel* distributeByLbl=new QLabel("Distribute by:");
    QLabel* daysLbl=new QLabel("days.");
    QWidget* panel=new QWidget();
    QVBoxLayout* panelLayout=new QVBoxLayout(panel);

    setObjectName("scheduleverticalview");
    // Crazy hack to allow styling
    setAttribute(Qt::WA_StyledBackground);

    titleLabel->setObjectName("titlelabel");

    vLayout->setSpacing(0);
    vLayout->setMargin(0);
    panel->setObjectName("panel");
    vLayout->addWidget(titleLabel);
    vLayout->addWidget(panel, 1);

    hLayout=new QHBoxLayout();
    scheduleBtn->setObjectName("okbtn");
    hLayout->addWidget(scheduleBtn);
    hLayout->addStretch(1);
    cancelBtn->setObjectName("backbtn");
    hLayout->addWidget(cancelBtn);

    vLayout->addLayout(hLayout);

    productTitleLbl->setObjectName("producttitlelbl");
    panelLayout->addWidget(productTitleLbl);
    panelLayout->addWidget(productLbl);
    amountLbl->setObjectName("amountlbl");
    amountLbl->setWordWrap(true);
    panelLayout->addWidget(amountLbl);
    adviceLbl->setObjectName("advicelbl");
    adviceLbl->setWordWrap(true);
    panelLayout->addWidget(adviceLbl);

    hLayout=new QHBoxLayout();
    panelLayout->addLayout(hLayout);
    hLayout->addWidget(startDateLbl);
    hLayout->addWidget(startDateEdit);

    hLayout=new QHBoxLayout();
    panelLayout->addLayout(hLayout);
    hLayout->addWidget(distributeByLbl);
    hLayout->addWidget(intervalEdit);
    hLayout->addWidget(daysLbl);
    hLayout->addWidget(dailyAmountLbl);

    intervalEdit->setInputMask("D");
    intervalEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);

    connect(scheduleBtn, SIGNAL(clicked()), this, SLOT(handleScheduleBtnClicked()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(handleBackBtnClicked()));
    connect(intervalEdit, SIGNAL(textChanged(QString)), this, SLOT(handleIntervalChanged(QString)));
}


