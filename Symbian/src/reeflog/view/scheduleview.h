#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include "view.h"
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QStringListModel>
#include <QDateEdit>
#include <QLineEdit>

class ScheduleView : public View
{
    Q_OBJECT
public:
    ScheduleView(Screen* parent);

    virtual void setProductName(QString product);
    virtual void setDosageAmount(QString amount);
    virtual void setDosageAdvice(QString advice);
    virtual void setStartDate(QDate date);
    virtual QDate getStartDate();
    virtual void setInterval(int days);
    virtual int getInterval();
    virtual void setDailyDosageAmount(QString amount);
    void showAlarmSetMsg();
    void showNoAlarmSetMsg();


signals:
    void scheduleBtnClicked();
    void backBtnClicked();
    void intervalChanged(int days);

private slots:
    void handleScheduleBtnClicked();
    void handleBackBtnClicked();
    void handleIntervalChanged(QString interval);

protected:
    QPushButton* scheduleBtn;
    QPushButton* cancelBtn;
    QLabel* productLbl;
    QLabel* amountLbl;
    QLabel* adviceLbl;
    QDateEdit* startDateEdit;
    QLineEdit* intervalEdit;
    QLabel* dailyAmountLbl;
};

#endif // SCHEDULEVIEW_H
