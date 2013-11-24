#include "alkalinitylevel.h"
#include "dkhleveltype.h"
#include "ppmleveltype.h"
#include "meqleveltype.h"
#include "additive.h"

AlkalinityLevel::AlkalinityLevel() : Level()
{
    setLevelType(PLevelType(new DkhLevelType()));
}

QList<PLevelType > AlkalinityLevel::listPossibleLevelTypes()
{
    QList<PLevelType > levels;

    levels.append(PLevelType(new DkhLevelType()));
    levels.append(PLevelType(new PpmLevelType()));
    levels.append(PLevelType(new MeqLevelType()));

    return levels;
}

PDosage AlkalinityLevel::adjust(Additive &additive, Volume &volume, PLevel targetLevel)
{
    return additive.calcDosage(volume, PLevel(this), targetLevel);
}

QList<PAdditive > AlkalinityLevel::listPossibleAdditives()
{
    return Additive::listAdditives("A");
}

QString AlkalinityLevel::toString()
{
    return "Alk: "+QString::number(getValue())+ " " + getLevelType()->getName();
}
