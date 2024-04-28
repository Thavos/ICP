/****************************************************************************
** Meta object code from reading C++ file 'EditorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/view/EditorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditorDialog_t {
    QByteArrayData data[11];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditorDialog_t qt_meta_stringdata_EditorDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EditorDialog"
QT_MOC_LITERAL(1, 13, 14), // "handleAddRobot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "position"
QT_MOC_LITERAL(4, 38, 17), // "handleAddObstacle"
QT_MOC_LITERAL(5, 56, 26), // "handleRobotPositionChanged"
QT_MOC_LITERAL(6, 83, 8), // "Vector2D"
QT_MOC_LITERAL(7, 92, 6), // "newPos"
QT_MOC_LITERAL(8, 99, 6), // "oldPos"
QT_MOC_LITERAL(9, 106, 29), // "handleObstaclePositionChanged"
QT_MOC_LITERAL(10, 136, 17) // "updateRobotParams"

    },
    "EditorDialog\0handleAddRobot\0\0position\0"
    "handleAddObstacle\0handleRobotPositionChanged\0"
    "Vector2D\0newPos\0oldPos\0"
    "handleObstaclePositionChanged\0"
    "updateRobotParams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    2,   45,    2, 0x08 /* Private */,
       9,    2,   50,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void EditorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditorDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleAddRobot((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->handleAddObstacle((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->handleRobotPositionChanged((*reinterpret_cast< const Vector2D(*)>(_a[1])),(*reinterpret_cast< const Vector2D(*)>(_a[2]))); break;
        case 3: _t->handleObstaclePositionChanged((*reinterpret_cast< const Vector2D(*)>(_a[1])),(*reinterpret_cast< const Vector2D(*)>(_a[2]))); break;
        case 4: _t->updateRobotParams(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EditorDialog.data,
    qt_meta_data_EditorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
