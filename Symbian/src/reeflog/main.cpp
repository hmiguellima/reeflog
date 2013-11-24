#include <QtGui/QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QWidget>
#include <QTimer>
#include <QObject>
#include "mainwindow.h"
#include "global.h"
#include "splashscreen.h"
#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#endif

#define WAIT_MS 3500

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window;
    SplashScreen *splash;
    int execV;

    window=new MainWindow();
    splash=new SplashScreen();

    #ifdef Q_OS_SYMBIAN
        CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
        TRAPD(error,
            if (appUi) {
                // Lock application orientation into portrait
                appUi->SetOrientationL(CAknAppUi::EAppUiOrientationPortrait);
            }
        )
    #endif

    splash->setAttribute(Qt::WA_DeleteOnClose, true);
    splash->showFullScreen();
    splash->raise();
    qApp->processEvents();

    QTimer::singleShot(WAIT_MS, splash, SLOT(close()));
    QTimer::singleShot(WAIT_MS, window, SLOT(init()));

    execV=app.exec();

    if (window) delete window;

    return execV;
}

