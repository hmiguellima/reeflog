/****************************************************************************
** Meta object code from reading C++ file 'additive.h'
**
** Created: Mon 11. Jun 16:00:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../model/additive.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additive.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Additive[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      15,    9, (QMetaType::QReal << 24) | 0x00095001,
      30,   22, 0x0a095001,
      35,   22, 0x0a095001,

       0        // eod
};

static const char qt_meta_stringdata_Additive[] = {
    "Additive\0qreal\0factor\0QString\0name\0"
    "instructions\0"
};

const QMetaObject Additive::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Additive,
      qt_meta_data_Additive, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Additive::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Additive::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Additive::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Additive))
        return static_cast<void*>(const_cast< Additive*>(this));
    return QObject::qt_metacast(_clname);
}

int Additive::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = getFactor(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getInstructions(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
