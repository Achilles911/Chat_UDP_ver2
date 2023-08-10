/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "ReadingData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "CountingDate"
QT_MOC_LITERAL(4, 37, 12), // "PhotoProfile"
QT_MOC_LITERAL(5, 50, 1), // "a"
QT_MOC_LITERAL(6, 52, 8), // "SaveFile"
QT_MOC_LITERAL(7, 61, 11), // "QByteArray&"
QT_MOC_LITERAL(8, 73, 8), // "datagram"
QT_MOC_LITERAL(9, 82, 14), // "sendingPackets"
QT_MOC_LITERAL(10, 97, 6), // "choise"
QT_MOC_LITERAL(11, 104, 11), // "updateLabel"
QT_MOC_LITERAL(12, 116, 22), // "on_SendingData_clicked"
QT_MOC_LITERAL(13, 139, 21), // "on_selectFile_clicked"
QT_MOC_LITERAL(14, 161, 27), // "on_selectPortButton_clicked"
QT_MOC_LITERAL(15, 189, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 211, 27), // "on_switchPacketSize_clicked"
QT_MOC_LITERAL(17, 239, 26), // "on_selectFrequency_clicked"
QT_MOC_LITERAL(18, 266, 29), // "on_debugCheckBox_stateChanged"
QT_MOC_LITERAL(19, 296, 4) // "arg1"

    },
    "MainWindow\0ReadingData\0\0CountingDate\0"
    "PhotoProfile\0a\0SaveFile\0QByteArray&\0"
    "datagram\0sendingPackets\0choise\0"
    "updateLabel\0on_SendingData_clicked\0"
    "on_selectFile_clicked\0on_selectPortButton_clicked\0"
    "on_pushButton_clicked\0on_switchPacketSize_clicked\0"
    "on_selectFrequency_clicked\0"
    "on_debugCheckBox_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    1,   81,    2, 0x0a /* Public */,
       6,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::QByteArray, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReadingData(); break;
        case 1: { QString _r = _t->CountingDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->PhotoProfile((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QByteArray _r = _t->SaveFile((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->sendingPackets((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateLabel(); break;
        case 6: _t->on_SendingData_clicked(); break;
        case 7: _t->on_selectFile_clicked(); break;
        case 8: _t->on_selectPortButton_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_switchPacketSize_clicked(); break;
        case 11: _t->on_selectFrequency_clicked(); break;
        case 12: _t->on_debugCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
