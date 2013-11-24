#ifndef CALCIUMLEVEL_H
#define CALCIUMLEVEL_H

#include "level.h"

class CalciumLevel : public Level
{
public:
    CalciumLevel();
    QList<PLevelType > listPossibleLevelTypes();
    PDosage adjust(Additive &additive, Volume &volume, PLevel targetLevel);
    QList<PAdditive > listPossibleAdditives();
    QString toString();
};

#endif // CALCIUMLEVEL_H
