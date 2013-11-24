/****************************************************************************
** Meta object code from reading C++ file 'eventbus.h'
**
** Created: Wed 19. Oct 23:54:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/eventbus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EventBus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      27,    9,    9,    9, 0x05,
      43,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_EventBus[] = {
    "EventBus\0\0showMainScreen()\0showNewRecord()\0"
    "showAboutScreen()\0"
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
        case 1: showNewRecord(); break;
        case 2: showAboutScreen(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void EventBus::showMainScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EventBus::showNewRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void EventBus::showAboutScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
