/****************************************************************************
** Meta object code from reading C++ file 'managenamespage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/managenamespage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managenamespage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageNamesPage_t {
    QByteArrayData data[18];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageNamesPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageNamesPage_t qt_meta_stringdata_ManageNamesPage = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ManageNamesPage"
QT_MOC_LITERAL(1, 16, 7), // "message"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "title"
QT_MOC_LITERAL(4, 31, 5), // "style"
QT_MOC_LITERAL(5, 37, 11), // "eventFilter"
QT_MOC_LITERAL(6, 49, 6), // "object"
QT_MOC_LITERAL(7, 56, 7), // "QEvent*"
QT_MOC_LITERAL(8, 64, 5), // "event"
QT_MOC_LITERAL(9, 70, 16), // "selectionChanged"
QT_MOC_LITERAL(10, 87, 15), // "rowCountChanged"
QT_MOC_LITERAL(11, 103, 14), // "contextualMenu"
QT_MOC_LITERAL(12, 118, 5), // "point"
QT_MOC_LITERAL(13, 124, 16), // "onCopyNameAction"
QT_MOC_LITERAL(14, 141, 17), // "onCopyValueAction"
QT_MOC_LITERAL(15, 159, 21), // "onConfigureNameAction"
QT_MOC_LITERAL(16, 181, 17), // "onRenewNameAction"
QT_MOC_LITERAL(17, 199, 8) // "onExport"

    },
    "ManageNamesPage\0message\0\0title\0style\0"
    "eventFilter\0object\0QEvent*\0event\0"
    "selectionChanged\0rowCountChanged\0"
    "contextualMenu\0point\0onCopyNameAction\0"
    "onCopyValueAction\0onConfigureNameAction\0"
    "onRenewNameAction\0onExport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageNamesPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   71,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,
      16,    0,   84,    2, 0x08 /* Private */,
      17,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    1,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManageNamesPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageNamesPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->selectionChanged(); break;
        case 3: _t->rowCountChanged(); break;
        case 4: _t->contextualMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->onCopyNameAction(); break;
        case 6: _t->onCopyValueAction(); break;
        case 7: _t->onConfigureNameAction(); break;
        case 8: _t->onRenewNameAction(); break;
        case 9: _t->onExport(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManageNamesPage::*)(const QString & , const QString & , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManageNamesPage::message)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageNamesPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ManageNamesPage.data,
    qt_meta_data_ManageNamesPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageNamesPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageNamesPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageNamesPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ManageNamesPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ManageNamesPage::message(const QString & _t1, const QString & _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
