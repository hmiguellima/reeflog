#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPixmap>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    SplashScreen();
    ~SplashScreen();
private:
    QPixmap *pixmap;
};

#endif // SPLASHSCREEN_H
