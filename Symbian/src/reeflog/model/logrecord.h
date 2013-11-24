#ifndef LOGRECORD_H
#define LOGRECORD_H

#include <QObject>
#include <QDateTime>
#include <QVariant>
#include <QSharedPointer>
#include "parameters.h"
#include <QList>

#define PLogRecord QSharedPointer<LogRecord>

class LogRecord : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PParameters parameters READ getParameters)
    Q_PROPERTY(QDateTime date READ getDate WRITE setDate)
public:
    LogRecord(int id=0);

    PParameters getParameters();
    QDateTime getDate();
    void setDate(QDateTime date);
    int getId();
    void setAquariumId(int aquariumId);
    int getAquariumid();
    static QList<PLogRecord > listRecords(int aquariumId);
    void save();
    void remove();


private:
    int _id;
    int _aquariumId;
    QDateTime _date;
    PParameters _parameters;
};

#endif // LOGRECORD_H
