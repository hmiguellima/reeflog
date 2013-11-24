#ifndef GRAMUNITTYPE_H
#define GRAMUNITTYPE_H

#include "unittype.h"

class GramUnitType : public UnitType
{
public:
    GramUnitType();
    QString getName();
    QString getDosage(qreal value);
    QString getDosageName();
};

#endif // GRAMUNITTYPE_H
