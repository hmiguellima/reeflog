#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QFile>
#include <QSqlQuery>
#include <QDateTime>
#include <QList>
#include <QSharedPointer>
#include <QMessageBox>
#include <QSqlError>
#include "eventbus.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QApplication>
#include "global.h"
#include <QDesktopServices>
#include <QUrl>
#ifdef Q_OS_SYMBIAN
    #include <eikenv.h>
    #include <eikappui.h>
    #include <aknenv.h>
    #include <aknappui.h>
#endif
#include <QLocale>
#include <QSharedPointer>
#include <QTextStream>

#define DB_FILE_NAME "reeflog.db"
#define HELP_URI "http://www.hlimasoft.com/reeflog/help"
#define UPDATE_URI "http://www.hlimasoft.com/reeflog/update"

MainWindow* MainWindow::instance;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
#ifdef Q_OS_SYMBIAN
    appDataPath = QApplication::applicationDirPath();
#else
    appDataPath = "C:\\temp\\reeflogdata";
#endif

    initDatabase();
    applyStylesheet();
    ui->setupUi(this);
    instance=this;
    start();

    showFullScreen();
}

void MainWindow::clearContextMenus()
{
    QWidgetList widgets = QApplication::allWidgets();
    QWidget* w=0;
    foreach(w,widgets) {
        w->setContextMenuPolicy(Qt::NoContextMenu);
    }
}


void MainWindow::showMainScreen()
{
    QAction *action;

    foreach (action, menuBar()->actions())
        menuBar()->removeAction(action);

    menuBar()->addAction(actionAbout);
    menuBar()->addAction(actionHelp);

    removeAction(actionBack);
    addAction(actionExit);

    mainScreen->show();
}

void MainWindow::showScreen(Screen* screen)
{
    ui->stackedWidget->setCurrentWidget(screen);
}

Screen* MainWindow::getCurrentScreen()
{
    return qobject_cast<Screen*>(ui->stackedWidget->currentWidget());
}

void MainWindow::initDatabase()
{
    bool createTables=true;
    QString dbFileName;

    db=QSqlDatabase::addDatabase("QSQLITE");

    dbFileName=appDataPath.replace("/", "\\")+"\\"DB_FILE_NAME;

    createTables=!QFile::exists(dbFileName);
    db.setDatabaseName(dbFileName);

    db.open();
    if (createTables) {
        QSqlQuery query;
        QFile data(":/resources/resources/initdb.sql");
        QString sql;

        if(data.open(QFile::ReadOnly)) {
            QTextStream styleIn(&data);

            while (!(sql=styleIn.readLine()).isNull())
                query.exec(sql);

            data.close();
        }
    } else {
        // Verificar se é necessário upgrade
    }
}

QAction* MainWindow::getBackAction()
{
    return actionBack;
}


MainWindow* MainWindow::getInstance()
{
    return instance;
}

void MainWindow::showHelp()
{
    QDesktopServices::openUrl(QUrl(QString(HELP_URI)+"/"+appLang));
}

void MainWindow::start()
{
    actionBack=new QAction(tr("Back"), this);
    actionAbout=new QAction(tr("About"), this);
    actionHelp=new QAction(tr("Help"), this);

    actionExit=new QAction(tr("Quit"), this);

    actionBack->setSoftKeyRole(QAction::NegativeSoftKey);
    actionExit->setSoftKeyRole(QAction::NegativeSoftKey);

    ui->stackedWidget->addWidget(mainScreen=new MainScreen(this));
    ui->stackedWidget->addWidget(editRecordScreen=new EditRecordScreen(this));
    ui->stackedWidget->addWidget(dosageAdviceScreen=new DosageAdviceScreen(this));
    ui->stackedWidget->addWidget(scheduleScreen=new ScheduleScreen(this));

    connect(actionBack, SIGNAL(triggered()), this, SLOT(showMainScreen()));
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(showHelp()));
    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(EventBus::getInstance(), SIGNAL(showMainScreen()), this, SLOT(showMainScreen()));

    clearContextMenus();

#if defined(TIME_TRIAL_VERSION)
    QMessageBox::information(0, tr("Reef Chemistry Log"), "Trial version\r\n(ends on October 1, 2012)");
    if (QDate::currentDate()>QDate(2012, 10, 1))
        QApplication::instance()->quit();
#endif

    showMainScreen();
}

QString MainWindow::getStyleSheet()
{
    QFile file(":/resource/styles.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    return in.readAll();
}


void MainWindow::applyStylesheet()
{
    QFile data(":/resources/resources/styles.txt");
    QString style;
    if(data.open(QFile::ReadOnly)) {
        /* QTextStream... */
        QTextStream styleIn(&data);
        /* ...read file to a string. */
        style = styleIn.readAll();
        data.close();
        /* We'll use qApp macro to get the QApplication pointer
         * and set the style sheet application wide. */
        qApp->setStyleSheet(style);
    }
}
