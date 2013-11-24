#include "editrecordview.h"
#include <QStringList>
#include "mycombobox.h"

EditRecordView::EditRecordView(Screen *parent) : View(parent)
{
    QStringList alkTypeList;
    QStringList caTypeList;
    QStringList volTypeList;

    volTypeList << "lit" << "gal" << "imp";
    alkTypeList << "dkh" << "ppm" << "meq";
    caTypeList << "ppm" << "meq/L";

    waterVolModel=new QStringListModel(volTypeList, this);
    alkModel=new QStringListModel(alkTypeList, this);
    caModel=new QStringListModel(caTypeList, this);

    waterVolEdit=new QLineEdit();
    waterVolCombo=new MyComboBox();
    waterVolCombo->setModel(waterVolModel);
    waterVolCombo->setCurrentIndex(0);
    targetCalciumEdit=new QLineEdit();
    targetCalciumCombo=new MyComboBox();
    targetCalciumCombo->setModel(caModel);
    targetCalciumCombo->setCurrentIndex(0);
    targetAlkalinityEdit=new QLineEdit();
    targetAlkalinityCombo=new MyComboBox();
    targetAlkalinityCombo->setModel(alkModel);
    targetAlkalinityCombo->setCurrentIndex(0);
    targetMagnesiumEdit=new QLineEdit();
    targetMagnesiumCombo=new MyComboBox();
    targetMagnesiumCombo->setModel(caModel);
    targetMagnesiumCombo->setCurrentIndex(0);
    currentCalciumEdit=new QLineEdit();
    currentCalciumCombo=new MyComboBox();
    currentCalciumCombo->setModel(caModel);
    currentCalciumCombo->setCurrentIndex(0);
    currentAlkalinityEdit=new QLineEdit();
    currentAlkalinityCombo=new MyComboBox();
    currentAlkalinityCombo->setModel(alkModel);
    currentAlkalinityCombo->setCurrentIndex(0);
    currentMagnesiumEdit=new QLineEdit();
    currentMagnesiumCombo=new MyComboBox();
    currentMagnesiumCombo->setModel(caModel);
    currentMagnesiumCombo->setCurrentIndex(0);
    showDosageCheck=new QCheckBox();

    connect(showDosageCheck, SIGNAL(clicked()), this, SLOT(handleDosageCheckClicked()));
}

void EditRecordView::setRecordDate(QDate date)
{

}

void EditRecordView::setTargetWaterVol(QString volume)
{
    waterVolEdit->setText(volume);
}

void EditRecordView::setTargetWaterVolType(char volType)
{
    switch (volType)
    {
    case 'L':
        waterVolCombo->setCurrentIndex(0);
        break;
    case 'G':
        waterVolCombo->setCurrentIndex(1);
        break;
    case 'I':
        waterVolCombo->setCurrentIndex(0);
        break;
    }


}

void EditRecordView::setTargetCalciumLevel(QString level)
{
    targetCalciumEdit->setText(level);
}

void EditRecordView::setTargetCalciumLevelType(char levelType)
{
    switch (levelType)
    {
    case 'P':
        targetCalciumCombo->setCurrentIndex(0);
        break;
    case 'M':
        targetCalciumCombo->setCurrentIndex(1);
        break;
    }
}

void EditRecordView::setTargetAlkalinityLevel(QString level)
{
    targetAlkalinityEdit->setText(level);
}

void EditRecordView::setTargetAlkalinityLevelType(char levelType)
{
    switch (levelType)
    {
    case 'D':
        targetAlkalinityCombo->setCurrentIndex(0);
        break;
    case 'P':
        targetAlkalinityCombo->setCurrentIndex(1);
        break;
    case 'M':
        targetAlkalinityCombo->setCurrentIndex(2);
        break;
    }
}

void EditRecordView::setTargetMagnesiumLevel(QString level)
{
    targetMagnesiumEdit->setText(level);
}

void EditRecordView::setTargetMagnesiumLevelType(char levelType)
{
    switch (levelType)
    {
    case 'P':
        targetMagnesiumCombo->setCurrentIndex(0);
        break;
    case 'M':
        targetMagnesiumCombo->setCurrentIndex(1);
        break;
    }
}

void EditRecordView::setCurrentCalciumLevel(QString level)
{
    currentCalciumEdit->setText(level);
}

void EditRecordView::setCurrentCalciumLevelType(char levelType)
{
    switch (levelType)
    {
    case 'P':
        currentCalciumCombo->setCurrentIndex(0);
        break;
    case 'M':
        currentCalciumCombo->setCurrentIndex(1);
        break;
    }
}

void EditRecordView::setCurrentAlkalinityLevel(QString level)
{
    currentAlkalinityEdit->setText(level);
}

void EditRecordView::setCurrentAlkalinityLevelType(char levelType)
{
    switch (levelType)
    {
    case 'D':
        currentAlkalinityCombo->setCurrentIndex(0);
        break;
    case 'P':
        currentAlkalinityCombo->setCurrentIndex(1);
        break;
    case 'M':
        currentAlkalinityCombo->setCurrentIndex(2);
        break;
    }
}

void EditRecordView::setCurrentMagnesiumLevel(QString level)
{
    currentMagnesiumEdit->setText(level);
}

void EditRecordView::setCurrentMagnesiumLevelType(char levelType)
{
    switch (levelType)
    {
    case 'P':
        currentMagnesiumCombo->setCurrentIndex(0);
        break;
    case 'M':
        currentMagnesiumCombo->setCurrentIndex(1);
        break;
    }
}

void EditRecordView::setShowAdviceToogle(bool enable)
{
    showDosageCheck->setChecked(enable);
}

QString EditRecordView::getTargetWaterVol()
{
    return waterVolEdit->text();
}

char EditRecordView::getTargetWaterVolType()
{
    switch (waterVolCombo->currentIndex())
    {
    case 0:
        return 'L';
    case 1:
        return 'G';
    case 2:
        return 'I';
    }
    return 0;
}

QString EditRecordView::getTargetCalciumLevel()
{
    return targetCalciumEdit->text();
}

char EditRecordView::getTargetCalciumLevelType()
{
    switch (targetCalciumCombo->currentIndex())
    {
    case 0:
        return 'P';
    case 1:
        return 'M';
    }
    return 0;
}

QString EditRecordView::getTargetAlkalinityLevel()
{
    return targetAlkalinityEdit->text();
}

char EditRecordView::getTargetAlkalinityLevelType()
{
    switch (targetAlkalinityCombo->currentIndex())
    {
    case 0:
        return 'D';
    case 1:
        return 'P';
    case 2:
        return 'M';
    }
    return 0;
}

QString EditRecordView::getTargetMagnesiumLevel()
{
    return targetMagnesiumEdit->text();
}

char EditRecordView::getTargetMagnesiumLevelType()
{
    switch (targetMagnesiumCombo->currentIndex())
    {
    case 0:
        return 'P';
    case 1:
        return 'M';
    }
    return 0;
}

QString EditRecordView::getCurrentCalciumLevel()
{
    return currentCalciumEdit->text();
}

char EditRecordView::getCurrentCalciumLevelType()
{
    switch (currentCalciumCombo->currentIndex())
    {
    case 0:
        return 'P';
    case 1:
        return 'M';
    }
    return 0;
}

QString EditRecordView::getCurrentAlkalinityLevel()
{
    return currentAlkalinityEdit->text();
}

char EditRecordView::getCurrentAlkalinityLevelType()
{
    switch (currentAlkalinityCombo->currentIndex())
    {
    case 0:
        return 'D';
    case 1:
        return 'P';
    case 2:
        return 'M';
    }
    return 0;
}

QString EditRecordView::getCurrentMagnesiumLevel()
{
    return currentMagnesiumEdit->text();
}

char EditRecordView::getCurrentMagnesiumLevelType()
{
    switch (currentMagnesiumCombo->currentIndex())
    {
    case 0:
        return 'P';
    case 1:
        return 'M';
    }
    return 0;
}

bool EditRecordView::getShowAdviceToogle()
{
    return showDosageCheck->isChecked();
}

void EditRecordView::handleSaveBtnClicked()
{
    playBtnSound();
    emit saveBtnClicked();
}

void EditRecordView::handleBackBtnClicked()
{
    playBtnSound();
    emit backBtnClicked();
}

void EditRecordView::handleDosageCheckClicked()
{
    playBtnSound();
    askFocusNow();
}
