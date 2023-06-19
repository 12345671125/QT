/****************************************************************************
** Meta object code from reading C++ file 'desktoplyricwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../desktoplyricwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktoplyricwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DesktopLyricWidget_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DesktopLyricWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DesktopLyricWidget_t qt_meta_stringdata_DesktopLyricWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DesktopLyricWidget"
QT_MOC_LITERAL(1, 19, 10), // "signalhide"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "signalSWitchTrans"
QT_MOC_LITERAL(4, 49, 8), // "showMenu"
QT_MOC_LITERAL(5, 58, 11), // "setPosition"
QT_MOC_LITERAL(6, 70, 8) // "position"

    },
    "DesktopLyricWidget\0signalhide\0\0"
    "signalSWitchTrans\0showMenu\0setPosition\0"
    "position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DesktopLyricWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    6,

       0        // eod
};

void DesktopLyricWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DesktopLyricWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalhide(); break;
        case 1: _t->signalSWitchTrans(); break;
        case 2: _t->showMenu(); break;
        case 3: _t->setPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DesktopLyricWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DesktopLyricWidget::signalhide)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DesktopLyricWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DesktopLyricWidget::signalSWitchTrans)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DesktopLyricWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DesktopLyricWidget.data,
    qt_meta_data_DesktopLyricWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DesktopLyricWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopLyricWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DesktopLyricWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DesktopLyricWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DesktopLyricWidget::signalhide()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DesktopLyricWidget::signalSWitchTrans()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
