/****************************************************************************
** Meta object code from reading C++ file 'bitcoinunits.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/bitcoinunits.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitcoinunits.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BitcoinUnits_t {
    QByteArrayData data[6];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BitcoinUnits_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BitcoinUnits_t qt_meta_stringdata_BitcoinUnits = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BitcoinUnits"
QT_MOC_LITERAL(1, 13, 4), // "Unit"
QT_MOC_LITERAL(2, 18, 3), // "BTC"
QT_MOC_LITERAL(3, 22, 4), // "mBTC"
QT_MOC_LITERAL(4, 27, 4), // "uBTC"
QT_MOC_LITERAL(5, 32, 3) // "SAT"

    },
    "BitcoinUnits\0Unit\0BTC\0mBTC\0uBTC\0SAT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BitcoinUnits[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x2,    4,   19,

 // enum data: key, value
       2, uint(BitcoinUnits::Unit::BTC),
       3, uint(BitcoinUnits::Unit::mBTC),
       4, uint(BitcoinUnits::Unit::uBTC),
       5, uint(BitcoinUnits::Unit::SAT),

       0        // eod
};

void BitcoinUnits::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject BitcoinUnits::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BitcoinUnits.data,
    qt_meta_data_BitcoinUnits,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BitcoinUnits::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BitcoinUnits::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BitcoinUnits.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BitcoinUnits::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
