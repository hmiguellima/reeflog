#include "magnesiumlevel.h"
#include "ppmleveltype.h"
#include "additive.h"

MagnesiumLevel::MagnesiumLevel() : Level()
{
    setLevelType(PLevelType(new PpmLevelType()));
}

QList<PLevelType > MagnesiumLevel::listPossibleLevelTypes()
{
    QList<PLevelType > types;

    types.append(PLevelType(new PpmLevelType()));

    return types;
}

PDosage MagnesiumLevel::adjust(Additive &additive, Volume &volume, QSharedPointer<Level> targetLevel)
{
    return additive.calcDosage(volume, PLevel(this), targetLevel);
}

QList<PAdditive > MagnesiumLevel::listPossibleAdditives()
{
    return Additive::listAdditives("M");
}

QString MagnesiumLevel::toString()
{
    return "Mg: "+QString::number(getValue())+ " " + getLevelType()->getName();
}
