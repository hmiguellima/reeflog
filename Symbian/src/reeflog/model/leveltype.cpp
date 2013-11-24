#include "leveltype.h"
#include "ppmleveltype.h"
#include "dkhleveltype.h"
#include "meqleveltype.h"

LevelType::LevelType()
{
}

QSharedPointer<LevelType> LevelType::createLevelTypeFromKey(QString key)
{
    switch (key.at(0).toAscii())
    {
    case 'P':
        return PLevelType(new PpmLevelType());
    case 'D':
        return PLevelType(new DkhLevelType());
    case 'M':
        return PLevelType(new MeqLevelType());
    default:
        return PLevelType(NULL);
    }

}
