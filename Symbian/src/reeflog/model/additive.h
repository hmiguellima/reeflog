#ifndef ADDITIVE_H
#define ADDITIVE_H

#include <QString>
#include "dosage.h"
#include "volume.h"
#include "level.h"
#include <QList>
#include <QObject>
#include <QSharedPointer>

#define PAdditive QSharedPointer<Additive>

class Additive : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal factor READ getFactor)
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QString instructions READ getInstructions)

public:
    Additive();

    PDosage calcDosage(Volume& waterVolume, PLevel sourceLevel, PLevel destLevel);
    qreal getFactor();
    QString getName();
    QString getInstructions();
    static QList<PAdditive > listAdditives(QString levelName);

private:
    QString _name;
    QString _instructions;
    qreal _factor;
    QString _unitType;
};

#endif // ADDITIVE_H
