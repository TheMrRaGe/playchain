/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/optionsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProxyAddressValidator_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProxyAddressValidator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProxyAddressValidator_t qt_meta_stringdata_ProxyAddressValidator = {
    {
QT_MOC_LITERAL(0, 0, 21) // "ProxyAddressValidator"

    },
    "ProxyAddressValidator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProxyAddressValidator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ProxyAddressValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ProxyAddressValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QValidator::staticMetaObject>(),
    qt_meta_stringdata_ProxyAddressValidator.data,
    qt_meta_data_ProxyAddressValidator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProxyAddressValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyAddressValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyAddressValidator.stringdata0))
        return static_cast<void*>(this);
    return QValidator::qt_metacast(_clname);
}

int ProxyAddressValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_OptionsDialog_t {
    QByteArrayData data[23];
    char stringdata0[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsDialog_t qt_meta_stringdata_OptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionsDialog"
QT_MOC_LITERAL(1, 14, 13), // "proxyIpChecks"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "QValidatedLineEdit*"
QT_MOC_LITERAL(4, 49, 10), // "pUiProxyIp"
QT_MOC_LITERAL(5, 60, 8), // "uint16_t"
QT_MOC_LITERAL(6, 69, 10), // "nProxyPort"
QT_MOC_LITERAL(7, 80, 11), // "quitOnReset"
QT_MOC_LITERAL(8, 92, 16), // "setOkButtonState"
QT_MOC_LITERAL(9, 109, 6), // "fState"
QT_MOC_LITERAL(10, 116, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(11, 139, 32), // "on_openBitcoinConfButton_clicked"
QT_MOC_LITERAL(12, 172, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(13, 192, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(14, 216, 28), // "on_showTrayIcon_stateChanged"
QT_MOC_LITERAL(15, 245, 5), // "state"
QT_MOC_LITERAL(16, 251, 18), // "togglePruneWarning"
QT_MOC_LITERAL(17, 270, 7), // "enabled"
QT_MOC_LITERAL(18, 278, 18), // "showRestartWarning"
QT_MOC_LITERAL(19, 297, 11), // "fPersistent"
QT_MOC_LITERAL(20, 309, 16), // "clearStatusLabel"
QT_MOC_LITERAL(21, 326, 26), // "updateProxyValidationState"
QT_MOC_LITERAL(22, 353, 22) // "updateDefaultProxyNets"

    },
    "OptionsDialog\0proxyIpChecks\0\0"
    "QValidatedLineEdit*\0pUiProxyIp\0uint16_t\0"
    "nProxyPort\0quitOnReset\0setOkButtonState\0"
    "fState\0on_resetButton_clicked\0"
    "on_openBitcoinConfButton_clicked\0"
    "on_okButton_clicked\0on_cancelButton_clicked\0"
    "on_showTrayIcon_stateChanged\0state\0"
    "togglePruneWarning\0enabled\0"
    "showRestartWarning\0fPersistent\0"
    "clearStatusLabel\0updateProxyValidationState\0"
    "updateDefaultProxyNets"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   90,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    1,  100,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x28 /* Private | MethodCloned */,
      20,    0,  107,    2, 0x08 /* Private */,
      21,    0,  108,    2, 0x08 /* Private */,
      22,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OptionsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->proxyIpChecks((*reinterpret_cast< QValidatedLineEdit*(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 1: _t->quitOnReset(); break;
        case 2: _t->setOkButtonState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_resetButton_clicked(); break;
        case 4: _t->on_openBitcoinConfButton_clicked(); break;
        case 5: _t->on_okButton_clicked(); break;
        case 6: _t->on_cancelButton_clicked(); break;
        case 7: _t->on_showTrayIcon_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->togglePruneWarning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->showRestartWarning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showRestartWarning(); break;
        case 11: _t->clearStatusLabel(); break;
        case 12: _t->updateProxyValidationState(); break;
        case 13: _t->updateDefaultProxyNets(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionsDialog::*)(QValidatedLineEdit * , uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsDialog::proxyIpChecks)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsDialog::quitOnReset)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OptionsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_OptionsDialog.data,
    qt_meta_data_OptionsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void OptionsDialog::proxyIpChecks(QValidatedLineEdit * _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OptionsDialog::quitOnReset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
