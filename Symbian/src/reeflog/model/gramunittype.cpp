#include "gramunittype.h"

GramUnitType::GramUnitType()
{
}

QString GramUnitType::getName()
{
    return "Grams";
}

QString GramUnitType::getDosage(qreal value)
{
    return "sample dosage";
}

QString GramUnitType::getDosageName()
{
    return "gr";
}
