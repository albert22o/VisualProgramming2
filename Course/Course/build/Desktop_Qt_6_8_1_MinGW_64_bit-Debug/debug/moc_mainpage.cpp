/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PageViewModels/mainpage.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8MainPageE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN8MainPageE = QtMocHelpers::stringData(
    "MainPage",
    "on_tableWidget_cellClicked",
    "",
    "row",
    "column",
    "on_startSession_clicked",
    "OnComputerLeaseTimeChanged",
    "Computer",
    "computer",
    "updatedTime",
    "OnComputerLeaseFinished",
    "OnNewSessionStarted",
    "Session&",
    "session",
    "on_endSession_clicked",
    "on_search_textChanged",
    "arg1",
    "on_clearButton_clicked",
    "on_tariff_activated",
    "index",
    "on_status_activated"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN8MainPageE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x08,    1 /* Private */,
       5,    0,   79,    2, 0x08,    4 /* Private */,
       6,    2,   80,    2, 0x08,    5 /* Private */,
      10,    1,   85,    2, 0x08,    8 /* Private */,
      11,    2,   88,    2, 0x08,   10 /* Private */,
      14,    0,   93,    2, 0x08,   13 /* Private */,
      15,    1,   94,    2, 0x08,   14 /* Private */,
      17,    0,   97,    2, 0x08,   16 /* Private */,
      18,    1,   98,    2, 0x08,   17 /* Private */,
      20,    1,  101,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 7,   13,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN8MainPageE.offsetsAndSizes,
    qt_meta_data_ZN8MainPageE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN8MainPageE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainPage, std::true_type>,
        // method 'on_tableWidget_cellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_startSession_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnComputerLeaseTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Computer &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'OnComputerLeaseFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Computer &, std::false_type>,
        // method 'OnNewSessionStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Session &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Computer &, std::false_type>,
        // method 'on_endSession_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_search_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_clearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tariff_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_status_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainPage *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_tableWidget_cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->on_startSession_clicked(); break;
        case 2: _t->OnComputerLeaseTimeChanged((*reinterpret_cast< std::add_pointer_t<Computer>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->OnComputerLeaseFinished((*reinterpret_cast< std::add_pointer_t<Computer>>(_a[1]))); break;
        case 4: _t->OnNewSessionStarted((*reinterpret_cast< std::add_pointer_t<Session&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Computer>>(_a[2]))); break;
        case 5: _t->on_endSession_clicked(); break;
        case 6: _t->on_search_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_clearButton_clicked(); break;
        case 8: _t->on_tariff_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_status_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN8MainPageE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
