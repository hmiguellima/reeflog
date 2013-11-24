#include "splashscreen.h"

SplashScreen::SplashScreen() : QSplashScreen()
{
    pixmap=new QPixmap(QString::fromUtf8(":/resources/resources/splash_vertical.png"));
    setPixmap(*pixmap);
}

SplashScreen::~SplashScreen()
{
    delete pixmap;
}
