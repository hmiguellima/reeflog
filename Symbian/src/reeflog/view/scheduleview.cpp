#include "scheduleview.h"
#include <QMessageBox>

ScheduleView::ScheduleView(Screen* parent) : View(parent)
{
    scheduleBtn=new QPushButton("");
    cancelBtn=new QPushButton("");
    productLbl=new QLabel("");
    amountLbl=new QLabel("");
    adviceLbl=new QLabel("");
    startDateEdit=new QDateEdit();
    intervalEdit=new QLineEdit();
    dailyAmountLbl=new QLabel("");
}

void ScheduleView::setProductName(QString product)
{
    productLbl->setText(product);
}

void ScheduleView::setDosageAmount(QString amount)
{
    amountLbl->setText(amount);
}

void ScheduleView::setDosageAdvice(QString advice)
{
    adviceLbl->setText(advice);
}

void ScheduleView::setStartDate(QDate date)
{
    startDateEdit->setDate(date);
}

QDate ScheduleView::getStartDate()
{
    return startDateEdit->date();
}

void ScheduleView::setInterval(int days)
{
    intervalEdit->setText(QString::number(days));
}

int ScheduleView::getInterval()
{
    return QVariant(intervalEdit->text()).toInt();
}

void ScheduleView::setDailyDosageAmount(QString amount)
{
    dailyAmountLbl->setText("("+amount+")");
}

void ScheduleView::handleScheduleBtnClicked()
{
    emit scheduleBtnClicked();
}

void ScheduleView::handleBackBtnClicked()
{
    emit backBtnClicked();
}

void ScheduleView::handleIntervalChanged(QString interval)
{
    emit intervalChanged(QVariant(interval).toInt());
}

void ScheduleView::showAlarmSetMsg()
{
    QMessageBox::information(this, "Reef Calculator", "Dosage alarms set");
}

void ScheduleView::showNoAlarmSetMsg()
{
    QMessageBox::information(this, "Reef Calculator", "No alarms set (check start date");
}



