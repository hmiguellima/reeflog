#ifndef VOLUMETYPE_H
#define VOLUMETYPE_H

#include "unittype.h"
#include <QString>
#include <QSharedPointer>
#include <QList>

#define PVolumeType QSharedPointer<VolumeType>

class VolumeType : public UnitType
{
public:
    VolumeType();
    virtual qreal convertToLitres(qreal value)=0;
    virtual qreal convertFromLitres(qreal value)=0;
    virtual char getKey()=0;

    static PVolumeType createFromKey(QString key);
    static QList<PVolumeType > listTypes();
};

#endif // VOLUMETYPE_H
