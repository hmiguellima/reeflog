#ifndef RECORDDELEGATE_H
#define RECORDDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyleOptionViewItemV4>
#include <QModelIndex>
#include <QPalette>
#include <QRect>
#include <QSize>

class RecordDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    RecordDelegate(QObject* parent);
    ~RecordDelegate();

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};

#endif // RECORDDELEGATE_H
