#ifndef LEVELTYPE_H
#define LEVELTYPE_H

#include <QSharedPointer>

#define PLevelType QSharedPointer<LevelType>

class LevelType
{
public:
    LevelType();

    virtual qreal convertToPPM(qreal value)=0;
    virtual qreal convertFromPPM(qreal value)=0;
    virtual QString getKey()=0;
    virtual QString getName()=0;
    static PLevelType createLevelTypeFromKey(QString key);
};

#endif // LEVELTYPE_H
