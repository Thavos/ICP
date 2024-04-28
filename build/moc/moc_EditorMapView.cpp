/****************************************************************************
** Meta object code from reading C++ file 'EditorMapView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/view/EditorMapView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditorMapView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditorMapView_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditorMapView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditorMapView_t qt_meta_stringdata_EditorMapView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EditorMapView"
QT_MOC_LITERAL(1, 14, 10), // "robotAdded"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "position"
QT_MOC_LITERAL(4, 35, 13), // "obstacleAdded"
QT_MOC_LITERAL(5, 49, 20), // "robotPositionChanged"
QT_MOC_LITERAL(6, 70, 8), // "Vector2D"
QT_MOC_LITERAL(7, 79, 6), // "newPos"
QT_MOC_LITERAL(8, 86, 6), // "oldPos"
QT_MOC_LITERAL(9, 93, 23) // "obstaclePositionChanged"

    },
    "EditorMapView\0robotAdded\0\0position\0"
    "obstacleAdded\0robotPositionChanged\0"
    "Vector2D\0newPos\0oldPos\0obstaclePositionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditorMapView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    2,   40,    2, 0x06 /* Public */,
       9,    2,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,

       0        // eod
};

void EditorMapView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditorMapView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->robotAdded((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->obstacleAdded((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->robotPositionChanged((*reinterpret_cast< const Vector2D(*)>(_a[1])),(*reinterpret_cast< const Vector2D(*)>(_a[2]))); break;
        case 3: _t->obstaclePositionChanged((*reinterpret_cast< const Vector2D(*)>(_a[1])),(*reinterpret_cast< const Vector2D(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditorMapView::*)(const QPointF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorMapView::robotAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EditorMapView::*)(const QPointF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorMapView::obstacleAdded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EditorMapView::*)(const Vector2D & , const Vector2D & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorMapView::robotPositionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EditorMapView::*)(const Vector2D & , const Vector2D & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorMapView::obstaclePositionChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditorMapView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_EditorMapView.data,
    qt_meta_data_EditorMapView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditorMapView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditorMapView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditorMapView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int EditorMapView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void EditorMapView::robotAdded(const QPointF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EditorMapView::obstacleAdded(const QPointF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EditorMapView::robotPositionChanged(const Vector2D & _t1, const Vector2D & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EditorMapView::obstaclePositionChanged(const Vector2D & _t1, const Vector2D & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
