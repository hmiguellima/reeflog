#include "dkhleveltype.h"

DkhLevelType::DkhLevelType()
{
}

qreal DkhLevelType::convertToPPM(qreal value)
{
    return value*17.857;
}

qreal DkhLevelType::convertFromPPM(qreal value)
{
    return value*0.056;
}

QString DkhLevelType::getKey()
{
    return "D";
}

QString DkhLevelType::getName()
{
    return "dKH";
}
