#ifndef EDITRECORDVIEW_H
#define EDITRECORDVIEW_H

#include "view.h"
#include <QString>
#include <QDate>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QStringListModel>

class EditRecordView : public View
{
    Q_OBJECT
public:
    EditRecordView(Screen *parent = 0);

    virtual void setRecordDate(QDate date);
    virtual void setTargetWaterVol(QString volume);
    virtual void setTargetWaterVolType(char volType);
    virtual void setTargetCalciumLevel(QString level);
    virtual void setTargetCalciumLevelType(char levelType);
    virtual void setTargetAlkalinityLevel(QString level);
    virtual void setTargetAlkalinityLevelType(char levelType);
    virtual void setTargetMagnesiumLevel(QString level);
    virtual void setTargetMagnesiumLevelType(char levelType);
    virtual void setCurrentCalciumLevel(QString level);
    virtual void setCurrentCalciumLevelType(char levelType);
    virtual void setCurrentAlkalinityLevel(QString level);
    virtual void setCurrentAlkalinityLevelType(char levelType);
    virtual void setCurrentMagnesiumLevel(QString level);
    virtual void setCurrentMagnesiumLevelType(char levelType);
    virtual void setShowAdviceToogle(bool enable);

    virtual QString getTargetWaterVol();
    virtual char getTargetWaterVolType();
    virtual QString getTargetCalciumLevel();
    virtual char getTargetCalciumLevelType();
    virtual QString getTargetAlkalinityLevel();
    virtual char getTargetAlkalinityLevelType();
    virtual QString getTargetMagnesiumLevel();
    virtual char getTargetMagnesiumLevelType();
    virtual QString getCurrentCalciumLevel();
    virtual char getCurrentCalciumLevelType();
    virtual QString getCurrentAlkalinityLevel();
    virtual char getCurrentAlkalinityLevelType();
    virtual QString getCurrentMagnesiumLevel();
    virtual char getCurrentMagnesiumLevelType();
    virtual bool getShowAdviceToogle();

    virtual void setTitle(QString title)=0;

signals:
    void saveBtnClicked();
    void backBtnClicked();

public slots:

protected:
    QStringListModel* waterVolModel;
    QStringListModel* alkModel;
    QStringListModel* caModel;
    QLineEdit* waterVolEdit;
    QComboBox* waterVolCombo;
    QLineEdit* targetCalciumEdit;
    QComboBox* targetCalciumCombo;
    QLineEdit* targetAlkalinityEdit;
    QComboBox* targetAlkalinityCombo;
    QLineEdit* targetMagnesiumEdit;
    QComboBox* targetMagnesiumCombo;
    QLineEdit* currentCalciumEdit;
    QComboBox* currentCalciumCombo;
    QLineEdit* currentAlkalinityEdit;
    QComboBox* currentAlkalinityCombo;
    QLineEdit* currentMagnesiumEdit;
    QComboBox* currentMagnesiumCombo;
    QCheckBox* showDosageCheck;

private slots:
    void handleSaveBtnClicked();
    void handleBackBtnClicked();
    void handleDosageCheckClicked();
};

#endif // EDITRECORDVIEW_H
