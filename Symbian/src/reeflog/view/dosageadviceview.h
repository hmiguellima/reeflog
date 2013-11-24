#ifndef DOSAGEADVICEVIEW_H
#define DOSAGEADVICEVIEW_H

#include "view.h"
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QStringListModel>

class DosageAdviceView : public View
{
    Q_OBJECT
public:
    DosageAdviceView(Screen* parent);

    virtual void setWaterVolume(QString volume);
    virtual void setDesiredParams(QString params);
    virtual void setCurrentParams(QString params);
    virtual void setCalciumAdditives(QStringListModel* additives);
    virtual void setAlkalinityAdditives(QStringListModel* additives);
    virtual void setMagnesiumAdditives(QStringListModel* additives);
    virtual void setCaDosageAdvice(QString advice);
    virtual void setCaDosageAmount(QString amount);
    virtual void setAlkDosageAdvice(QString advice);
    virtual void setAlkDosageAmount(QString amount);
    virtual void setMgDosageAdvice(QString advice);
    virtual void setMgDosageAmount(QString amount);
    virtual void showPanelByIndex(int index)=0;
    virtual int getVisiblePanelIndex()=0;
    virtual void setCaAdditiveIndex(int index);
    virtual int getCaAdditiveIndex();
    virtual void setAlkAdditiveIndex(int index);
    virtual int getAlkAdditiveIndex();
    virtual void setMgAdditiveIndex(int index);
    virtual int getMgAdditiveIndex();

signals:
    void calciumAdditiveSelected(int index);
    void alkalinityAdditiveSelected(int index);
    void magnesiumAdditiveSelected(int index);
    void scheduleCalciumClicked();
    void scheduleAlkalinityClicked();
    void scheduleMagnesiumClicked();
    void editParametersClicked();
    void okClicked();
    void backClicked();

private slots:
    void handleEditParams();
    void handleCalciumAdditiveSelected(int index);
    void handleAlkalinityAdditiveSelected(int index);
    void handleMagnesiumAdditiveSelected(int index);
    void handleScheduleCalcium();
    void handleScheduleAlkalinity();
    void handleScheduleMagnesium();
    void handleOk();
    void handleBack();

protected:
    QPushButton* editParmsBtn;
    QPushButton* scheduleCalciumBtn;
    QPushButton* scheduleAlkalinityBtn;
    QPushButton* scheduleMagnesiumBtn;
    QComboBox* calciumBox;
    QComboBox* alkalinityBox;
    QComboBox* magnesiumBox;
    QPushButton* okBtn;
    QPushButton* backBtn;
    QLabel* waterVolLbl;
    QLabel* desiredParamsLbl;
    QLabel* currentParamsLbl;
    QLabel* caDosageAdviceLbl;
    QLabel* caDosageAmountLbl;
    QLabel* alkDosageAdviceLbl;
    QLabel* alkDosageAmountLbl;
    QLabel* mgDosageAmountLbl;
    QLabel* mgDosageAdviceLbl;
};

#endif // DOSAGEADVICEVIEW_H
