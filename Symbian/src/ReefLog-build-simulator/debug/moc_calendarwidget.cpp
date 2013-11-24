/****************************************************************************
** Meta object code from reading C++ file 'calendarwidget.h'
**
** Created: Sun 2. Oct 02:17:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/calendarwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalendarWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   15,   15,   15, 0x08,
      51,   15,   15,   15, 0x08,
      75,   67,   15,   15, 0x08,
     102,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CalendarWidget[] = {
    "CalendarWidget\0\0selectionChanged()\0"
    "showPrevMonth()\0showNextMonth()\0ano,mes\0"
    "updateAnoMesLabel(int,int)\0"
    "emitSelectionChanged()\0"
};

const QMetaObject CalendarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalendarWidget,
      qt_meta_data_CalendarWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalendarWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalendarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalendarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalendarWidget))
        return static_cast<void*>(const_cast< CalendarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalendarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectionChanged(); break;
        case 1: showPrevMonth(); break;
        case 2: showNextMonth(); break;
        case 3: updateAnoMesLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: emitSelectionChanged(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CalendarWidget::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
