#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <QObject>
#include <QString>
#include <QSharedPointer>

#define PUnitType QSharedPointer<UnitType>

class UnitType : public QObject
{
public:
    explicit UnitType(QObject *parent = 0);

    virtual QString getName()=0;
    virtual QString getDosage(qreal value)=0;
    virtual QString getDosageName();
    static PUnitType getUnitType(QString name);
};

#endif // UNITTYPE_H
