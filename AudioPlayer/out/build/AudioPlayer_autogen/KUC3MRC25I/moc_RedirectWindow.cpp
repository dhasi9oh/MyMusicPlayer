/****************************************************************************
** Meta object code from reading C++ file 'RedirectWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/Window/RedirectWindow.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RedirectWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSRedirectWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRedirectWindowENDCLASS = QtMocHelpers::stringData(
    "RedirectWindow",
    "slotSwitchLogin",
    "",
    "slotSwitchReset",
    "slotSwitchRegister",
    "slotSwitchMain",
    "obj"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRedirectWindowENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[15];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[19];
    char stringdata5[15];
    char stringdata6[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRedirectWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRedirectWindowENDCLASS_t qt_meta_stringdata_CLASSRedirectWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "RedirectWindow"
        QT_MOC_LITERAL(15, 15),  // "slotSwitchLogin"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 15),  // "slotSwitchReset"
        QT_MOC_LITERAL(48, 18),  // "slotSwitchRegister"
        QT_MOC_LITERAL(67, 14),  // "slotSwitchMain"
        QT_MOC_LITERAL(82, 3)   // "obj"
    },
    "RedirectWindow",
    "slotSwitchLogin",
    "",
    "slotSwitchReset",
    "slotSwitchRegister",
    "slotSwitchMain",
    "obj"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRedirectWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    1,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject RedirectWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSRedirectWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRedirectWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRedirectWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RedirectWindow, std::true_type>,
        // method 'slotSwitchLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSwitchReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSwitchRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSwitchMain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>
    >,
    nullptr
} };

void RedirectWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RedirectWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotSwitchLogin(); break;
        case 1: _t->slotSwitchReset(); break;
        case 2: _t->slotSwitchRegister(); break;
        case 3: _t->slotSwitchMain((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *RedirectWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RedirectWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRedirectWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RedirectWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP