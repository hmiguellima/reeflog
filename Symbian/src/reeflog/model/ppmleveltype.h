#ifndef PPMLEVELTYPE_H
#define PPMLEVELTYPE_H

#include "leveltype.h"

class PpmLevelType : public LevelType
{
public:
    PpmLevelType();

    qreal convertToPPM(qreal value);
    qreal convertFromPPM(qreal value);
    QString getKey();
    QString getName();
};

#endif // PPMLEVELTYPE_H
