#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "logrecord.h"
#include "parameters.h"
#include <QObject>
#include <QList>
#include "volume.h"
#include <QSharedPointer>
#include <QString>

#define PAquarium QSharedPointer<Aquarium>

class Aquarium : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PParameters targetParameters READ getTargetParameters)
    Q_PROPERTY(PVolume waterVolume READ getWaterVolume)

public:
    Aquarium(int id);

    void addLogRecord(PLogRecord record);
    void deleteLogRecord(PLogRecord record);
    PParameters getTargetParameters();
    QList<PLogRecord > getLogHistory();
    PVolume getWaterVolume();
    void setWaterVolume(PVolume volume);
    QString getName();
    int getId();
    void remove();

    static PAquarium newAquarium();
    static QList<PAquarium> listAquariums();

private:
    int _id;
    PParameters _targetParameters;
    PVolume _waterVolume;
};

#endif // AQUARIUM_H
