#ifndef DOSAGE_H
#define DOSAGE_H

#include <QObject>
#include <QString>
#include <QSharedPointer>
#include "unittype.h"

#define PDosage QSharedPointer<Dosage>

class Dosage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal value READ getValue)

public:
    Dosage(qreal value, QString unitType);

    qreal getValue();
    PUnitType getUnitType();
    void schedule(int days);
    QString getDailyDosageAmount(int days);
    QString toString();
private:
    qreal _value;
    PUnitType _unitType;
};

#endif // DOSAGE_H
