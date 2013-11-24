/****************************************************************************
** Meta object code from reading C++ file 'dosageadvicescreen.h'
**
** Created: Mon 11. Jun 16:00:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller/dosageadvicescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dosageadvicescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DosageAdviceScreen[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   20,   19,   19, 0x08,
      81,   19,   19,   19, 0x08,
      96,   90,   19,   19, 0x08,
     131,   90,   19,   19, 0x08,
     169,   90,   19,   19, 0x08,
     206,   19,   19,   19, 0x08,
     224,   19,   19,   19, 0x08,
     255,   19,   19,   19, 0x08,
     289,   19,   19,   19, 0x08,
     322,   19,   19,   19, 0x08,
     343,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DosageAdviceScreen[] = {
    "DosageAdviceScreen\0\0aquarium,record\0"
    "showDosageAdviceScreen(PAquarium,PLogRecord)\0"
    "update()\0index\0handleCalciumAdditiveSelected(int)\0"
    "handleAlkalinityAdditiveSelected(int)\0"
    "handleMagnesiumAdditiveSelected(int)\0"
    "handleOkClicked()\0handleScheduleCalciumClicked()\0"
    "handleScheduleAlkalinityClicked()\0"
    "handleScheduleMagnesiumClicked()\0"
    "returnFromSchedule()\0handleBackClicked()\0"
};

const QMetaObject DosageAdviceScreen::staticMetaObject = {
    { &Screen::staticMetaObject, qt_meta_stringdata_DosageAdviceScreen,
      qt_meta_data_DosageAdviceScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DosageAdviceScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DosageAdviceScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DosageAdviceScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DosageAdviceScreen))
        return static_cast<void*>(const_cast< DosageAdviceScreen*>(this));
    return Screen::qt_metacast(_clname);
}

int DosageAdviceScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Screen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showDosageAdviceScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PLogRecord(*)>(_a[2]))); break;
        case 1: update(); break;
        case 2: handleCalciumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: handleAlkalinityAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: handleMagnesiumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: handleOkClicked(); break;
        case 6: handleScheduleCalciumClicked(); break;
        case 7: handleScheduleAlkalinityClicked(); break;
        case 8: handleScheduleMagnesiumClicked(); break;
        case 9: returnFromSchedule(); break;
        case 10: handleBackClicked(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
