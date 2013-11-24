#include "myitemdelegate.h"

MyItemDelegate::MyItemDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{
}

MyItemDelegate::~MyItemDelegate()
{

}

void MyItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyleOptionViewItemV4 opt = option;
    initStyleOption(&opt, index);
    QFont font;
    QRect rect = opt.rect;
    QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;

    if (cg == QPalette::Normal && !(opt.state & QStyle::State_Active))
        cg = QPalette::Inactive;



    painter->save();

    font=QFont("helvetica");
    font.setPixelSize(30);
    painter->setPen(QColor(0, 0, 0));
    painter->setFont(font);

    painter->drawText(QRect(rect.left()+5, rect.top(), rect.width()-50, rect.height()),
                      Qt::AlignLeft | Qt::AlignVCenter, index.data().toString());

    painter->drawText(QRect(rect.left()+5, rect.top(), rect.width()-20, rect.height()),
                      Qt::AlignRight | Qt::AlignVCenter, ">");

    painter->setPen(QColor(0, 0, 0, 120));
    painter->drawLine(rect.bottomLeft(), rect.bottomRight());

    painter->restore();
}

QSize MyItemDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const {
    QSize result = QStyledItemDelegate::sizeHint(option, index);
    result.setHeight(40);
    return result;
}
