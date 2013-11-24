#ifndef DOSAGEADVICEVERTICALVIEW_H
#define DOSAGEADVICEVERTICALVIEW_H

#include "dosageadviceview.h"
#include <QTabWidget>

class DosageAdviceVerticalView : public DosageAdviceView
{
    Q_OBJECT
public:
    DosageAdviceVerticalView(Screen* parent=0);

    void showPanelByIndex(int index);
    int getVisiblePanelIndex();

private:
    QWidget* calciumPanel;
    QWidget* alkalinityPanel;
    QWidget* magnesiumPanel;
    QTabWidget* tabs;

private slots:
};

#endif // DOSAGEADVICEVERTICALVIEW_H
