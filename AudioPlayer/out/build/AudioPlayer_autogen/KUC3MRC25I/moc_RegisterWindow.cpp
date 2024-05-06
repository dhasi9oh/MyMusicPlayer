/****************************************************************************
** Meta object code from reading C++ file 'RegisterWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/Window/RegisterWindow.h"
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
#error "The header file 'RegisterWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRegisterWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRegisterWindowENDCLASS = QtMocHelpers::stringData(
    "RegisterWindow",
    "register_success",
    "",
    "cancel_button_clicked",
    "onRegisterButtonClicked",
    "onGetVarifyCodeButtonClicked",
    "slotRegsterModFinish",
    "ReqId",
    "id",
    "res",
    "ErrorCodes",
    "err",
    "json"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRegisterWindowENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[15];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[24];
    char stringdata5[29];
    char stringdata6[21];
    char stringdata7[6];
    char stringdata8[3];
    char stringdata9[4];
    char stringdata10[11];
    char stringdata11[4];
    char stringdata12[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRegisterWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRegisterWindowENDCLASS_t qt_meta_stringdata_CLASSRegisterWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "RegisterWindow"
        QT_MOC_LITERAL(15, 16),  // "register_success"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 21),  // "cancel_button_clicked"
        QT_MOC_LITERAL(55, 23),  // "onRegisterButtonClicked"
        QT_MOC_LITERAL(79, 28),  // "onGetVarifyCodeButtonClicked"
        QT_MOC_LITERAL(108, 20),  // "slotRegsterModFinish"
        QT_MOC_LITERAL(129, 5),  // "ReqId"
        QT_MOC_LITERAL(135, 2),  // "id"
        QT_MOC_LITERAL(138, 3),  // "res"
        QT_MOC_LITERAL(142, 10),  // "ErrorCodes"
        QT_MOC_LITERAL(153, 3),  // "err"
        QT_MOC_LITERAL(157, 4)   // "json"
    },
    "RegisterWindow",
    "register_success",
    "",
    "cancel_button_clicked",
    "onRegisterButtonClicked",
    "onGetVarifyCodeButtonClicked",
    "slotRegsterModFinish",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSRegisterWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    4,   48,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QByteArray, 0x80000000 | 10, QMetaType::QJsonObject,    8,    9,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject RegisterWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<TinyWidgetLibrary::RemovableWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSRegisterWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRegisterWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRegisterWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RegisterWindow, std::true_type>,
        // method 'register_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancel_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRegisterButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGetVarifyCodeButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRegsterModFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>
    >,
    nullptr
} };

void RegisterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RegisterWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->register_success(); break;
        case 1: _t->cancel_button_clicked(); break;
        case 2: _t->onRegisterButtonClicked(); break;
        case 3: _t->onGetVarifyCodeButtonClicked(); break;
        case 4: _t->slotRegsterModFinish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RegisterWindow::*)();
            if (_t _q_method = &RegisterWindow::register_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RegisterWindow::*)();
            if (_t _q_method = &RegisterWindow::cancel_button_clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *RegisterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRegisterWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return TinyWidgetLibrary::RemovableWidget::qt_metacast(_clname);
}

int RegisterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TinyWidgetLibrary::RemovableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RegisterWindow::register_success()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RegisterWindow::cancel_button_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
