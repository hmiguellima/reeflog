/****************************************************************************
** Meta object code from reading C++ file 'eventbus.h'
**
** Created: Mon 5. Mar 23:54:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/eventbus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EventBus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      36,   27,    9,    9, 0x05,
      61,    9,    9,    9, 0x05,
      77,    9,    9,    9, 0x05,
     111,   95,    9,    9, 0x05,
     150,   95,    9,    9, 0x05,
     227,  187,    9,    9, 0x05,
     281,    9,    9,    9, 0x05,
     302,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     321,    9,    9,    9, 0x0a,
     342,   27,    9,    9, 0x0a,
     371,    9,    9,    9, 0x0a,
     393,    9,    9,    9, 0x0a,
     413,   95,    9,    9, 0x0a,
     456,   95,    9,    9, 0x0a,
     497,  187,    9,    9, 0x0a,
     555,    9,    9,    9, 0x0a,
     580,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EventBus[] = {
    "EventBus\0\0showMainScreen()\0aquarium\0"
    "showNewRecord(PAquarium)\0eventsUpdated()\0"
    "showAboutScreen()\0aquarium,record\0"
    "showAdviceScreen(PAquarium,PLogRecord)\0"
    "showEditRecord(PAquarium,PLogRecord)\0"
    "aquarium,additive,sourceLevel,destLevel\0"
    "showScheduleScreen(PAquarium,PAdditive,PLevel,PLevel)\0"
    "returnFromSchedule()\0returnFromAdvice()\0"
    "fireShowMainScreen()\0fireShowNewRecord(PAquarium)\0"
    "fireShowAboutScreen()\0fireEventsUpdated()\0"
    "fireShowAdviceScreen(PAquarium,PLogRecord)\0"
    "fireShowEditRecord(PAquarium,PLogRecord)\0"
    "fireShowScheduleScreen(PAquarium,PAdditive,PLevel,PLevel)\0"
    "fireReturnFromSchedule()\0"
    "fireReturnFromAdvice()\0"
};

const QMetaObject EventBus::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EventBus,
      qt_meta_data_EventBus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EventBus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EventBus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EventBus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EventBus))
        return static_cast<void*>(const_cast< EventBus*>(this));
    return QObject::qt_metacast(_clname);
}

int EventBus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showMainScreen(); break;
        case 1: showNewRecord((*reinterpret_cast< PAquarium(*)>(_a[1]))); break;
        case 2: eventsUpdated(); break;
        case 3: showAboutScreen(); break;
        case 4: showAdviceScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PLogRecord(*)>(_a[2]))); break;
        case 5: showEditRecord((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PLogRecord(*)>(_a[2]))); break;
        case 6: showScheduleScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PAdditive(*)>(_a[2])),(*reinterpret_cast< PLevel(*)>(_a[3])),(*reinterpret_cast< PLevel(*)>(_a[4]))); break;
        case 7: returnFromSchedule(); break;
        case 8: returnFromAdvice(); break;
        case 9: fireShowMainScreen(); break;
        case 10: fireShowNewRecord((*reinterpret_cast< PAquarium(*)>(_a[1]))); break;
        case 11: fireShowAboutScreen(); break;
        case 12: fireEventsUpdated(); break;
        case 13: fireShowAdviceScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PLogRecord(*)>(_a[2]))); break;
        case 14: fireShowEditRecord((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PLogRecord(*)>(_a[2]))); break;
        case 15: fireShowScheduleScreen((*reinterpret_cast< PAquarium(*)>(_a[1])),(*reinterpret_cast< PAdditive(*)>(_a[2])),(*reinterpret_cast< PLevel(*)>(_a[3])),(*reinterpret_cast< PLevel(*)>(_a[4]))); break;
        case 16: fireReturnFromSchedule(); break;
        case 17: fireReturnFromAdvice(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void EventBus::showMainScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EventBus::showNewRecord(PAquarium _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EventBus::eventsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void EventBus::showAboutScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void EventBus::showAdviceScreen(PAquarium _t1, PLogRecord _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EventBus::showEditRecord(PAquarium _t1, PLogRecord _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EventBus::showScheduleScreen(PAquarium _t1, PAdditive _t2, PLevel _t3, PLevel _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EventBus::returnFromSchedule()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void EventBus::returnFromAdvice()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
