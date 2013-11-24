/****************************************************************************
** Meta object code from reading C++ file 'mainverticalviewharmatan.h'
**
** Created: Tue 1. Nov 01:13:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/view/mainverticalviewharmatan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainverticalviewharmatan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainVerticalViewHarmatan[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      38,   26,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainVerticalViewHarmatan[] = {
    "MainVerticalViewHarmatan\0\0eventsModel\0"
    "setEvents(PRecordModel)\0"
};

const QMetaObject MainVerticalViewHarmatan::staticMetaObject = {
    { &MainView::staticMetaObject, qt_meta_stringdata_MainVerticalViewHarmatan,
      qt_meta_data_MainVerticalViewHarmatan, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainVerticalViewHarmatan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainVerticalViewHarmatan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainVerticalViewHarmatan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainVerticalViewHarmatan))
        return static_cast<void*>(const_cast< MainVerticalViewHarmatan*>(this));
    return MainView::qt_metacast(_clname);
}

int MainVerticalViewHarmatan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setEvents((*reinterpret_cast< PRecordModel(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
