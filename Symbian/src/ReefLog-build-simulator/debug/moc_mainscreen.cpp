/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created: Thu 20. Oct 00:00:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/mainscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainScreen[] = {

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
      12,   11,   11,   11, 0x08,
      43,   37,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      99,   92,   11,   11, 0x08,
     122,   11,   11,   11, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_MainScreen[] = {
    "MainScreen\0\0handleNewRecordClicked()\0"
    "index\0handleRecordClicked(int)\0"
    "handleAboutBtnClicked()\0screen\0"
    "updateOrientation(int)\0updateOrientation()\0"
};

const QMetaObject MainScreen::staticMetaObject = {
    { &Screen::staticMetaObject, qt_meta_stringdata_MainScreen,
      qt_meta_data_MainScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen))
        return static_cast<void*>(const_cast< MainScreen*>(this));
    return Screen::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Screen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleNewRecordClicked(); break;
        case 1: handleRecordClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: handleAboutBtnClicked(); break;
        case 3: updateOrientation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: updateOrientation(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
