#include "parameters.h"
#include "calciumlevel.h"
#include "alkalinitylevel.h"
#include "magnesiumlevel.h"
#include <QSqlQuery>
#include <QVariant>

Parameters::Parameters(int id)
{
    _id=id;
    _calcium=PLevel(new CalciumLevel());
    _alkalinity=PLevel(new AlkalinityLevel());
    _magnesium=PLevel(new MagnesiumLevel());
}

QSharedPointer<Level> Parameters::getCalcium()
{
    return _calcium;
}

QSharedPointer<Level> Parameters::getAlkalinity()
{
    return _alkalinity;
}

QSharedPointer<Level> Parameters::getMagnesium()
{
    return _magnesium;
}

int Parameters::getId()
{
    return _id;
}

void Parameters::setCalcium(QSharedPointer<Level> calcium)
{
    _calcium=calcium;
}

void Parameters::setAlkalinity(QSharedPointer<Level> alkalinity)
{
    _alkalinity=alkalinity;
}

void Parameters::setMagnesium(QSharedPointer<Level> magnesium)
{
    _magnesium=magnesium;
}

void Parameters::save()
{
    QSqlQuery query;
    int paramId=1;
    QString sql;

    if (_id==0)
    {
        query.exec("select max(par_pk_id) from Parameters");
        if (query.next());
            paramId=query.value(0).toInt()+1;

        sql = "insert into Parameters values("+
                QString::number(paramId)+","+
                QString::number(_alkalinity->getValue())+","+
                "'"+_alkalinity->getLevelType()->getKey()+"',"+
                QString::number(_calcium->getValue())+","+
                "'"+_calcium->getLevelType()->getKey()+"',"+
                QString::number(_magnesium->getValue())+","+
                "'"+_magnesium->getLevelType()->getKey()+"')";
        query.exec(sql);
        _id=paramId;
    }
    else
    {
        sql = "update Parameters set "
                " par_alk_level="+QString::number(_alkalinity->getValue())+","+
                " par_alk_level_type='"+_alkalinity->getLevelType()->getKey()+"',"+
                " par_ca_level="+QString::number(_calcium->getValue())+","+
                " par_ca_level_type='"+_calcium->getLevelType()->getKey()+"',"+
                " par_mg_level="+QString::number(_magnesium->getValue())+","+
                " par_mg_level_type='"+_magnesium->getLevelType()->getKey()+"'"+
                " where par_pk_id="+QString::number(_id);

        query.exec(sql);
    }
}

void Parameters::load()
{
    QSqlQuery query;
    QString sql;
    PLevel alkLevel=PLevel(new AlkalinityLevel());
    PLevel magLevel=PLevel(new MagnesiumLevel());
    PLevel caLevel=PLevel(new CalciumLevel());

    sql = "select par_alk_level , par_alk_level_type, par_ca_level, par_ca_level_type, par_mg_level, par_mg_level_type from Parameters where par_pk_id="+QString::number(_id);
    query.exec(sql);
    query.next();

    alkLevel->setValue(query.value(0).toReal());
    alkLevel->setLevelType(LevelType::createLevelTypeFromKey(query.value(1).toString()));

    caLevel->setValue(query.value(2).toReal());
    caLevel->setLevelType(LevelType::createLevelTypeFromKey(query.value(3).toString()));

    magLevel->setValue(query.value(4).toReal());
    magLevel->setLevelType(LevelType::createLevelTypeFromKey(query.value(5).toString()));

    setAlkalinity(alkLevel);
    setCalcium(caLevel);
    setMagnesium(magLevel);
}

void Parameters::remove()
{
    QSqlQuery query;
    QString sql;

    sql="delete from Parameters where par_pk_id="+QString::number(_id);
    query.exec(sql);
}

QString Parameters::toString(QString label)
{
    return QString("%0: %1 %2 %3").arg(label).arg(_calcium->toString()).arg(_alkalinity->toString()).arg(_magnesium->toString());
}
