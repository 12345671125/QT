/****************************************************************************
** Meta object code from reading C++ file 'tipbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tipbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tipbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TipBox_t {
    QByteArrayData data[11];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TipBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TipBox_t qt_meta_stringdata_TipBox = {
    {
QT_MOC_LITERAL(0, 0, 6), // "TipBox"
QT_MOC_LITERAL(1, 7, 16), // "signalCardClosed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "NotificationEntry*"
QT_MOC_LITERAL(4, 44, 4), // "noti"
QT_MOC_LITERAL(5, 49, 17), // "signalCardClicked"
QT_MOC_LITERAL(6, 67, 16), // "signalBtnClicked"
QT_MOC_LITERAL(7, 84, 14), // "slotCardClosed"
QT_MOC_LITERAL(8, 99, 8), // "TipCard*"
QT_MOC_LITERAL(9, 108, 4), // "card"
QT_MOC_LITERAL(10, 113, 14) // "adjustPosition"

    },
    "TipBox\0signalCardClosed\0\0NotificationEntry*\0"
    "noti\0signalCardClicked\0signalBtnClicked\0"
    "slotCardClosed\0TipCard*\0card\0"
    "adjustPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TipBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   48,    2, 0x0a /* Public */,
      10,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void TipBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TipBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalCardClosed((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 1: _t->signalCardClicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 2: _t->signalBtnClicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 3: _t->slotCardClosed((*reinterpret_cast< TipCard*(*)>(_a[1]))); break;
        case 4: _t->adjustPosition(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationEntry* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationEntry* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationEntry* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TipCard* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TipBox::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipBox::signalCardClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TipBox::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipBox::signalCardClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TipBox::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipBox::signalBtnClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TipBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TipBox.data,
    qt_meta_data_TipBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TipBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TipBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TipBox.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TipBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TipBox::signalCardClosed(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TipBox::signalCardClicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TipBox::signalBtnClicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
