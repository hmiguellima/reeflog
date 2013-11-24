/****************************************************************************
** Meta object code from reading C++ file 'scheduleview.h'
**
** Created: Mon 11. Jun 16:00:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/scheduleview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scheduleview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScheduleView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      35,   13,   13,   13, 0x05,
      57,   52,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   13,   13,   13, 0x08,
     105,   13,   13,   13, 0x08,
     137,  128,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScheduleView[] = {
    "ScheduleView\0\0scheduleBtnClicked()\0"
    "backBtnClicked()\0days\0intervalChanged(int)\0"
    "handleScheduleBtnClicked()\0"
    "handleBackBtnClicked()\0interval\0"
    "handleIntervalChanged(QString)\0"
};

const QMetaObject ScheduleView::staticMetaObject = {
    { &View::staticMetaObject, qt_meta_stringdata_ScheduleView,
      qt_meta_data_ScheduleView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScheduleView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScheduleView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScheduleView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScheduleView))
        return static_cast<void*>(const_cast< ScheduleView*>(this));
    return View::qt_metacast(_clname);
}

int ScheduleView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scheduleBtnClicked(); break;
        case 1: backBtnClicked(); break;
        case 2: intervalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: handleScheduleBtnClicked(); break;
        case 4: handleBackBtnClicked(); break;
        case 5: handleIntervalChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ScheduleView::scheduleBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScheduleView::backBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ScheduleView::intervalChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
