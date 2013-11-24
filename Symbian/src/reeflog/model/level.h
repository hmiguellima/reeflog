#ifndef LEVEL_H
#define LEVEL_H

#include <QList>
#include "leveltype.h"
#include "volume.h"
#include "dosage.h"
#include <QSharedPointer>
#include <QObject>
#include <QString>

class Additive;

#define PLevel QSharedPointer<Level>
#ifndef PAdditive
#define PAdditive QSharedPointer<Additive>
#endif

class Level : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal value READ getValue WRITE setValue)
    Q_PROPERTY(PLevelType levelType READ getLevelType WRITE setLevelType)

public:
    Level();
    virtual QList<PLevelType > listPossibleLevelTypes()=0;
    virtual PDosage adjust(Additive &additive, Volume &volume, PLevel targetLevel)=0;
    virtual QList<PAdditive > listPossibleAdditives()=0;
    qreal getValue();
    PLevelType getLevelType();
    void setValue(qreal value);
    void setLevelType(PLevelType levelType);
    virtual QString toString()=0;
    qreal getPPM();

private:
    qreal _value;
    PLevelType _levelType;
};

#endif // LEVEL_H
