#include "view.h"
#include <QTimer>
#include <QWidget>
#include <QSound>

View::View(Screen *parent) :
    QFrame(parent)
{
    setFrameStyle(QFrame::NoFrame);
}

void View::askFocus()
{
    QTimer::singleShot(500, this, SLOT(askFocusNow()));
}

void View::askFocusNow()
{
    focusNextChild();
}

void View::playBtnSound()
{
}
