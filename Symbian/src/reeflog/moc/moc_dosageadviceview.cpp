/****************************************************************************
** Meta object code from reading C++ file 'dosageadviceview.h'
**
** Created: Mon 11. Jun 16:00:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/dosageadviceview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dosageadviceview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DosageAdviceView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x05,
      53,   18,   17,   17, 0x05,
      85,   18,   17,   17, 0x05,
     116,   17,   17,   17, 0x05,
     141,   17,   17,   17, 0x05,
     169,   17,   17,   17, 0x05,
     196,   17,   17,   17, 0x05,
     220,   17,   17,   17, 0x05,
     232,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     246,   17,   17,   17, 0x08,
     265,   18,   17,   17, 0x08,
     300,   18,   17,   17, 0x08,
     338,   18,   17,   17, 0x08,
     375,   17,   17,   17, 0x08,
     399,   17,   17,   17, 0x08,
     426,   17,   17,   17, 0x08,
     452,   17,   17,   17, 0x08,
     463,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DosageAdviceView[] = {
    "DosageAdviceView\0\0index\0"
    "calciumAdditiveSelected(int)\0"
    "alkalinityAdditiveSelected(int)\0"
    "magnesiumAdditiveSelected(int)\0"
    "scheduleCalciumClicked()\0"
    "scheduleAlkalinityClicked()\0"
    "scheduleMagnesiumClicked()\0"
    "editParametersClicked()\0okClicked()\0"
    "backClicked()\0handleEditParams()\0"
    "handleCalciumAdditiveSelected(int)\0"
    "handleAlkalinityAdditiveSelected(int)\0"
    "handleMagnesiumAdditiveSelected(int)\0"
    "handleScheduleCalcium()\0"
    "handleScheduleAlkalinity()\0"
    "handleScheduleMagnesium()\0handleOk()\0"
    "handleBack()\0"
};

const QMetaObject DosageAdviceView::staticMetaObject = {
    { &View::staticMetaObject, qt_meta_stringdata_DosageAdviceView,
      qt_meta_data_DosageAdviceView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DosageAdviceView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DosageAdviceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DosageAdviceView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DosageAdviceView))
        return static_cast<void*>(const_cast< DosageAdviceView*>(this));
    return View::qt_metacast(_clname);
}

int DosageAdviceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: calciumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: alkalinityAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: magnesiumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: scheduleCalciumClicked(); break;
        case 4: scheduleAlkalinityClicked(); break;
        case 5: scheduleMagnesiumClicked(); break;
        case 6: editParametersClicked(); break;
        case 7: okClicked(); break;
        case 8: backClicked(); break;
        case 9: handleEditParams(); break;
        case 10: handleCalciumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: handleAlkalinityAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: handleMagnesiumAdditiveSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: handleScheduleCalcium(); break;
        case 14: handleScheduleAlkalinity(); break;
        case 15: handleScheduleMagnesium(); break;
        case 16: handleOk(); break;
        case 17: handleBack(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void DosageAdviceView::calciumAdditiveSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DosageAdviceView::alkalinityAdditiveSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DosageAdviceView::magnesiumAdditiveSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DosageAdviceView::scheduleCalciumClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void DosageAdviceView::scheduleAlkalinityClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void DosageAdviceView::scheduleMagnesiumClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void DosageAdviceView::editParametersClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void DosageAdviceView::okClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void DosageAdviceView::backClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
