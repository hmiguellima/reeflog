#include "logrecord.h"
#include <QSqlQuery>
#include <QDebug>

LogRecord::LogRecord(int id) : _id(id)
{
    _parameters=PParameters(new Parameters());
}

PParameters LogRecord::getParameters()
{
    return _parameters;
}

QDateTime LogRecord::getDate()
{
    return _date;
}

void LogRecord::setDate(QDateTime date)
{
    _date=date;
}

void LogRecord::setAquariumId(int aquariumId)
{
    _aquariumId = aquariumId;
}

int LogRecord::getId()
{
    return _id;
}

int LogRecord::getAquariumid()
{
    return _aquariumId;
}

QList<QSharedPointer<LogRecord> > LogRecord::listRecords(int aquariumId)
{
    QSqlQuery query;
    QString sql;
    QList<PLogRecord > history;
    PLogRecord record;
    PParameters parameters;

    sql = "select log_pk_id, log_date , log_fk_parameters_id from LogRecord where log_fk_aquarium_id="+QString::number(aquariumId)+" order by log_pk_id desc";
    query.exec(sql);

    while (query.next())
    {
        record=PLogRecord(new LogRecord(query.value(0).toInt()));
        record->_aquariumId=aquariumId;
        record->_date=QDateTime::fromString(query.value(1).toString(), QString("yyyy-MM-dd hh:mm"));

        parameters=PParameters(new Parameters(query.value(2).toInt()));
        parameters->load();

        record->_parameters = parameters;

        history.append(record);
    }

    return history;
}

void LogRecord::save()
{
    QSqlQuery query;
    QString sql;
    int recordId=0;

    if (_id==0)
    {
        _parameters->save();

        query.exec("select max(log_pk_id) from LogRecord");
        if (query.next());
            recordId=query.value(0).toInt()+1;

        sql = "insert into LogRecord values("+
                QString::number(recordId)+","+
                QString::number(_aquariumId)+","+
                "'"+_date.toString("yyyy-MM-dd hh:mm")+"',"+
                QString::number(_parameters->getId())+")";
        query.exec(sql);
        _id=recordId;
    }
    else
    {
        _parameters->save();
    }
}

void LogRecord::remove()
{
    QSqlQuery query;
    QString sql;

    _parameters->remove();
    sql="delete from LogRecord where log_pk_id="+QString::number(_id);

    query.exec(sql);
}
