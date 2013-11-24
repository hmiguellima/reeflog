#ifndef DKHLEVELTYPE_H
#define DKHLEVELTYPE_H

#include "leveltype.h"

class DkhLevelType : public LevelType
{
public:
    DkhLevelType();

    qreal convertToPPM(qreal value);
    qreal convertFromPPM(qreal value);
    QString getKey();
    QString getName();
};

#endif // DKHLEVELTYPE_H
