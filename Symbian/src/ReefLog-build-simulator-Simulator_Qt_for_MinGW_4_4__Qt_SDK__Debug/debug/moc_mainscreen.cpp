/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created: Mon 5. Mar 23:54:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/controller/mainscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainScreen[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      43,   37,   11,   11, 0x08,
      74,   37,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     127,   37,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     242,   11,   11,   11, 0x08,
     271,  264,   11,   11, 0x08,
     294,   11,   11,   11, 0x28,
     320,  314,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainScreen[] = {
    "MainScreen\0\0handleNewRecordClicked()\0"
    "index\0handleRecordDeleteClicked(int)\0"
    "handleRecordEditClicked(int)\0"
    "handleAboutBtnClicked()\0"
    "handleAquariumClicked(int)\0"
    "handleNewAquariumClicked()\0"
    "handleDeleteAquariumClicked()\0"
    "handleUpdateAdditivesClicked()\0"
    "handleEventsUpdated()\0screen\0"
    "updateOrientation(int)\0updateOrientation()\0"
    "reply\0replyFinished(QNetworkReply*)\0"
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
        case 1: handleRecordDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: handleRecordEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: handleAboutBtnClicked(); break;
        case 4: handleAquariumClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: handleNewAquariumClicked(); break;
        case 6: handleDeleteAquariumClicked(); break;
        case 7: handleUpdateAdditivesClicked(); break;
        case 8: handleEventsUpdated(); break;
        case 9: updateOrientation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: updateOrientation(); break;
        case 11: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
