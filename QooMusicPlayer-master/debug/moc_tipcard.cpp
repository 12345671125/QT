/****************************************************************************
** Meta object code from reading C++ file 'tipcard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tipcard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tipcard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TipCard_t {
    QByteArrayData data[12];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TipCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TipCard_t qt_meta_stringdata_TipCard = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TipCard"
QT_MOC_LITERAL(1, 8, 12), // "signalClosed"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "TipCard*"
QT_MOC_LITERAL(4, 31, 4), // "card"
QT_MOC_LITERAL(5, 36, 17), // "signalCardClicked"
QT_MOC_LITERAL(6, 54, 18), // "NotificationEntry*"
QT_MOC_LITERAL(7, 73, 4), // "noti"
QT_MOC_LITERAL(8, 78, 20), // "signalButton1Clicked"
QT_MOC_LITERAL(9, 99, 20), // "signalButton2Clicked"
QT_MOC_LITERAL(10, 120, 20), // "signalButton3Clicked"
QT_MOC_LITERAL(11, 141, 10) // "slotClosed"

    },
    "TipCard\0signalClosed\0\0TipCard*\0card\0"
    "signalCardClicked\0NotificationEntry*\0"
    "noti\0signalButton1Clicked\0"
    "signalButton2Clicked\0signalButton3Clicked\0"
    "slotClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TipCard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       8,    1,   50,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,
      10,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void TipCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TipCard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalClosed((*reinterpret_cast< TipCard*(*)>(_a[1]))); break;
        case 1: _t->signalCardClicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 2: _t->signalButton1Clicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 3: _t->signalButton2Clicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 4: _t->signalButton3Clicked((*reinterpret_cast< NotificationEntry*(*)>(_a[1]))); break;
        case 5: _t->slotClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TipCard* >(); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationEntry* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationEntry* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TipCard::*)(TipCard * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipCard::signalClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TipCard::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipCard::signalCardClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TipCard::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipCard::signalButton1Clicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TipCard::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipCard::signalButton2Clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TipCard::*)(NotificationEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TipCard::signalButton3Clicked)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TipCard::staticMetaObject = { {
    QMetaObject::SuperData::link<ThreeDimenButton::staticMetaObject>(),
    qt_meta_stringdata_TipCard.data,
    qt_meta_data_TipCard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TipCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TipCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TipCard.stringdata0))
        return static_cast<void*>(this);
    return ThreeDimenButton::qt_metacast(_clname);
}

int TipCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ThreeDimenButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TipCard::signalClosed(TipCard * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TipCard::signalCardClicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TipCard::signalButton1Clicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TipCard::signalButton2Clicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TipCard::signalButton3Clicked(NotificationEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
