/****************************************************************************
** Meta object code from reading C++ file 'usgallonsvolumetype.h'
**
** Created: Wed 5. Oct 03:10:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/usgallonsvolumetype.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usgallonsvolumetype.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_USGallonsVolumeType[] = {

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

static const char qt_meta_stringdata_USGallonsVolumeType[] = {
    "USGallonsVolumeType\0"
};

const QMetaObject USGallonsVolumeType::staticMetaObject = {
    { &VolumeType::staticMetaObject, qt_meta_stringdata_USGallonsVolumeType,
      qt_meta_data_USGallonsVolumeType, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &USGallonsVolumeType::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *USGallonsVolumeType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *USGallonsVolumeType::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_USGallonsVolumeType))
        return static_cast<void*>(const_cast< USGallonsVolumeType*>(this));
    return VolumeType::qt_metacast(_clname);
}

int USGallonsVolumeType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VolumeType::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
