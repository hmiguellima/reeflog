#include "ppmleveltype.h"

PpmLevelType::PpmLevelType()
{
}

qreal PpmLevelType::convertToPPM(qreal value)
{
    return value;
}

qreal PpmLevelType::convertFromPPM(qreal value)
{
    return value;
}

QString PpmLevelType::getKey()
{
    return "P";
}

QString PpmLevelType::getName()
{
    return "PPM";
}
