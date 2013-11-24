#-------------------------------------------------
#
# Project created by QtCreator 2010-08-16T00:18:09
#
#-------------------------------------------------

CONFIG += debug

QT += core gui sql network
CONFIG += mobility
MOBILITY += organizer

TARGET = ReefLog
TEMPLATE = app
VERSION = 1.0.0

DEFINES += QTSCROLLER_NO_WEBKIT
DEFINES += TIME_TRIAL_VERSION
DEFINES += SYMBIAN_VERSION
win32:DESTDIR = $$OUT_PWD

SOURCES += \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    controller/mainscreen.cpp \
    controller/screen.cpp \
    qtkineticscroller/qtscrollevent.cpp \
    qtkineticscroller/qtscrollerproperties.cpp \
    qtkineticscroller/qtscrollerfilter.cpp \
    qtkineticscroller/qtscroller.cpp \
    qtkineticscroller/qtflickgesture.cpp \
    splashscreen.cpp \
    eventbus.cpp \
    view/mainview.cpp \
    view/view.cpp \
    model/level.cpp \
    model/alkalinitylevel.cpp \
    model/calciumlevel.cpp \
    model/magnesiumlevel.cpp \
    model/leveltype.cpp \
    model/additive.cpp \
    model/dosage.cpp \
    model/parameters.cpp \
    model/logrecord.cpp \
    model/aquarium.cpp \
    model/volume.cpp \
    model/volumetype.cpp \
    view/mainverticalview.cpp \
    model/recordmodel.cpp \
    view/recorddelegate.cpp \
    model/ppmleveltype.cpp \
    model/dkhleveltype.cpp \
    model/meqleveltype.cpp \
    model/litresvolumetype.cpp \
    model/usgallonsvolumetype.cpp \
    model/imperialgallonsvolumetype.cpp \
    model/unittype.cpp \
    model/gramunittype.cpp \
    view/editrecordview.cpp \
    view/editrecordverticalview.cpp \
    controller/editrecordscreen.cpp \
    controller/dosageadvicescreen.cpp \
    view/dosageadviceview.cpp \
    view/dosageadviceverticalview.cpp \
    controller/schedulescreen.cpp \
    view/scheduleview.cpp \
    view/scheduleverticalview.cpp \
    view/mycombobox.cpp \
    view/myitemdelegate.cpp \
    model/calwrapper.cpp

HEADERS  += \
    global.h \
    mainwindow.h \
    controller/screen.h \
    qtkineticscroller/qtscrollevent.h \
    qtkineticscroller/qtscrollerproperties_p.h \
    qtkineticscroller/qtscrollerproperties.h \
    qtkineticscroller/qtscrollerfilter_p.h \
    qtkineticscroller/qtscroller_p.h \
    qtkineticscroller/qtscroller.h \
    qtkineticscroller/qtflickgesture_p.h \
    qtkineticscroller/qtscrollevent_p.h \
    controller/splashscreen.h \
    eventbus.h \
    view/mainview.h \
    view/view.h \
    model/level.h \
    model/alkalinitylevel.h \
    model/calciumlevel.h \
    model/magnesiumlevel.h \
    model/leveltype.h \
    model/additive.h \
    model/dosage.h \
    model/parameters.h \
    model/logrecord.h \
    model/aquarium.h \
    model/volume.h \
    model/volumetype.h \
    view/mainverticalview.h \
    model/recordmodel.h \
    view/recorddelegate.h \
    model/ppmleveltype.h \
    model/dkhleveltype.h \
    model/meqleveltype.h \
    model/litresvolumetype.h \
    model/usgallonsvolumetype.h \
    model/imperialgallonsvolumetype.h \
    model/unittype.h \
    model/gramunittype.h \
    view/editrecordview.h \
    view/editrecordverticalview.h \
    controller/editrecordscreen.h \
    controller/dosageadvicescreen.h \
    view/dosageadviceview.h \
    view/dosageadviceverticalview.h \
    controller/schedulescreen.h \
    view/scheduleview.h \
    view/scheduleverticalview.h \
    splashscreen.h \
    controller/mainscreen.h \
    view/mycombobox.h \
    view/myitemdelegate.h \
    model/calwrapper.h

FORMS    += \
    calendarwidget.ui \
    mainwindow.ui

symbian*:{
    #Dados para OVI
    #TARGET.UID3 = 0x20036D8F
    #DEPLOYMENT.installer_header=0x2002CCCF
    #vendorinfo = \
    #  "%{\"Hugo Miguel Barbarrica Rodrigues Lima\"}" \
    #  ":\"Hugo Miguel Barbarrica Rodrigues Lima\""
    #my_deployment.pkg_prerules += vendorinfo

    #Dados para self-signed
    TARGET.UID3 = 0xE4DE5D29
    DEPLOYMENT.installer_header=0xA000D7CE
    vendorinfo = \
      "%{\"CustomVendor-EN\"}" \
      ":\"CustomVendor\""
    my_deployment.pkg_prerules += vendorinfo


    ICON = icons/reefcalc_icon.svg

    INCLUDEPATH += C:/QtSDK/Symbian/SDKs/Symbian1Qt473/epoc32/include
    INCLUDEPATH += C:/QtSDK/Symbian/SDKs/Symbian1Qt473/epoc32/include/stdapis

    LIBS += -lestor -lefsrv
    LIBS += -lcone -leikcore -lavkon
    LIBS += -lsendas2 -lmsgs -letext -lcharconv -lgsmu -limcm -lbafl -lmtur

    TARGET.CAPABILITY += ReadUserData \
        WriteUserData \
        NetworkServices \
        LocalServices \
        UserEnvironment
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x1000000
    TARGET.EPOCALLOWDLLDATA = 1

    supported_platforms = \
         "; S60 5.0 and Symbian^3" \
         "[0x1028315F],0,0,0,{\"S60ProductID\"}" \
         "[0x20022E6D],0,0,0,{\"S60ProductID\"}"

    default_deployment.pkg_prerules -= pkg_platform_dependencies
    my_deployment.pkg_prerules += supported_platforms

    DEPLOYMENT += my_deployment
}

RESOURCES += \
    ReefLog.qrc

soundFiles.sources = resources/*.wav
DEPLOYMENT += soundFiles

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog





































































