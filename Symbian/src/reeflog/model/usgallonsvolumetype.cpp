#include "usgallonsvolumetype.h"

USGallonsVolumeType::USGallonsVolumeType()
{
}

qreal USGallonsVolumeType::convertToLitres(qreal value)
{
    return value*3.785;
}

qreal USGallonsVolumeType::convertFromLitres(qreal value)
{
    return value/3.785;
}

QString USGallonsVolumeType::getName()
{
    return "US Gallons";
}

QString USGallonsVolumeType::getDosage(qreal value)
{
    return "";
}

char USGallonsVolumeType::getKey()
{
    return 'G';
}
