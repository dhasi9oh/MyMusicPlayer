/****************************************************************************
** Meta object code from reading C++ file 'LoginWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/Window/LoginWindow.h"
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
#error "The header file 'LoginWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLoginWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLoginWindowENDCLASS = QtMocHelpers::stringData(
    "LoginWindow",
    "login_success",
    "",
    "register_button_clicked",
    "onLoginButtonClicked",
    "slotLoginModFinish",
    "ReqId",
    "id",
    "res",
    "ErrorCodes",
    "err",
    "json"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLoginWindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[21];
    char stringdata5[19];
    char stringdata6[6];
    char stringdata7[3];
    char stringdata8[4];
    char stringdata9[11];
    char stringdata10[4];
    char stringdata11[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLoginWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLoginWindowENDCLASS_t qt_meta_stringdata_CLASSLoginWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "LoginWindow"
        QT_MOC_LITERAL(12, 13),  // "login_success"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 23),  // "register_button_clicked"
        QT_MOC_LITERAL(51, 20),  // "onLoginButtonClicked"
        QT_MOC_LITERAL(72, 18),  // "slotLoginModFinish"
        QT_MOC_LITERAL(91, 5),  // "ReqId"
        QT_MOC_LITERAL(97, 2),  // "id"
        QT_MOC_LITERAL(100, 3),  // "res"
        QT_MOC_LITERAL(104, 10),  // "ErrorCodes"
        QT_MOC_LITERAL(115, 3),  // "err"
        QT_MOC_LITERAL(119, 4)   // "json"
    },
    "LoginWindow",
    "login_success",
    "",
    "register_button_clicked",
    "onLoginButtonClicked",
    "slotLoginModFinish",
    "ReqId",
    "id",
    "res",
    "ErrorCodes",
    "err",
    "json"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLoginWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       3,    0,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   42,    2, 0x08,    4 /* Private */,
       5,    4,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QByteArray, 0x80000000 | 9, QMetaType::QJsonObject,    7,    8,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject LoginWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<TinyWidgetLibrary::RemovableWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSLoginWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLoginWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLoginWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LoginWindow, std::true_type>,
        // method 'login_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'register_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLoginButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotLoginModFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>
    >,
    nullptr
} };

void LoginWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->login_success((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->register_button_clicked(); break;
        case 2: _t->onLoginButtonClicked(); break;
        case 3: _t->slotLoginModFinish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginWindow::*)(QJsonObject );
            if (_t _q_method = &LoginWindow::login_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginWindow::*)();
            if (_t _q_method = &LoginWindow::register_button_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *LoginWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLoginWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return TinyWidgetLibrary::RemovableWidget::qt_metacast(_clname);
}

int LoginWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TinyWidgetLibrary::RemovableWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LoginWindow::login_success(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginWindow::register_button_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
