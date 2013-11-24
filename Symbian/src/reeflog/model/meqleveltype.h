#ifndef MEQLEVELTYPE_H
#define MEQLEVELTYPE_H

#include "leveltype.h"

class MeqLevelType : public LevelType
{
public:
    MeqLevelType();

    qreal convertToPPM(qreal value);
    qreal convertFromPPM(qreal value);
    QString getKey();
    QString getName();
};

#endif // MEQLEVELTYPE_H
