#ifndef MYITEMDELEGATE_H
#define MYITEMDELEGATE_H

#include <QRect>
#include <QStyledItemDelegate>
#include <QPainter>

class MyItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    MyItemDelegate(QObject* parent);
    ~MyItemDelegate();

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};
#endif // MYITEMDELEGATE_H
