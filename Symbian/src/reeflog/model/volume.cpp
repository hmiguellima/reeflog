#include "volume.h"

Volume::Volume()
{
}

qreal Volume::getValue()
{
    return _value;
}

QSharedPointer<VolumeType> Volume::getVolumeType()
{
    return _volumeType;
}

void Volume::setVolumeType(QSharedPointer<VolumeType> volType)
{
    _volumeType=volType;
}

void Volume::setValue(qreal value)
{
    _value=value;
}

QString Volume::toString()
{
    return QString("Volume: %0 %1").arg(_value, 2).arg(_volumeType->getName());
}
