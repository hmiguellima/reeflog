/****************************************************************************
** Meta object code from reading C++ file 'aquarium.h'
**
** Created: Mon 11. Jun 16:00:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../model/aquarium.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aquarium.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Aquarium[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      21,    9, 0x00095009,
      46,   38, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_Aquarium[] = {
    "Aquarium\0PParameters\0targetParameters\0"
    "PVolume\0waterVolume\0"
};

const QMetaObject Aquarium::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Aquarium,
      qt_meta_data_Aquarium, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Aquarium::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Aquarium::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Aquarium::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Aquarium))
        return static_cast<void*>(const_cast< Aquarium*>(this));
    return QObject::qt_metacast(_clname);
}

int Aquarium::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< PParameters*>(_v) = getTargetParameters(); break;
        case 1: *reinterpret_cast< PVolume*>(_v) = getWaterVolume(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
