#include "mycombobox.h"
#include <QDesktopWidget>
#include <QApplication>
#include "myitemdelegate.h"

MyComboBox::MyComboBox(QWidget *parent) :
    QComboBox(parent)
{
    MyItemDelegate *delegate=new MyItemDelegate(this);
    setAttribute(Qt::WA_StyledBackground);
    listView=new QListView(this);
    setView(listView);
    listView->setModel(model());
    view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    setItemDelegate(delegate);
}

