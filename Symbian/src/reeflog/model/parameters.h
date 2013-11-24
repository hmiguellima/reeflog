#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QObject>
#include "level.h"
#include <QSharedPointer>
#include <QString>

#define PParameters QSharedPointer<Parameters>

class Parameters : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PLevel calcium READ getCalcium WRITE setCalcium)
    Q_PROPERTY(PLevel alkalinity READ getAlkalinity WRITE setAlkalinity)
    Q_PROPERTY(PLevel magnesium READ getMagnesium WRITE setMagnesium)
    Q_PROPERTY(int id READ getId)
public:
    Parameters(int id=0);
    PLevel getCalcium();
    PLevel getAlkalinity();
    PLevel getMagnesium();
    int getId();
    void setCalcium(PLevel calcium);
    void setAlkalinity(PLevel alkalinity);
    void setMagnesium(PLevel magnesium);
    void save();
    void remove();
    void load();
    QString toString(QString label);

private:
    int _id;
    PLevel _calcium;
    PLevel _alkalinity;
    PLevel _magnesium;
};

#endif // PARAMETERS_H
