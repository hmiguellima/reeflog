#ifndef LITRESVOLUMETYPE_H
#define LITRESVOLUMETYPE_H

#include "volumetype.h"

class LitresVolumeType : public VolumeType
{
    Q_OBJECT
public:
    LitresVolumeType();
    qreal convertToLitres(qreal value);
    qreal convertFromLitres(qreal value);
    QString getName();
    QString getDosage(qreal value);
    QString getDosageName();
    char getKey();
};

#endif // LITRESVOLUMETYPE_H
