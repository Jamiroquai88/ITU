/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata[494];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 23),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 28),
QT_MOC_LITERAL(4, 65, 29),
QT_MOC_LITERAL(5, 95, 23),
QT_MOC_LITERAL(6, 119, 23),
QT_MOC_LITERAL(7, 143, 22),
QT_MOC_LITERAL(8, 166, 22),
QT_MOC_LITERAL(9, 189, 11),
QT_MOC_LITERAL(10, 201, 9),
QT_MOC_LITERAL(11, 211, 10),
QT_MOC_LITERAL(12, 222, 26),
QT_MOC_LITERAL(13, 249, 5),
QT_MOC_LITERAL(14, 255, 31),
QT_MOC_LITERAL(15, 287, 4),
QT_MOC_LITERAL(16, 292, 23),
QT_MOC_LITERAL(17, 316, 23),
QT_MOC_LITERAL(18, 340, 26),
QT_MOC_LITERAL(19, 367, 27),
QT_MOC_LITERAL(20, 395, 29),
QT_MOC_LITERAL(21, 425, 32),
QT_MOC_LITERAL(22, 458, 34)
    },
    "MainWindow\0on_actionExit_triggered\0\0"
    "on_actionNew_Scene_triggered\0"
    "on_actionLoad_Scene_triggered\0"
    "on_renderButton_clicked\0on_objectButton_clicked\0"
    "on_lightButton_clicked\0on_resetButton_clicked\0"
    "s_addSphere\0s_addCube\0s_addPlane\0"
    "on_sizeSlider_valueChanged\0value\0"
    "on_colorBox_currentIndexChanged\0arg1\0"
    "on_nameEdit_textChanged\0on_removeButton_clicked\0"
    "on_reflSlider_valueChanged\0"
    "on_gammaSlider_valueChanged\0"
    "on_actionSave_Scene_triggered\0"
    "on_actionSave_Scene_As_triggered\0"
    "on_actionRender_Settings_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08,
       3,    0,  110,    2, 0x08,
       4,    0,  111,    2, 0x08,
       5,    0,  112,    2, 0x08,
       6,    0,  113,    2, 0x08,
       7,    0,  114,    2, 0x08,
       8,    0,  115,    2, 0x08,
       9,    0,  116,    2, 0x08,
      10,    0,  117,    2, 0x08,
      11,    0,  118,    2, 0x08,
      12,    1,  119,    2, 0x08,
      14,    1,  122,    2, 0x08,
      16,    0,  125,    2, 0x08,
      17,    0,  126,    2, 0x08,
      18,    1,  127,    2, 0x08,
      19,    1,  130,    2, 0x08,
      20,    0,  133,    2, 0x08,
      21,    0,  134,    2, 0x08,
      22,    0,  135,    2, 0x08,

 // slots: parameters
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
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_actionNew_Scene_triggered(); break;
        case 2: _t->on_actionLoad_Scene_triggered(); break;
        case 3: _t->on_renderButton_clicked(); break;
        case 4: _t->on_objectButton_clicked(); break;
        case 5: _t->on_lightButton_clicked(); break;
        case 6: _t->on_resetButton_clicked(); break;
        case 7: _t->s_addSphere(); break;
        case 8: _t->s_addCube(); break;
        case 9: _t->s_addPlane(); break;
        case 10: _t->on_sizeSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_colorBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_nameEdit_textChanged(); break;
        case 13: _t->on_removeButton_clicked(); break;
        case 14: _t->on_reflSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_gammaSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_actionSave_Scene_triggered(); break;
        case 17: _t->on_actionSave_Scene_As_triggered(); break;
        case 18: _t->on_actionRender_Settings_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
