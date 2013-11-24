#ifndef EDITRECORDVERTICALVIEW_H
#define EDITRECORDVERTICALVIEW_H

#include "editrecordview.h"
#include <QLabel>

class EditRecordVerticalView : public EditRecordView
{
public:
    EditRecordVerticalView(Screen *parent = 0);

    void setTitle(QString title);

private:
    QLabel* titleLabel;
};

#endif // EDITRECORDVERTICALVIEW_H
