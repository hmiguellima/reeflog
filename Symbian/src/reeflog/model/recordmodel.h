#ifndef RECORDMODEL_H
#define RECORDMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include "logrecord.h"
#include <QList>
#include <QSharedPointer>

#define PRecordModel QSharedPointer<RecordModel>

class RecordModel : public QAbstractItemModel
{
public:
    Q_OBJECT

public:
    enum RecordRoles {
        DateRole = Qt::UserRole + 1,
        CalciumRole,
        AlkalinityRole,
        MagnesiumRole
    };

    RecordModel(QObject *parent=0);
    ~RecordModel();

    QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    QModelIndex parent ( const QModelIndex & index ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
    PLogRecord getRecordAt(int row);

    void setLogData(QList<PLogRecord > data);
    void recordInserted();

private:
    QList<PLogRecord > _data;
};

#endif // RECORDMODEL_H
