/****************************************************************************
** Meta object code from reading C++ file 'labelededit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../loginregister/labelededit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labelededit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabeledEdit_t {
    QByteArrayData data[11];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabeledEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabeledEdit_t qt_meta_stringdata_LabeledEdit = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LabeledEdit"
QT_MOC_LITERAL(1, 12, 9), // "LabelProg"
QT_MOC_LITERAL(2, 22, 9), // "FocusProg"
QT_MOC_LITERAL(3, 32, 9), // "LosesProg"
QT_MOC_LITERAL(4, 42, 9), // "WrongProg"
QT_MOC_LITERAL(5, 52, 11), // "CorrectProg"
QT_MOC_LITERAL(6, 64, 15), // "ShowLoadingProg"
QT_MOC_LITERAL(7, 80, 15), // "HideLoadingProg"
QT_MOC_LITERAL(8, 96, 7), // "TipProg"
QT_MOC_LITERAL(9, 104, 11), // "MsgShowProg"
QT_MOC_LITERAL(10, 116, 11) // "MsgHideProg"

    },
    "LabeledEdit\0LabelProg\0FocusProg\0"
    "LosesProg\0WrongProg\0CorrectProg\0"
    "ShowLoadingProg\0HideLoadingProg\0TipProg\0"
    "MsgShowProg\0MsgHideProg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabeledEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Double, 0x00095103,
       2, QMetaType::Int, 0x00095103,
       3, QMetaType::Int, 0x00095103,
       4, QMetaType::Int, 0x00095103,
       5, QMetaType::Int, 0x00095103,
       6, QMetaType::Int, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       8, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,
      10, QMetaType::Int, 0x00095103,

       0        // eod
};

void LabeledEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LabeledEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getFocusProg(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getFocusProg(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getLosesProg(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getWrongProg(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getCorrectProg(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getShowLoadingProg(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getHideLoadingProg(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getTipProg(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getMsgShowProg(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getMsgHideProg(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LabeledEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLabelProg(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setFocusProg(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setLosesProg(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setWrongProg(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setCorrectProg(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setShowLoadingProg(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setHideLoadingProg(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setTipProg(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setMsgShowProg(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setMsgHideProg(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LabeledEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LabeledEdit.data,
    qt_meta_data_LabeledEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LabeledEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabeledEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabeledEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LabeledEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
