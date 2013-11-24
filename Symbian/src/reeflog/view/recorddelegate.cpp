#include "recorddelegate.h"
#include <QApplication>
#include <QFont>
#include "model/recordmodel.h"
#include <QDate>
#include <QStyleOptionButton>
#include <QStyle>
#include <QFontMetrics>
#include <QBrush>
#include <QStringList>

RecordDelegate::RecordDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{

}

RecordDelegate::~RecordDelegate()
{

}

void RecordDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyleOptionViewItemV4 opt = option;
    initStyleOption(&opt, index);
    int lineHeight;
    QString recordDate;
    QString calciumLevel;
    QString alkalinityLevel;
    QString magnesiumLevel;
    QFont font;
    int yPos;
    QStringList split;

    // draw correct background
    opt.text = "";
    //QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();
    //style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, opt.widget);

    QRect rect = opt.rect;
    QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
    if (cg == QPalette::Normal && !(opt.state & QStyle::State_Active))
        cg = QPalette::Inactive;

    // set pen color
    if (opt.state & QStyle::State_Selected)
        painter->setPen(opt.palette.color(cg, QPalette::HighlightedText));
    else
        painter->setPen(opt.palette.color(cg, QPalette::Text));


    lineHeight = rect.height()/5;

    painter->save();

    if (index.data(RecordModel::DateRole).isValid())
    {
        recordDate = index.data(RecordModel::DateRole).toString();
        calciumLevel = index.data(RecordModel::CalciumRole).toString();
        alkalinityLevel = index.data(RecordModel::AlkalinityRole).toString();
        magnesiumLevel = index.data(RecordModel::MagnesiumRole).toString();

        font=QFont("helvetica");
        font.setPixelSize(16);
        font.setBold(true);
        painter->setFont(font);
        painter->setPen(QPen(QColor(255,255,255,255)));

        painter->fillRect(QRect(rect.left()+4, rect.top()+10, 306, 30), QColor(0, 0, 0, 150));
        painter->drawText(QRect(rect.left()+14, rect.top()+10, rect.width()-10, 30),
                          opt.displayAlignment, recordDate);


        font=QFont("helvetica");
        painter->setFont(font);

        yPos=rect.top()+45;

        painter->fillRect(QRect(rect.left()+4, yPos-5, 306, 50), QColor(0, 0, 0, 100));

        font.setPixelSize(15);
        font.setBold(true);
        painter->setFont(font);
        painter->setPen(QPen(QColor(255, 255, 255)));

        //Calcium
        split=calciumLevel.split(' ');
        painter->drawText(QRect(rect.left()+10, yPos, 80, 20),
                          opt.displayAlignment, split[0]);
        painter->drawText(QRect(rect.left()+10, yPos+20, 80, 20),
                          opt.displayAlignment, split[1]+" "+split[2]);

        //Alkalinity
        split=alkalinityLevel.split(' ');
        painter->drawText(QRect(rect.left()+100, yPos, 80, 20),
                          opt.displayAlignment, split[0]);
        painter->drawText(QRect(rect.left()+100, yPos+20, 80, 20),
                          opt.displayAlignment, split[1]+" "+split[2]);

        //Magnesium
        split=magnesiumLevel.split(' ');
        painter->drawText(QRect(rect.left()+190, yPos, 80, 20),
                          opt.displayAlignment, split[0]);
        painter->drawText(QRect(rect.left()+190, yPos+20, 80, 20),
                          opt.displayAlignment, split[1]+" "+split[2]);


        font.setPixelSize(30);
        font.setBold(false);
        painter->setFont(font);
        painter->setPen(QPen(QColor(0,0,0,100)));
        painter->drawText(QRect(rect.left()+280, yPos+4, 30, 30),
                          opt.displayAlignment, ">");

        if (option.state & QStyle::State_HasFocus)
            painter->fillRect(QRect(rect.left()+4, rect.top()+10, 306, 80), QColor(255, 255, 255, 200));
    }
    else
    {
        font=QFont("helvetica");
        font.setPixelSize(30);
        painter->setFont(font);

        painter->drawText(QRect(rect.left(), rect.top(), rect.width()-10, lineHeight*2),
                          Qt::AlignHCenter | Qt::AlignVCenter, "<No records>");

    }

    painter->restore();
}

QSize RecordDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QSize result = QStyledItemDelegate::sizeHint(option, index);
    result.setHeight(90);
    return result;
}
