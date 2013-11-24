#ifndef IMPERIALGALLONSVOLUMETYPE_H
#define IMPERIALGALLONSVOLUMETYPE_H

#include "volumetype.h"

class ImperialGallonsVolumeType : public VolumeType
{
    Q_OBJECT
public:
    ImperialGallonsVolumeType();
    qreal convertToLitres(qreal value);
    qreal convertFromLitres(qreal value);
    QString getName();
    QString getDosage(qreal value);
    char getKey();
};

#endif // IMPERIALGALLONSVOLUMETYPE_H
