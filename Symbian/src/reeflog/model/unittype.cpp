#include "unittype.h"
#include "gramunittype.h"
#include "litresvolumetype.h"

UnitType::UnitType(QObject *parent) :
    QObject(parent)
{
}

QSharedPointer<UnitType> UnitType::getUnitType(QString name)
{
    switch (name.at(0).toAscii())
    {
    case 'L':
        return PUnitType(new LitresVolumeType());
    case 'G':
        return PUnitType(new GramUnitType());
    default:
        return PUnitType(NULL);
    }
}

QString UnitType::getDosageName()
{
    return "";
}
