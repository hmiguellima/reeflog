#ifndef MAGNESIUMLEVEL_H
#define MAGNESIUMLEVEL_H

#include "level.h"

class MagnesiumLevel : public Level
{
public:
    MagnesiumLevel();
    QList<PLevelType > listPossibleLevelTypes();
    PDosage adjust(Additive &additive, Volume &volume, PLevel targetLevel);
    QList<PAdditive > listPossibleAdditives();
    QString toString();
};

#endif // MAGNESIUMLEVEL_H
