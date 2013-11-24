/****************************************************************************
** Meta object code from reading C++ file 'editrecordview.h'
**
** Created: Mon 5. Mar 23:54:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reeflog/view/editrecordview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editrecordview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditRecordView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      33,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   15,   15,   15, 0x08,
      73,   15,   15,   15, 0x08,
      96,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditRecordView[] = {
    "EditRecordView\0\0saveBtnClicked()\0"
    "backBtnClicked()\0handleSaveBtnClicked()\0"
    "handleBackBtnClicked()\0"
    "handleDosageCheckClicked()\0"
};

const QMetaObject EditRecordView::staticMetaObject = {
    { &View::staticMetaObject, qt_meta_stringdata_EditRecordView,
      qt_meta_data_EditRecordView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditRecordView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditRecordView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditRecordView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditRecordView))
        return static_cast<void*>(const_cast< EditRecordView*>(this));
    return View::qt_metacast(_clname);
}

int EditRecordView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveBtnClicked(); break;
        case 1: backBtnClicked(); break;
        case 2: handleSaveBtnClicked(); break;
        case 3: handleBackBtnClicked(); break;
        case 4: handleDosageCheckClicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void EditRecordView::saveBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EditRecordView::backBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
