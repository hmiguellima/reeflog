#include "dosageadviceview.h"
#include "mycombobox.h"

DosageAdviceView::DosageAdviceView(Screen* parent) : View(parent)
{
    editParmsBtn=new QPushButton("Edit");
    scheduleCalciumBtn=new QPushButton("Schedule dosage alarm");
    scheduleAlkalinityBtn=new QPushButton("Schedule dosage alarm");
    scheduleMagnesiumBtn=new QPushButton("Schedule dosage alarm");
    calciumBox=new MyComboBox();
    alkalinityBox=new MyComboBox();
    magnesiumBox=new MyComboBox();
    okBtn=new QPushButton("");
    backBtn=new QPushButton("");
    waterVolLbl=new QLabel();
    desiredParamsLbl=new QLabel();
    currentParamsLbl=new QLabel();
    caDosageAdviceLbl=new QLabel();
    caDosageAmountLbl=new QLabel();
    alkDosageAdviceLbl=new QLabel();
    alkDosageAmountLbl=new QLabel();
    mgDosageAdviceLbl=new QLabel();
    mgDosageAmountLbl=new QLabel();

    connect(editParmsBtn, SIGNAL(clicked()), this, SLOT(handleEditParams()));
    connect(scheduleCalciumBtn, SIGNAL(clicked()), this, SLOT(handleScheduleCalcium()));
    connect(scheduleAlkalinityBtn, SIGNAL(clicked()), this, SLOT(handleScheduleAlkalinity()));
    connect(scheduleMagnesiumBtn, SIGNAL(clicked()), this, SLOT(handleScheduleMagnesium()));
    connect(calciumBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleCalciumAdditiveSelected(int)));
    connect(alkalinityBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleAlkalinityAdditiveSelected(int)));
    connect(magnesiumBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleMagnesiumAdditiveSelected(int)));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(handleOk()));
}

void DosageAdviceView::setWaterVolume(QString volume)
{
    waterVolLbl->setText(volume);
}

void DosageAdviceView::setDesiredParams(QString params)
{
    desiredParamsLbl->setText(params);
}

void DosageAdviceView::setCurrentParams(QString params)
{
    currentParamsLbl->setText(params);
}


void DosageAdviceView::setCalciumAdditives(QStringListModel* additives)
{
    calciumBox->setModel(additives);
    calciumBox->setCurrentIndex(0);
}

void DosageAdviceView::setAlkalinityAdditives(QStringListModel* additives)
{
    alkalinityBox->setModel(additives);
    alkalinityBox->setCurrentIndex(0);
}

void DosageAdviceView::setMagnesiumAdditives(QStringListModel* additives)
{
    magnesiumBox->setModel(additives);
    magnesiumBox->setCurrentIndex(0);
}

void DosageAdviceView::setCaDosageAdvice(QString advice)
{
    caDosageAdviceLbl->setText(advice);
}

void DosageAdviceView::setCaDosageAmount(QString amount)
{
    caDosageAmountLbl->setText(amount);
}


void DosageAdviceView::setAlkDosageAdvice(QString advice)
{
    alkDosageAdviceLbl->setText(advice);
}

void DosageAdviceView::setAlkDosageAmount(QString amount)
{
    alkDosageAmountLbl->setText(amount);
}

void DosageAdviceView::setMgDosageAdvice(QString advice)
{
    mgDosageAdviceLbl->setText(advice);
}

void DosageAdviceView::setMgDosageAmount(QString amount)
{
    mgDosageAmountLbl->setText(amount);
}

void DosageAdviceView::handleEditParams()
{
    emit editParametersClicked();
}

void DosageAdviceView::handleCalciumAdditiveSelected(int index)
{
    emit calciumAdditiveSelected(index);
}

void DosageAdviceView::handleAlkalinityAdditiveSelected(int index)
{
    emit alkalinityAdditiveSelected(index);
}

void DosageAdviceView::handleMagnesiumAdditiveSelected(int index)
{
    emit magnesiumAdditiveSelected(index);
}

void DosageAdviceView::handleScheduleCalcium()
{
    emit scheduleCalciumClicked();
}

void DosageAdviceView::handleScheduleAlkalinity()
{
    emit scheduleAlkalinityClicked();
}

void DosageAdviceView::handleScheduleMagnesium()
{
    emit scheduleMagnesiumClicked();
}

void DosageAdviceView::handleOk()
{
    playBtnSound();
    emit okClicked();
}

void DosageAdviceView::setCaAdditiveIndex(int index)
{
    calciumBox->setCurrentIndex(index);
}

int DosageAdviceView::getCaAdditiveIndex()
{
    return calciumBox->currentIndex();
}

void DosageAdviceView::setAlkAdditiveIndex(int index)
{
    alkalinityBox->setCurrentIndex(index);
}

int DosageAdviceView::getAlkAdditiveIndex()
{
    return alkalinityBox->currentIndex();
}

void DosageAdviceView::setMgAdditiveIndex(int index)
{
    magnesiumBox->setCurrentIndex(index);
}

int DosageAdviceView::getMgAdditiveIndex()
{
    return magnesiumBox->currentIndex();
}

void DosageAdviceView::handleBack()
{
    emit backClicked();
}
