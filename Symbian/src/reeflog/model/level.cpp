#include "level.h"
#include "additive.h"

Level::Level()
{
    _value = 0.0;
}

qreal Level::getValue()
{
    return this->_value;
}

QSharedPointer<LevelType> Level::getLevelType()
{
    return _levelType;
}

void Level::setValue(qreal value)
{
    this->_value=value;
}

void Level::setLevelType(QSharedPointer<LevelType> levelType)
{
    this->_levelType=levelType;
}

qreal Level::getPPM()
{
    return getLevelType()->convertToPPM(_value);
}
