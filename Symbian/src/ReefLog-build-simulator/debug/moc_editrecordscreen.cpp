/****************************************************************************
** Meta object code from reading C++ file 'editrecordscreen.h'
**
** Created: Thu 20. Oct 00:07:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/editrecordscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editrecordscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditRecordScreen[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      41,   34,   17,   17, 0x08,
      64,   17,   17,   17, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_EditRecordScreen[] = {
    "EditRecordScreen\0\0showNewRecord()\0"
    "screen\0updateOrientation(int)\0"
    "updateOrientation()\0"
};

const QMetaObject EditRecordScreen::staticMetaObject = {
    { &Screen::staticMetaObject, qt_meta_stringdata_EditRecordScreen,
      qt_meta_data_EditRecordScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditRecordScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditRecordScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditRecordScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditRecordScreen))
        return static_cast<void*>(const_cast< EditRecordScreen*>(this));
    return Screen::qt_metacast(_clname);
}

int EditRecordScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Screen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showNewRecord(); break;
        case 1: updateOrientation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: updateOrientation(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
