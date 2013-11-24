/****************************************************************************
** Meta object code from reading C++ file 'schedulescreen.h'
**
** Created: Mon 5. Mar 23:54:28 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/controller/schedulescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schedulescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScheduleScreen[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      56,   16,   15,   15, 0x08,
     110,   15,   15,   15, 0x08,
     119,   15,   15,   15, 0x08,
     146,   15,   15,   15, 0x08,
     174,  169,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScheduleScreen[] = {
    "ScheduleScreen\0\0aquarium,additive,sourceLevel,destLevel\0"
    "showScheduleScreen(PAquarium,PAdditive,PLevel,PLevel)\0"
    "update()\0handleScheduleBtnClicked()\0"
    "handleBackBtnClicked()\0days\0"
    "handleIntervalChanged(int)\0"
};

const QMetaObject ScheduleScreen::staticMetaObject = {
    { &Screen::staticMetaObject, qt_meta_stringdata_ScheduleScreen,
      qt_meta_data_ScheduleScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScheduleScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScheduleScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScheduleScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScheduleScreen))
        return static_cast<void*>(const_cast< ScheduleScreen*>(this));
    return Screen::qt_metacast(_clname);
}

int ScheduleScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Screen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showScheduleScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PAdditive(*)>(_a[2])),(*reinterpret_cast< PLevel(*)>(_a[3])),(*reinterpret_cast< PLevel(*)>(_a[4]))); break;
        case 1: update(); break;
        case 2: handleScheduleBtnClicked(); break;
        case 3: handleBackBtnClicked(); break;
        case 4: handleIntervalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
