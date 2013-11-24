#ifndef VOLUME_H
#define VOLUME_H

#include "volumetype.h"
#include <QObject>
#include <QSharedPointer>
#include <QString>

#define PVolume QSharedPointer<Volume>

class Volume : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal value READ getValue)
    Q_PROPERTY(PVolumeType volumeType READ getVolumeType)
public:
    Volume();
    void setValue(qreal value);
    qreal getValue();
    void setVolumeType(PVolumeType volType);
    PVolumeType getVolumeType();
    QString toString();

private:
    qreal _value;
    PVolumeType _volumeType;
};

#endif // VOLUME_H
