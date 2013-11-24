#ifndef USGALLONSVOLUMETYPE_H
#define USGALLONSVOLUMETYPE_H

#include "volumetype.h"

class USGallonsVolumeType : public VolumeType
{
    Q_OBJECT
public:
    USGallonsVolumeType();
    qreal convertToLitres(qreal value);
    qreal convertFromLitres(qreal value);
    QString getName();
    QString getDosage(qreal value);
    char getKey();
};

#endif // USGALLONSVOLUMETYPE_H
