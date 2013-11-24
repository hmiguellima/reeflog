/****************************************************************************
** Meta object code from reading C++ file 'parameters.h'
**
** Created: Fri 7. Oct 02:01:45 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/parameters.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parameters.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Parameters[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      18,   11, 0x0009510b,
      26,   11, 0x0009510b,
      37,   11, 0x0009510b,
      51,   47, 0x02095001,

       0        // eod
};

static const char qt_meta_stringdata_Parameters[] = {
    "Parameters\0PLevel\0calcium\0alkalinity\0"
    "magnesium\0int\0id\0"
};

const QMetaObject Parameters::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Parameters,
      qt_meta_data_Parameters, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Parameters::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Parameters::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Parameters::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Parameters))
        return static_cast<void*>(const_cast< Parameters*>(this));
    return QObject::qt_metacast(_clname);
}

int Parameters::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< PLevel*>(_v) = getCalcium(); break;
        case 1: *reinterpret_cast< PLevel*>(_v) = getAlkalinity(); break;
        case 2: *reinterpret_cast< PLevel*>(_v) = getMagnesium(); break;
        case 3: *reinterpret_cast< int*>(_v) = getId(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCalcium(*reinterpret_cast< PLevel*>(_v)); break;
        case 1: setAlkalinity(*reinterpret_cast< PLevel*>(_v)); break;
        case 2: setMagnesium(*reinterpret_cast< PLevel*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
