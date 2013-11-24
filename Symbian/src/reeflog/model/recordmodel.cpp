#include "recordmodel.h"

RecordModel::RecordModel(QObject *parent): QAbstractItemModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[DateRole] = "date";
    roles[CalciumRole] = "calcium";
    roles[AlkalinityRole] = "alkalinity";
    roles[MagnesiumRole] = "magnesium";
    setRoleNames(roles);
}

RecordModel::~RecordModel()
{

}

QModelIndex RecordModel::index ( int row, int column, const QModelIndex & parent ) const
{
    return createIndex(row, column, row);
}

QModelIndex RecordModel::parent ( const QModelIndex & index ) const
{
    return QModelIndex();
}

int RecordModel::columnCount ( const QModelIndex & parent ) const
{
    return 1;
}


int RecordModel::rowCount(const QModelIndex& parent) const
{
    if (_data.size()>0)
        return _data.size();
    else
        return 1;
}

QVariant RecordModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || (_data.size()==0) )
        return QVariant();

    switch (role)
    {
    case DateRole:
        return (_data)[index.row()]->getDate().date().toString(Qt::SystemLocaleShortDate)+"    "+(_data)[index.row()]->getDate().time().toString("hh:mm");
    case CalciumRole:
        return (_data)[index.row()]->getParameters()->getCalcium()->toString();
    case AlkalinityRole:
        return (_data)[index.row()]->getParameters()->getAlkalinity()->toString();
    case MagnesiumRole:
        return (_data)[index.row()]->getParameters()->getMagnesium()->toString();

    default:
        return QVariant();
    }

}

void RecordModel::setLogData(QList<QSharedPointer<LogRecord> > data)
{
    this->_data=data;
    reset();
}

void RecordModel::recordInserted()
{
    reset();
}

QSharedPointer<LogRecord> RecordModel::getRecordAt(int row)
{
    return _data.at(row);
}

