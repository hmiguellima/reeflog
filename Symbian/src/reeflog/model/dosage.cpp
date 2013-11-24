#include "dosage.h"
#include <QVariant>

Dosage::Dosage(qreal value, QString unitType)
{
    this->_unitType=UnitType::getUnitType(unitType);
    this->_value=value;
}

void Dosage::schedule(int days)
{
}

qreal Dosage::getValue()
{
    return _value;
}

PUnitType Dosage::getUnitType()
{
    return _unitType;
}

QString Dosage::toString()
{
    return QString("%0 %1").arg(QString::number(_value, 'f', 1)).arg(_unitType->getDosageName());
}

QString Dosage::getDailyDosageAmount(int days)
{
    qreal partDos=_value / days;
    return QString("%0 %1").arg(QString::number(partDos, 'f', 1)).arg(_unitType->getDosageName());
}
