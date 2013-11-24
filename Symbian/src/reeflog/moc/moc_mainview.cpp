/****************************************************************************
** Meta object code from reading C++ file 'mainview.h'
**
** Created: Mon 11. Jun 16:00:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/mainview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      26,    9,    9,    9, 0x05,
      41,    9,    9,    9, 0x05,
      64,   58,    9,    9, 0x05,
      89,   58,    9,    9, 0x05,
     112,   58,    9,    9, 0x05,
     133,    9,    9,    9, 0x05,
     157,    9,    9,    9, 0x05,
     178,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     216,  204,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainView[] = {
    "MainView\0\0newBtnClicked()\0aboutClicked()\0"
    "quitBtnClicked()\0index\0recordDeleteClicked(int)\0"
    "recordEditClicked(int)\0aquariumClicked(int)\0"
    "aquariumDeleteClicked()\0newAquariumClicked()\0"
    "updateaAdditivesClicked()\0eventsModel\0"
    "setEvents(PRecordModel)\0"
};

const QMetaObject MainView::staticMetaObject = {
    { &View::staticMetaObject, qt_meta_stringdata_MainView,
      qt_meta_data_MainView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainView))
        return static_cast<void*>(const_cast< MainView*>(this));
    return View::qt_metacast(_clname);
}

int MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newBtnClicked(); break;
        case 1: aboutClicked(); break;
        case 2: quitBtnClicked(); break;
        case 3: recordDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: recordEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: aquariumClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: aquariumDeleteClicked(); break;
        case 7: newAquariumClicked(); break;
        case 8: updateaAdditivesClicked(); break;
        case 9: setEvents((*reinterpret_cast< PRecordModel(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainView::newBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainView::aboutClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainView::quitBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainView::recordDeleteClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainView::recordEditClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainView::aquariumClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainView::aquariumDeleteClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainView::newAquariumClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MainView::updateaAdditivesClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
