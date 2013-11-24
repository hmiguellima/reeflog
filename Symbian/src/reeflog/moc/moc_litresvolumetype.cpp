/****************************************************************************
** Meta object code from reading C++ file 'litresvolumetype.h'
**
** Created: Mon 11. Jun 16:00:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../model/litresvolumetype.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'litresvolumetype.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LitresVolumeType[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_LitresVolumeType[] = {
    "LitresVolumeType\0"
};

const QMetaObject LitresVolumeType::staticMetaObject = {
    { &VolumeType::staticMetaObject, qt_meta_stringdata_LitresVolumeType,
      qt_meta_data_LitresVolumeType, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LitresVolumeType::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LitresVolumeType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LitresVolumeType::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LitresVolumeType))
        return static_cast<void*>(const_cast< LitresVolumeType*>(this));
    return VolumeType::qt_metacast(_clname);
}

int LitresVolumeType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VolumeType::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
