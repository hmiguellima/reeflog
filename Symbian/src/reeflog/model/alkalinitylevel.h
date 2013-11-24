#ifndef ALKALINITYLEVEL_H
#define ALKALINITYLEVEL_H

#include "level.h"

class AlkalinityLevel : public Level
{
public:
    AlkalinityLevel();
    QList<PLevelType > listPossibleLevelTypes();
    PDosage adjust(Additive &additive, Volume &volume, PLevel targetLevel);
    QList<PAdditive > listPossibleAdditives();
    QString toString();
};

#endif // ALKALINITYLEVEL_H
