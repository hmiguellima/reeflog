#include "aquarium.h"
#include <QDateTime>
#include <QSqlQuery>
#include "alkalinitylevel.h"
#include "magnesiumlevel.h"
#include "calciumlevel.h"

Aquarium::Aquarium(int id) : _id(id)
{
    QSqlQuery query;
    QString sql;

    sql = "select aqu_water_volume, aqu_water_volume_type, aqu_fk_target_parameters_id from Aquarium "
          " where aqu_pk_id="+QString::number(_id);
    query.exec(sql);
    query.next();

    _waterVolume=PVolume(new Volume());
    _waterVolume->setValue(query.value(0).toReal());
    _waterVolume->setVolumeType(VolumeType::createFromKey(query.value(1).toString()));

    _targetParameters=PParameters(new Parameters(query.value(2).toInt()));
    _targetParameters->load();
}

void Aquarium::addLogRecord(QSharedPointer<LogRecord> record)
{
    record->setAquariumId(_id);
    record->save();
}

QSharedPointer<Parameters> Aquarium::getTargetParameters()
{
    return _targetParameters;
}

QList<QSharedPointer<LogRecord> > Aquarium::getLogHistory()
{
    return LogRecord::listRecords(_id);
}

void Aquarium::deleteLogRecord(QSharedPointer<LogRecord> record)
{
    record->remove();
}

QSharedPointer<Volume> Aquarium::getWaterVolume()
{
    return _waterVolume;
}

void Aquarium::setWaterVolume(QSharedPointer<Volume> volume)
{
    QSqlQuery query;

    _waterVolume=volume;

    query.prepare("update Aquarium "
                  "set aqu_water_volume=:aqu_water_volume,"
                  "aqu_water_volume_type=:aqu_water_volume_type "
                  "where aqu_pk_id="+QString::number(_id));

    query.bindValue(":aqu_water_volume", QVariant(volume->getValue()));
    query.bindValue(":aqu_water_volume_type", QVariant(QString(volume->getVolumeType()->getKey())));
    query.exec();
}

QString Aquarium::getName()
{
    return "Reef #"+QString::number(_id);
}

void Aquarium::remove()
{
    QSqlQuery query;
    PLogRecord record;
    QList<PLogRecord > logHistory;

    logHistory=getLogHistory();
    if (_id!=1) {
        foreach(record, logHistory)
            record->remove();
        _targetParameters->remove();

        query.exec("delete from Aquarium where aqu_pk_id="+QString::number(_id));
    }
}

QSharedPointer<Aquarium> Aquarium::newAquarium()
{
    QSqlQuery query;
    int newId;
    Parameters params;

    query.prepare("select max(aqu_pk_id)+1 from Aquarium");
    query.exec();
    query.next();
    newId=query.value(0).toInt();

    params.save();

    query.prepare("insert into Aquarium values(:id,0,'L',:params)");
    query.bindValue(":id", newId);
    query.bindValue(":params", params.getId());

    query.exec();

    return PAquarium(new Aquarium(newId));
}

QList<QSharedPointer<Aquarium> > Aquarium::listAquariums()
{
    QList<PAquarium > aquaList;
    QSqlQuery query;


    query.prepare("select aqu_pk_id from Aquarium order by aqu_pk_id");
    query.exec();

    while (query.next()) {
        aquaList.append(PAquarium(new Aquarium(query.value(0).toInt())));
    }

    return aquaList;
}

int Aquarium::getId()
{
    return _id;
}
