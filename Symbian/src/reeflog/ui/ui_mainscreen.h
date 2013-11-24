/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created: Mon 26. Sep 00:57:15 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *babyContainer;
    QVBoxLayout *babyLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *prevDayButton;
    QToolButton *currentDateBtn;
    QToolButton *nextDayButton;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QToolButton *checkInOutButton;
    QToolButton *manualButton;
    QToolButton *statsButton;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QString::fromUtf8("MainScreen"));
        MainScreen->resize(360, 640);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainScreen->sizePolicy().hasHeightForWidth());
        MainScreen->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(MainScreen);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        babyContainer = new QWidget(MainScreen);
        babyContainer->setObjectName(QString::fromUtf8("babyContainer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(babyContainer->sizePolicy().hasHeightForWidth());
        babyContainer->setSizePolicy(sizePolicy1);
        babyContainer->setMinimumSize(QSize(0, 130));
        babyContainer->setMaximumSize(QSize(16777215, 130));
        babyLayout = new QVBoxLayout(babyContainer);
        babyLayout->setSpacing(0);
        babyLayout->setContentsMargins(0, 0, 0, 0);
        babyLayout->setObjectName(QString::fromUtf8("babyLayout"));

        verticalLayout->addWidget(babyContainer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        prevDayButton = new QToolButton(MainScreen);
        prevDayButton->setObjectName(QString::fromUtf8("prevDayButton"));

        horizontalLayout_2->addWidget(prevDayButton);

        currentDateBtn = new QToolButton(MainScreen);
        currentDateBtn->setObjectName(QString::fromUtf8("currentDateBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(currentDateBtn->sizePolicy().hasHeightForWidth());
        currentDateBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(currentDateBtn);

        nextDayButton = new QToolButton(MainScreen);
        nextDayButton->setObjectName(QString::fromUtf8("nextDayButton"));

        horizontalLayout_2->addWidget(nextDayButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listView = new QListView(MainScreen);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setSelectionMode(QAbstractItemView::NoSelection);
        listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView->setUniformItemSizes(true);

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkInOutButton = new QToolButton(MainScreen);
        checkInOutButton->setObjectName(QString::fromUtf8("checkInOutButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkInOutButton->sizePolicy().hasHeightForWidth());
        checkInOutButton->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(5);
        checkInOutButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/k-timer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkInOutButton->setIcon(icon);
        checkInOutButton->setIconSize(QSize(48, 48));
        checkInOutButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(checkInOutButton);

        manualButton = new QToolButton(MainScreen);
        manualButton->setObjectName(QString::fromUtf8("manualButton"));
        sizePolicy3.setHeightForWidth(manualButton->sizePolicy().hasHeightForWidth());
        manualButton->setSizePolicy(sizePolicy3);
        manualButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/accessories-text-editor.svg"), QSize(), QIcon::Normal, QIcon::Off);
        manualButton->setIcon(icon1);
        manualButton->setIconSize(QSize(48, 48));
        manualButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(manualButton);

        statsButton = new QToolButton(MainScreen);
        statsButton->setObjectName(QString::fromUtf8("statsButton"));
        sizePolicy3.setHeightForWidth(statsButton->sizePolicy().hasHeightForWidth());
        statsButton->setSizePolicy(sizePolicy3);
        statsButton->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/x-office-spreadsheet.svg"), QSize(), QIcon::Normal, QIcon::Off);
        statsButton->setIcon(icon2);
        statsButton->setIconSize(QSize(48, 48));
        statsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(statsButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        prevDayButton->setText(QApplication::translate("MainScreen", "<", 0, QApplication::UnicodeUTF8));
        currentDateBtn->setText(QApplication::translate("MainScreen", "...", 0, QApplication::UnicodeUTF8));
        nextDayButton->setText(QApplication::translate("MainScreen", ">", 0, QApplication::UnicodeUTF8));
        checkInOutButton->setText(QApplication::translate("MainScreen", "Timer", 0, QApplication::UnicodeUTF8));
        manualButton->setText(QApplication::translate("MainScreen", "Event", 0, QApplication::UnicodeUTF8));
        statsButton->setText(QApplication::translate("MainScreen", "Report", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainScreen);
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
