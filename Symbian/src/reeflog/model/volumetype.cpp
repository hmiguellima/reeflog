#include "volumetype.h"
#include "litresvolumetype.h"
#include "usgallonsvolumetype.h"
#include "imperialgallonsvolumetype.h"

VolumeType::VolumeType() : UnitType()
{
}

QSharedPointer<VolumeType> VolumeType::createFromKey(QString key)
{
    switch (key.at(0).toAscii())
    {
    case 'L':
        return PVolumeType(new LitresVolumeType());
    case 'G':
        return PVolumeType(new USGallonsVolumeType());
    case 'I':
        return PVolumeType(new ImperialGallonsVolumeType());
    default:
        return PVolumeType(NULL);
    }
}

QList<QSharedPointer<VolumeType> > VolumeType::listTypes()
{
    QList<QSharedPointer<VolumeType> > list;

    list.append(PVolumeType(new LitresVolumeType()));
    list.append(PVolumeType(new USGallonsVolumeType()));
    list.append(PVolumeType(new ImperialGallonsVolumeType()));

    return list;
}
