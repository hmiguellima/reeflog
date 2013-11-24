#include "calciumlevel.h"
#include "ppmleveltype.h"
#include "additive.h"

CalciumLevel::CalciumLevel() : Level()
{
    setLevelType(PLevelType(new PpmLevelType()));
}

QList<PLevelType > CalciumLevel::listPossibleLevelTypes()
{
    QList<PLevelType > types;

    types.append(PLevelType(new PpmLevelType()));

    return types;
}

PDosage CalciumLevel::adjust(Additive &additive, Volume &volume, QSharedPointer<Level> targetLevel)
{
    return additive.calcDosage(volume, PLevel(this), targetLevel);
}

QList<PAdditive > CalciumLevel::listPossibleAdditives()
{
    return Additive::listAdditives("C");
}

QString CalciumLevel::toString()
{
    return "Ca: "+QString::number(getValue())+ " " + getLevelType()->getName();
}
