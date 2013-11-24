#include "imperialgallonsvolumetype.h"

ImperialGallonsVolumeType::ImperialGallonsVolumeType()
{
}

qreal ImperialGallonsVolumeType::convertToLitres(qreal value)
{
    return value;
}

qreal ImperialGallonsVolumeType::convertFromLitres(qreal value)
{
    return value;
}

QString ImperialGallonsVolumeType::getName()
{
    return "Imperial";
}

QString ImperialGallonsVolumeType::getDosage(qreal value)
{
    return "";
}

char ImperialGallonsVolumeType::getKey()
{
    return 'I';
}
