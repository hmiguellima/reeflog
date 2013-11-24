#include "litresvolumetype.h"

LitresVolumeType::LitresVolumeType()
{
}

qreal LitresVolumeType::convertToLitres(qreal value)
{
    return value;
}

qreal LitresVolumeType::convertFromLitres(qreal value)
{
    return value;
}

QString LitresVolumeType::getName()
{
    return "Litres";
}

QString LitresVolumeType::getDosage(qreal value)
{
    return "";
}

char LitresVolumeType::getKey()
{
    return 'L';
}

QString LitresVolumeType::getDosageName()
{
    return "ml";
}
