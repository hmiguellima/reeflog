#include "additive.h"
#include <QSqlQuery>
#include <QVariant>

Additive::Additive()
{
}

PDosage Additive::calcDosage(Volume& waterVolume, QSharedPointer<Level> sourceLevel, QSharedPointer<Level> destLevel)
{
    qreal value;
    qreal ppms;

    ppms = destLevel->getPPM()-sourceLevel->getPPM();
    value = _factor * ppms * waterVolume.getVolumeType()->convertToLitres(waterVolume.getValue());

    PDosage dosage=PDosage(new Dosage(value, _unitType));

    return dosage;
}

QList<PAdditive > Additive::listAdditives(QString levelName)
{
    QSqlQuery query;
    QList<PAdditive > additives;

    query.exec("select add_name, add_notes, add_factor, add_unit_type from Additive where add_parameter='"+levelName+"'");

    while (query.next())
    {
        PAdditive additive=PAdditive(new Additive());

        additive->_name = query.value(0).toString();
        additive->_instructions = query.value(1).toString();
        additive->_factor = query.value(2).toReal();
        additive->_unitType = query.value(3).toString();

        additives.append(additive);
    }

    return additives;

}

qreal Additive::getFactor()
{
    return _factor;
}

QString Additive::getName()
{
    return _name;
}

QString Additive::getInstructions()
{
    return _instructions;
}
