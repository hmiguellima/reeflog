/****************************************************************************
** Meta object code from reading C++ file 'mainhorizontalview.h'
**
** Created: Tue 1. Nov 04:55:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/view/mainhorizontalview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainhorizontalview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainHorizontalView[] = {

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
      20,   19,   19,   19, 0x08,
      42,   19,   19,   19, 0x08,
      66,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainHorizontalView[] = {
    "MainHorizontalView\0\0handleNewBtnClicked()\0"
    "handleAboutBtnClicked()\0handleQuitBtnClicked()\0"
};

const QMetaObject MainHorizontalView::staticMetaObject = {
    { &MainView::staticMetaObject, qt_meta_stringdata_MainHorizontalView,
      qt_meta_data_MainHorizontalView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainHorizontalView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainHorizontalView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainHorizontalView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainHorizontalView))
        return static_cast<void*>(const_cast< MainHorizontalView*>(this));
    return MainView::qt_metacast(_clname);
}

int MainHorizontalView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleNewBtnClicked(); break;
        case 1: handleAboutBtnClicked(); break;
        case 2: handleQuitBtnClicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE