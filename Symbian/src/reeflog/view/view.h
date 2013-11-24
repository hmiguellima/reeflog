#ifndef VIEW_H
#define VIEW_H

#include "controller/screen.h"
#include <QFrame>

class View : public QFrame
{
    Q_OBJECT
public:
    explicit View(Screen *parent = 0);

signals:

public slots:
    void askFocus();
    void askFocusNow();
    void playBtnSound();
};

#endif // VIEW_H
