#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QAction>
#include <QString>
#include "controller/mainscreen.h"
#include <QListWidget>
#include <QModelIndex>
#include "controller/editrecordscreen.h"
#include "controller/dosageadvicescreen.h"
#include "controller/schedulescreen.h"
#include "controller/screen.h"

namespace Ui {
    class MainWindow;
}

class Screen;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showScreen(Screen* screen);
    QAction* getBackAction();
    Screen* getCurrentScreen();

    static MainWindow* getInstance();

private:
    static MainWindow* instance;

    Ui::MainWindow *ui;

    MainScreen* mainScreen;
    EditRecordScreen* editRecordScreen;
    DosageAdviceScreen* dosageAdviceScreen;
    ScheduleScreen* scheduleScreen;

    QSqlDatabase db;
    QAction *actionBack;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHelp;

    QString getStyleSheet();

public slots:
    void init();
    void start();

private slots:
    void showMainScreen();
    void initDatabase();
    void clearContextMenus();
    void showHelp();
    void applyStylesheet();
};

#endif // MAINWINDOW_H
