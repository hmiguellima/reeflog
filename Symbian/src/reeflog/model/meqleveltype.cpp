#include "meqleveltype.h"

MeqLevelType::MeqLevelType()
{
}

qreal MeqLevelType::convertToPPM(qreal value)
{
    return value*50;
}

qreal MeqLevelType::convertFromPPM(qreal value)
{
    return value/50;
}

QString MeqLevelType::getKey()
{
    return "M";
}

QString MeqLevelType::getName()
{
    return "Meq/L";
}
