#include "screen.h"
#include "mainwindow.h"
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

Screen::Screen(MainWindow* window) :
        QWidget(window)
{
    this->window=window;
    setAttribute(Qt::WA_ContentsPropagated);
}

MainWindow* Screen::getWindow()
{
    return window;
}

void Screen::show()
{
    window->showScreen(this);
    focusNextChild();
    showHandler();
}

bool Screen::isCurrent()
{
    if (window->getCurrentScreen()==this)
        return true;
    else
        return false;
}

