#ifndef SCREEN_H
#define SCREEN_H
#include <QWidget>
#include <QSize>

class MainWindow;

class Screen: public QWidget
{
    Q_OBJECT

public:
    Screen(MainWindow* window);



public slots:
    void show();

protected:
    MainWindow* getWindow();
    virtual void showHandler() = 0;
    bool isCurrent();

private:
    MainWindow* window;
};

#endif // SCREEN_H
