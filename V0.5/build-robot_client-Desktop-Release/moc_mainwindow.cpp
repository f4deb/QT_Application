/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../robot_client/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[52];
    char stringdata0[1389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "donneesRecues"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "connecte"
QT_MOC_LITERAL(4, 35, 10), // "deconnecte"
QT_MOC_LITERAL(5, 46, 12), // "erreurSocket"
QT_MOC_LITERAL(6, 59, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 88, 6), // "erreur"
QT_MOC_LITERAL(8, 95, 25), // "on_pushButtonQuit_clicked"
QT_MOC_LITERAL(9, 121, 24), // "on_buttonQuitter_clicked"
QT_MOC_LITERAL(10, 146, 24), // "on_actionQuitter_changed"
QT_MOC_LITERAL(11, 171, 24), // "on_actionQuitter_toggled"
QT_MOC_LITERAL(12, 196, 4), // "arg1"
QT_MOC_LITERAL(13, 201, 26), // "on_actionQuitter_triggered"
QT_MOC_LITERAL(14, 228, 27), // "on_actionA_propos_triggered"
QT_MOC_LITERAL(15, 256, 25), // "on_Serial_Connect_clicked"
QT_MOC_LITERAL(16, 282, 37), // "on_Serial_Baudrate_currentTex..."
QT_MOC_LITERAL(17, 320, 24), // "on_Serial_Port_activated"
QT_MOC_LITERAL(18, 345, 34), // "on_Serial_Port_currentIndexCh..."
QT_MOC_LITERAL(19, 380, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(20, 421, 8), // "readData"
QT_MOC_LITERAL(21, 430, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(22, 471, 28), // "on_plainTextEdit_textChanged"
QT_MOC_LITERAL(23, 500, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(24, 541, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(25, 582, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(26, 623, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(27, 664, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(28, 705, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(29, 746, 40), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(30, 787, 41), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(31, 829, 41), // "on_pushButton_Command_Termina..."
QT_MOC_LITERAL(32, 871, 25), // "on_Telnet_Connect_clicked"
QT_MOC_LITERAL(33, 897, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(34, 919, 26), // "on_pushButtonReset_clicked"
QT_MOC_LITERAL(35, 946, 30), // "on_pushButtonStopMotor_clicked"
QT_MOC_LITERAL(36, 977, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(37, 1001, 31), // "on_resetLeftTrackSlider_clicked"
QT_MOC_LITERAL(38, 1033, 32), // "on_resetRightTrackSlider_clicked"
QT_MOC_LITERAL(39, 1066, 31), // "on_leftTrackSlider_valueChanged"
QT_MOC_LITERAL(40, 1098, 5), // "value"
QT_MOC_LITERAL(41, 1104, 32), // "on_rightTrackSlider_valueChanged"
QT_MOC_LITERAL(42, 1137, 32), // "on_pushButton_StropTrack_clicked"
QT_MOC_LITERAL(43, 1170, 24), // "on_radioButton_Y_toggled"
QT_MOC_LITERAL(44, 1195, 7), // "checked"
QT_MOC_LITERAL(45, 1203, 24), // "on_radioButton_X_toggled"
QT_MOC_LITERAL(46, 1228, 24), // "on_radioButton_B_toggled"
QT_MOC_LITERAL(47, 1253, 24), // "on_radioButton_A_toggled"
QT_MOC_LITERAL(48, 1278, 25), // "on_radioButton_Up_toggled"
QT_MOC_LITERAL(49, 1304, 27), // "on_radioButton_Left_toggled"
QT_MOC_LITERAL(50, 1332, 27), // "on_radioButton_Down_toggled"
QT_MOC_LITERAL(51, 1360, 28) // "on_radioButton_Right_toggled"

    },
    "MainWindow\0donneesRecues\0\0connecte\0"
    "deconnecte\0erreurSocket\0"
    "QAbstractSocket::SocketError\0erreur\0"
    "on_pushButtonQuit_clicked\0"
    "on_buttonQuitter_clicked\0"
    "on_actionQuitter_changed\0"
    "on_actionQuitter_toggled\0arg1\0"
    "on_actionQuitter_triggered\0"
    "on_actionA_propos_triggered\0"
    "on_Serial_Connect_clicked\0"
    "on_Serial_Baudrate_currentTextChanged\0"
    "on_Serial_Port_activated\0"
    "on_Serial_Port_currentIndexChanged\0"
    "on_pushButton_Command_Terminal_1_clicked\0"
    "readData\0on_pushButton_Command_Terminal_2_clicked\0"
    "on_plainTextEdit_textChanged\0"
    "on_pushButton_Command_Terminal_3_clicked\0"
    "on_pushButton_Command_Terminal_4_clicked\0"
    "on_pushButton_Command_Terminal_5_clicked\0"
    "on_pushButton_Command_Terminal_6_clicked\0"
    "on_pushButton_Command_Terminal_7_clicked\0"
    "on_pushButton_Command_Terminal_8_clicked\0"
    "on_pushButton_Command_Terminal_9_clicked\0"
    "on_pushButton_Command_Terminal_10_clicked\0"
    "on_pushButton_Command_Terminal_11_clicked\0"
    "on_Telnet_Connect_clicked\0"
    "on_pushButton_clicked\0on_pushButtonReset_clicked\0"
    "on_pushButtonStopMotor_clicked\0"
    "on_pushButton_2_clicked\0"
    "on_resetLeftTrackSlider_clicked\0"
    "on_resetRightTrackSlider_clicked\0"
    "on_leftTrackSlider_valueChanged\0value\0"
    "on_rightTrackSlider_valueChanged\0"
    "on_pushButton_StropTrack_clicked\0"
    "on_radioButton_Y_toggled\0checked\0"
    "on_radioButton_X_toggled\0"
    "on_radioButton_B_toggled\0"
    "on_radioButton_A_toggled\0"
    "on_radioButton_Up_toggled\0"
    "on_radioButton_Left_toggled\0"
    "on_radioButton_Down_toggled\0"
    "on_radioButton_Right_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  239,    2, 0x08 /* Private */,
       3,    0,  240,    2, 0x08 /* Private */,
       4,    0,  241,    2, 0x08 /* Private */,
       5,    1,  242,    2, 0x08 /* Private */,
       8,    0,  245,    2, 0x08 /* Private */,
       9,    0,  246,    2, 0x08 /* Private */,
      10,    0,  247,    2, 0x08 /* Private */,
      11,    1,  248,    2, 0x08 /* Private */,
      13,    0,  251,    2, 0x08 /* Private */,
      14,    0,  252,    2, 0x08 /* Private */,
      15,    0,  253,    2, 0x08 /* Private */,
      16,    1,  254,    2, 0x08 /* Private */,
      17,    1,  257,    2, 0x08 /* Private */,
      18,    1,  260,    2, 0x08 /* Private */,
      19,    0,  263,    2, 0x08 /* Private */,
      20,    0,  264,    2, 0x08 /* Private */,
      21,    0,  265,    2, 0x08 /* Private */,
      22,    0,  266,    2, 0x08 /* Private */,
      23,    0,  267,    2, 0x08 /* Private */,
      24,    0,  268,    2, 0x08 /* Private */,
      25,    0,  269,    2, 0x08 /* Private */,
      26,    0,  270,    2, 0x08 /* Private */,
      27,    0,  271,    2, 0x08 /* Private */,
      28,    0,  272,    2, 0x08 /* Private */,
      29,    0,  273,    2, 0x08 /* Private */,
      30,    0,  274,    2, 0x08 /* Private */,
      31,    0,  275,    2, 0x08 /* Private */,
      32,    0,  276,    2, 0x08 /* Private */,
      33,    0,  277,    2, 0x08 /* Private */,
      34,    0,  278,    2, 0x08 /* Private */,
      35,    0,  279,    2, 0x08 /* Private */,
      36,    0,  280,    2, 0x08 /* Private */,
      37,    0,  281,    2, 0x08 /* Private */,
      38,    0,  282,    2, 0x08 /* Private */,
      39,    1,  283,    2, 0x08 /* Private */,
      41,    1,  286,    2, 0x08 /* Private */,
      42,    0,  289,    2, 0x08 /* Private */,
      43,    1,  290,    2, 0x08 /* Private */,
      45,    1,  293,    2, 0x08 /* Private */,
      46,    1,  296,    2, 0x08 /* Private */,
      47,    1,  299,    2, 0x08 /* Private */,
      48,    1,  302,    2, 0x08 /* Private */,
      49,    1,  305,    2, 0x08 /* Private */,
      50,    1,  308,    2, 0x08 /* Private */,
      51,    1,  311,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Bool,   44,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->donneesRecues(); break;
        case 1: _t->connecte(); break;
        case 2: _t->deconnecte(); break;
        case 3: _t->erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonQuit_clicked(); break;
        case 5: _t->on_buttonQuitter_clicked(); break;
        case 6: _t->on_actionQuitter_changed(); break;
        case 7: _t->on_actionQuitter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_actionQuitter_triggered(); break;
        case 9: _t->on_actionA_propos_triggered(); break;
        case 10: _t->on_Serial_Connect_clicked(); break;
        case 11: _t->on_Serial_Baudrate_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_Serial_Port_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_Serial_Port_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_Command_Terminal_1_clicked(); break;
        case 15: _t->readData(); break;
        case 16: _t->on_pushButton_Command_Terminal_2_clicked(); break;
        case 17: _t->on_plainTextEdit_textChanged(); break;
        case 18: _t->on_pushButton_Command_Terminal_3_clicked(); break;
        case 19: _t->on_pushButton_Command_Terminal_4_clicked(); break;
        case 20: _t->on_pushButton_Command_Terminal_5_clicked(); break;
        case 21: _t->on_pushButton_Command_Terminal_6_clicked(); break;
        case 22: _t->on_pushButton_Command_Terminal_7_clicked(); break;
        case 23: _t->on_pushButton_Command_Terminal_8_clicked(); break;
        case 24: _t->on_pushButton_Command_Terminal_9_clicked(); break;
        case 25: _t->on_pushButton_Command_Terminal_10_clicked(); break;
        case 26: _t->on_pushButton_Command_Terminal_11_clicked(); break;
        case 27: _t->on_Telnet_Connect_clicked(); break;
        case 28: _t->on_pushButton_clicked(); break;
        case 29: _t->on_pushButtonReset_clicked(); break;
        case 30: _t->on_pushButtonStopMotor_clicked(); break;
        case 31: _t->on_pushButton_2_clicked(); break;
        case 32: _t->on_resetLeftTrackSlider_clicked(); break;
        case 33: _t->on_resetRightTrackSlider_clicked(); break;
        case 34: _t->on_leftTrackSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_rightTrackSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_pushButton_StropTrack_clicked(); break;
        case 37: _t->on_radioButton_Y_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_radioButton_X_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_radioButton_B_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_radioButton_A_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_radioButton_Up_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_radioButton_Left_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_radioButton_Down_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_radioButton_Right_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE