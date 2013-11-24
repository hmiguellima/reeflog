#include "editrecordverticalview.h"
#include <QLabel>
#include <QFormLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QDoubleValidator>

#define LABEL_WIDTH 120
#define EDIT_VALUE_WIDTH 80
#define EDIT_TYPE_WIDTH 120

EditRecordVerticalView::EditRecordVerticalView(Screen *parent) : EditRecordView(parent)
{
    QGridLayout* gLayout;
    QLabel* targetLabel=new QLabel(tr("Last target parameters"));
    QLabel* currentLabel=new QLabel(tr("Current values"));
    QLabel* fieldLabel;
    QHBoxLayout* buttonLayout=new QHBoxLayout();
    QPushButton* saveBtn=new QPushButton("");
    QPushButton* cancelBtn=new QPushButton("");
    QWidget* panel=new QWidget();
    QVBoxLayout* vLayout=new QVBoxLayout(panel);
    QDoubleValidator* validator=new QDoubleValidator(this);

    setObjectName("editrecordverticalview");
    // Crazy hack to allow styling
    setAttribute(Qt::WA_StyledBackground);

    panel->setObjectName("panel");

    titleLabel=new QLabel("");
    titleLabel->setObjectName("titlelabel");

    vLayout->setSpacing(0);
    vLayout->setMargin(0);

    targetLabel->setObjectName("targetlabel");
    //targetLabel->setAlignment(Qt::AlignCenter);
    currentLabel->setObjectName("currentlabel");
    //currentLabel->setAlignment(Qt::AlignCenter);

    vLayout->addWidget(targetLabel);

    gLayout=new QGridLayout();

    gLayout->setHorizontalSpacing(5);
    gLayout->setVerticalSpacing(5);

    fieldLabel=new QLabel(tr("Volume:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 0, 0);
    gLayout->addWidget(waterVolEdit, 0, 1);
    waterVolEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    waterVolCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(waterVolCombo, 0, 2);

    fieldLabel=new QLabel(tr("Calcium:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 1, 0);
    gLayout->addWidget(targetCalciumEdit, 1, 1);
    targetCalciumEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    targetCalciumCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(targetCalciumCombo, 1, 2);

    fieldLabel=new QLabel(tr("Alkalinity:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 2, 0);
    gLayout->addWidget(targetAlkalinityEdit, 2, 1);
    targetAlkalinityEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    targetAlkalinityCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(targetAlkalinityCombo, 2, 2);

    fieldLabel=new QLabel(tr("Magnesium:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 3, 0);
    gLayout->addWidget(targetMagnesiumEdit, 3, 1);
    targetMagnesiumEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    targetMagnesiumCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(targetMagnesiumCombo, 3, 2);

    vLayout->addLayout(gLayout);
    vLayout->addSpacing(10);
    vLayout->addWidget(currentLabel);

    gLayout=new QGridLayout();

    gLayout->setHorizontalSpacing(5);
    gLayout->setVerticalSpacing(5);

    fieldLabel=new QLabel(tr("Calcium:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 0, 0);
    gLayout->addWidget(currentCalciumEdit, 0, 1);
    currentCalciumEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    currentCalciumCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(currentCalciumCombo, 0, 2);

    fieldLabel=new QLabel(tr("Alkalinity:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 1, 0);
    gLayout->addWidget(currentAlkalinityEdit, 1, 1);
    currentAlkalinityEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    currentAlkalinityCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(currentAlkalinityCombo, 1, 2);

    fieldLabel=new QLabel(tr("Magnesium:"));
    fieldLabel->setFixedWidth(LABEL_WIDTH);
    gLayout->addWidget(fieldLabel, 2, 0);
    gLayout->addWidget(currentMagnesiumEdit, 2, 1);
    currentMagnesiumEdit->setFixedWidth(EDIT_VALUE_WIDTH);
    currentMagnesiumCombo->setFixedWidth(EDIT_TYPE_WIDTH);
    gLayout->addWidget(currentMagnesiumCombo, 2, 2);

    vLayout->addLayout(gLayout);

    gLayout=new QGridLayout();
    gLayout->setHorizontalSpacing(5);

    fieldLabel=new QLabel(tr("Show dosage advice?"));
    gLayout->addWidget(fieldLabel, 0, 0);
    gLayout->addWidget(showDosageCheck, 0, 1);

    vLayout->addSpacing(20);
    vLayout->addLayout(gLayout);
    vLayout->addStretch(1);

    vLayout=new QVBoxLayout(this);

    vLayout->setSpacing(0);
    vLayout->setMargin(0);

    vLayout->addWidget(titleLabel);
    vLayout->addWidget(panel);
    vLayout->addSpacing(15);
    vLayout->addLayout(buttonLayout);

    saveBtn->setObjectName("savebtn");
    buttonLayout->addWidget(saveBtn);
    buttonLayout->addStretch(1);
    cancelBtn->setObjectName("cancelbtn");
    buttonLayout->addWidget(cancelBtn);

    waterVolEdit->setValidator(validator);
    waterVolEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    targetCalciumEdit->setValidator(validator);
    targetCalciumEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    targetAlkalinityEdit->setValidator(validator);
    targetAlkalinityEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    targetMagnesiumEdit->setValidator(validator);
    targetMagnesiumEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    currentCalciumEdit->setValidator(validator);
    currentCalciumEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    currentAlkalinityEdit->setValidator(validator);
    currentAlkalinityEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
    currentMagnesiumEdit->setValidator(validator);
    currentMagnesiumEdit->setInputMethodHints(Qt::ImhFormattedNumbersOnly);


    connect(saveBtn, SIGNAL(clicked()), this, SLOT(handleSaveBtnClicked()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(handleBackBtnClicked()));
}

void EditRecordVerticalView::setTitle(QString title)
{
    titleLabel->setText(title);
}
