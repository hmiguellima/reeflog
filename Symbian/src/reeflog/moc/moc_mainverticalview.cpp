/****************************************************************************
** Meta object code from reading C++ file 'mainverticalview.h'
**
** Created: Mon 11. Jun 16:00:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/mainverticalview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainverticalview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainVerticalView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x08,
      55,   18,   17,   17, 0x08,
      87,   18,   17,   17, 0x08,
     117,   17,   17,   17, 0x08,
     139,   17,   17,   17, 0x08,
     163,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainVerticalView[] = {
    "MainVerticalView\0\0index\0"
    "handleListClicked(QModelIndex)\0"
    "handleRecordOptionSelected(int)\0"
    "handleMainOptionSelected(int)\0"
    "handleNewBtnClicked()\0handleAboutBtnClicked()\0"
    "handleQuitBtnClicked()\0"
};

const QMetaObject MainVerticalView::staticMetaObject = {
    { &MainView::staticMetaObject, qt_meta_stringdata_MainVerticalView,
      qt_meta_data_MainVerticalView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainVerticalView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainVerticalView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainVerticalView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainVerticalView))
        return static_cast<void*>(const_cast< MainVerticalView*>(this));
    return MainView::qt_metacast(_clname);
}

int MainVerticalView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleListClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: handleRecordOptionSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: handleMainOptionSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: handleNewBtnClicked(); break;
        case 4: handleAboutBtnClicked(); break;
        case 5: handleQuitBtnClicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
