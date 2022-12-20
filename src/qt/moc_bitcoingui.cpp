/****************************************************************************
** Meta object code from reading C++ file 'bitcoingui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/bitcoingui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitcoingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BitcoinGUI_t {
    QByteArrayData data[70];
    char stringdata0[925];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BitcoinGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BitcoinGUI_t qt_meta_stringdata_BitcoinGUI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BitcoinGUI"
QT_MOC_LITERAL(1, 11, 13), // "quitRequested"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "receivedURI"
QT_MOC_LITERAL(4, 38, 3), // "uri"
QT_MOC_LITERAL(5, 42, 12), // "consoleShown"
QT_MOC_LITERAL(6, 55, 11), // "RPCConsole*"
QT_MOC_LITERAL(7, 67, 7), // "console"
QT_MOC_LITERAL(8, 75, 10), // "setPrivacy"
QT_MOC_LITERAL(9, 86, 7), // "privacy"
QT_MOC_LITERAL(10, 94, 17), // "setNumConnections"
QT_MOC_LITERAL(11, 112, 5), // "count"
QT_MOC_LITERAL(12, 118, 16), // "setNetworkActive"
QT_MOC_LITERAL(13, 135, 14), // "network_active"
QT_MOC_LITERAL(14, 150, 12), // "setNumBlocks"
QT_MOC_LITERAL(15, 163, 9), // "blockDate"
QT_MOC_LITERAL(16, 173, 21), // "nVerificationProgress"
QT_MOC_LITERAL(17, 195, 8), // "SyncType"
QT_MOC_LITERAL(18, 204, 8), // "synctype"
QT_MOC_LITERAL(19, 213, 20), // "SynchronizationState"
QT_MOC_LITERAL(20, 234, 10), // "sync_state"
QT_MOC_LITERAL(21, 245, 7), // "message"
QT_MOC_LITERAL(22, 253, 5), // "title"
QT_MOC_LITERAL(23, 259, 5), // "style"
QT_MOC_LITERAL(24, 265, 5), // "bool*"
QT_MOC_LITERAL(25, 271, 3), // "ret"
QT_MOC_LITERAL(26, 275, 16), // "detailed_message"
QT_MOC_LITERAL(27, 292, 16), // "setCurrentWallet"
QT_MOC_LITERAL(28, 309, 12), // "WalletModel*"
QT_MOC_LITERAL(29, 322, 12), // "wallet_model"
QT_MOC_LITERAL(30, 335, 31), // "setCurrentWalletBySelectorIndex"
QT_MOC_LITERAL(31, 367, 5), // "index"
QT_MOC_LITERAL(32, 373, 18), // "updateWalletStatus"
QT_MOC_LITERAL(33, 392, 20), // "handlePaymentRequest"
QT_MOC_LITERAL(34, 413, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(35, 432, 9), // "recipient"
QT_MOC_LITERAL(36, 442, 19), // "incomingTransaction"
QT_MOC_LITERAL(37, 462, 4), // "date"
QT_MOC_LITERAL(38, 467, 11), // "BitcoinUnit"
QT_MOC_LITERAL(39, 479, 4), // "unit"
QT_MOC_LITERAL(40, 484, 7), // "CAmount"
QT_MOC_LITERAL(41, 492, 6), // "amount"
QT_MOC_LITERAL(42, 499, 4), // "type"
QT_MOC_LITERAL(43, 504, 7), // "address"
QT_MOC_LITERAL(44, 512, 5), // "label"
QT_MOC_LITERAL(45, 518, 10), // "walletName"
QT_MOC_LITERAL(46, 529, 16), // "gotoOverviewPage"
QT_MOC_LITERAL(47, 546, 15), // "gotoHistoryPage"
QT_MOC_LITERAL(48, 562, 20), // "gotoReceiveCoinsPage"
QT_MOC_LITERAL(49, 583, 17), // "gotoSendCoinsPage"
QT_MOC_LITERAL(50, 601, 4), // "addr"
QT_MOC_LITERAL(51, 606, 16), // "gotoBuyNamesPage"
QT_MOC_LITERAL(52, 623, 19), // "gotoManageNamesPage"
QT_MOC_LITERAL(53, 643, 18), // "gotoSignMessageTab"
QT_MOC_LITERAL(54, 662, 20), // "gotoVerifyMessageTab"
QT_MOC_LITERAL(55, 683, 12), // "gotoLoadPSBT"
QT_MOC_LITERAL(56, 696, 14), // "from_clipboard"
QT_MOC_LITERAL(57, 711, 11), // "openClicked"
QT_MOC_LITERAL(58, 723, 14), // "optionsClicked"
QT_MOC_LITERAL(59, 738, 12), // "aboutClicked"
QT_MOC_LITERAL(60, 751, 15), // "showDebugWindow"
QT_MOC_LITERAL(61, 767, 30), // "showDebugWindowActivateConsole"
QT_MOC_LITERAL(62, 798, 22), // "showHelpMessageClicked"
QT_MOC_LITERAL(63, 821, 21), // "showNormalIfMinimized"
QT_MOC_LITERAL(64, 843, 13), // "fToggleHidden"
QT_MOC_LITERAL(65, 857, 12), // "toggleHidden"
QT_MOC_LITERAL(66, 870, 14), // "detectShutdown"
QT_MOC_LITERAL(67, 885, 12), // "showProgress"
QT_MOC_LITERAL(68, 898, 9), // "nProgress"
QT_MOC_LITERAL(69, 908, 16) // "showModalOverlay"

    },
    "BitcoinGUI\0quitRequested\0\0receivedURI\0"
    "uri\0consoleShown\0RPCConsole*\0console\0"
    "setPrivacy\0privacy\0setNumConnections\0"
    "count\0setNetworkActive\0network_active\0"
    "setNumBlocks\0blockDate\0nVerificationProgress\0"
    "SyncType\0synctype\0SynchronizationState\0"
    "sync_state\0message\0title\0style\0bool*\0"
    "ret\0detailed_message\0setCurrentWallet\0"
    "WalletModel*\0wallet_model\0"
    "setCurrentWalletBySelectorIndex\0index\0"
    "updateWalletStatus\0handlePaymentRequest\0"
    "SendCoinsRecipient\0recipient\0"
    "incomingTransaction\0date\0BitcoinUnit\0"
    "unit\0CAmount\0amount\0type\0address\0label\0"
    "walletName\0gotoOverviewPage\0gotoHistoryPage\0"
    "gotoReceiveCoinsPage\0gotoSendCoinsPage\0"
    "addr\0gotoBuyNamesPage\0gotoManageNamesPage\0"
    "gotoSignMessageTab\0gotoVerifyMessageTab\0"
    "gotoLoadPSBT\0from_clipboard\0openClicked\0"
    "optionsClicked\0aboutClicked\0showDebugWindow\0"
    "showDebugWindowActivateConsole\0"
    "showHelpMessageClicked\0showNormalIfMinimized\0"
    "fToggleHidden\0toggleHidden\0detectShutdown\0"
    "showProgress\0nProgress\0showModalOverlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BitcoinGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,
       3,    1,  215,    2, 0x06 /* Public */,
       5,    1,  218,    2, 0x06 /* Public */,
       8,    1,  221,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  224,    2, 0x0a /* Public */,
      12,    1,  227,    2, 0x0a /* Public */,
      14,    5,  230,    2, 0x0a /* Public */,
      21,    5,  241,    2, 0x0a /* Public */,
      21,    4,  252,    2, 0x2a /* Public | MethodCloned */,
      21,    3,  261,    2, 0x2a /* Public | MethodCloned */,
      27,    1,  268,    2, 0x0a /* Public */,
      30,    1,  271,    2, 0x0a /* Public */,
      32,    0,  274,    2, 0x0a /* Public */,
      33,    1,  275,    2, 0x0a /* Public */,
      36,    7,  278,    2, 0x0a /* Public */,
      46,    0,  293,    2, 0x0a /* Public */,
      47,    0,  294,    2, 0x0a /* Public */,
      48,    0,  295,    2, 0x0a /* Public */,
      49,    1,  296,    2, 0x0a /* Public */,
      49,    0,  299,    2, 0x2a /* Public | MethodCloned */,
      51,    0,  300,    2, 0x0a /* Public */,
      52,    0,  301,    2, 0x0a /* Public */,
      53,    1,  302,    2, 0x0a /* Public */,
      53,    0,  305,    2, 0x2a /* Public | MethodCloned */,
      54,    1,  306,    2, 0x0a /* Public */,
      54,    0,  309,    2, 0x2a /* Public | MethodCloned */,
      55,    1,  310,    2, 0x0a /* Public */,
      55,    0,  313,    2, 0x2a /* Public | MethodCloned */,
      57,    0,  314,    2, 0x0a /* Public */,
      58,    0,  315,    2, 0x0a /* Public */,
      59,    0,  316,    2, 0x0a /* Public */,
      60,    0,  317,    2, 0x0a /* Public */,
      61,    0,  318,    2, 0x0a /* Public */,
      62,    0,  319,    2, 0x0a /* Public */,
      63,    0,  320,    2, 0x0a /* Public */,
      63,    1,  321,    2, 0x0a /* Public */,
      65,    0,  324,    2, 0x0a /* Public */,
      66,    0,  325,    2, 0x0a /* Public */,
      67,    2,  326,    2, 0x0a /* Public */,
      69,    0,  331,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::Double, 0x80000000 | 17, 0x80000000 | 19,   11,   15,   16,   18,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt, 0x80000000 | 24, QMetaType::QString,   22,   21,   23,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt, 0x80000000 | 24,   22,   21,   23,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,   22,   21,   23,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 38, 0x80000000 | 40, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   37,   39,   41,   42,   43,   44,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   22,   68,
    QMetaType::Void,

       0        // eod
};

void BitcoinGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BitcoinGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->quitRequested(); break;
        case 1: _t->receivedURI((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->consoleShown((*reinterpret_cast< RPCConsole*(*)>(_a[1]))); break;
        case 3: _t->setPrivacy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< SyncType(*)>(_a[4])),(*reinterpret_cast< SynchronizationState(*)>(_a[5]))); break;
        case 7: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool*(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 8: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool*(*)>(_a[4]))); break;
        case 9: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 10: _t->setCurrentWallet((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        case 11: _t->setCurrentWalletBySelectorIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateWalletStatus(); break;
        case 13: { bool _r = _t->handlePaymentRequest((*reinterpret_cast< const SendCoinsRecipient(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->incomingTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< BitcoinUnit(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 15: _t->gotoOverviewPage(); break;
        case 16: _t->gotoHistoryPage(); break;
        case 17: _t->gotoReceiveCoinsPage(); break;
        case 18: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->gotoSendCoinsPage(); break;
        case 20: _t->gotoBuyNamesPage(); break;
        case 21: _t->gotoManageNamesPage(); break;
        case 22: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->gotoSignMessageTab(); break;
        case 24: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->gotoVerifyMessageTab(); break;
        case 26: _t->gotoLoadPSBT((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->gotoLoadPSBT(); break;
        case 28: _t->openClicked(); break;
        case 29: _t->optionsClicked(); break;
        case 30: _t->aboutClicked(); break;
        case 31: _t->showDebugWindow(); break;
        case 32: _t->showDebugWindowActivateConsole(); break;
        case 33: _t->showHelpMessageClicked(); break;
        case 34: _t->showNormalIfMinimized(); break;
        case 35: _t->showNormalIfMinimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->toggleHidden(); break;
        case 37: _t->detectShutdown(); break;
        case 38: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->showModalOverlay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BitcoinGUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::quitRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BitcoinGUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::receivedURI)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BitcoinGUI::*)(RPCConsole * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::consoleShown)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BitcoinGUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::setPrivacy)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BitcoinGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_BitcoinGUI.data,
    qt_meta_data_BitcoinGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BitcoinGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BitcoinGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BitcoinGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BitcoinGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void BitcoinGUI::quitRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BitcoinGUI::receivedURI(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BitcoinGUI::consoleShown(RPCConsole * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BitcoinGUI::setPrivacy(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_UnitDisplayStatusBarControl_t {
    QByteArrayData data[8];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitDisplayStatusBarControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitDisplayStatusBarControl_t qt_meta_stringdata_UnitDisplayStatusBarControl = {
    {
QT_MOC_LITERAL(0, 0, 27), // "UnitDisplayStatusBarControl"
QT_MOC_LITERAL(1, 28, 17), // "updateDisplayUnit"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 11), // "BitcoinUnit"
QT_MOC_LITERAL(4, 59, 8), // "newUnits"
QT_MOC_LITERAL(5, 68, 15), // "onMenuSelection"
QT_MOC_LITERAL(6, 84, 8), // "QAction*"
QT_MOC_LITERAL(7, 93, 6) // "action"

    },
    "UnitDisplayStatusBarControl\0"
    "updateDisplayUnit\0\0BitcoinUnit\0newUnits\0"
    "onMenuSelection\0QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitDisplayStatusBarControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void UnitDisplayStatusBarControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UnitDisplayStatusBarControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateDisplayUnit((*reinterpret_cast< BitcoinUnit(*)>(_a[1]))); break;
        case 1: _t->onMenuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UnitDisplayStatusBarControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_UnitDisplayStatusBarControl.data,
    qt_meta_data_UnitDisplayStatusBarControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UnitDisplayStatusBarControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitDisplayStatusBarControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitDisplayStatusBarControl.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int UnitDisplayStatusBarControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
