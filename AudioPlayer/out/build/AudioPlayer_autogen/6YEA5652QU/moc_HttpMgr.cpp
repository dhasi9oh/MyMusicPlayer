/****************************************************************************
** Meta object code from reading C++ file 'HttpMgr.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/HttpMgr.h"
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
#error "The header file 'HttpMgr.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSHttpMgrENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHttpMgrENDCLASS = QtMocHelpers::stringData(
    "HttpMgr",
    "signalLoginMod",
    "",
    "ReqId",
    "ErrorCodes",
    "signalResetMod",
    "signalEnrollMod",
    "signalMusicMod",
    "signalHttpFinish",
    "Modules",
    "slotHttpFinish",
    "id",
    "res",
    "err",
    "mod",
    "json"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHttpMgrENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[11];
    char stringdata5[15];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[17];
    char stringdata9[8];
    char stringdata10[15];
    char stringdata11[3];
    char stringdata12[4];
    char stringdata13[4];
    char stringdata14[4];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHttpMgrENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHttpMgrENDCLASS_t qt_meta_stringdata_CLASSHttpMgrENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "HttpMgr"
        QT_MOC_LITERAL(8, 14),  // "signalLoginMod"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5),  // "ReqId"
        QT_MOC_LITERAL(30, 10),  // "ErrorCodes"
        QT_MOC_LITERAL(41, 14),  // "signalResetMod"
        QT_MOC_LITERAL(56, 15),  // "signalEnrollMod"
        QT_MOC_LITERAL(72, 14),  // "signalMusicMod"
        QT_MOC_LITERAL(87, 16),  // "signalHttpFinish"
        QT_MOC_LITERAL(104, 7),  // "Modules"
        QT_MOC_LITERAL(112, 14),  // "slotHttpFinish"
        QT_MOC_LITERAL(127, 2),  // "id"
        QT_MOC_LITERAL(130, 3),  // "res"
        QT_MOC_LITERAL(134, 3),  // "err"
        QT_MOC_LITERAL(138, 3),  // "mod"
        QT_MOC_LITERAL(142, 4)   // "json"
    },
    "HttpMgr",
    "signalLoginMod",
    "",
    "ReqId",
    "ErrorCodes",
    "signalResetMod",
    "signalEnrollMod",
    "signalMusicMod",
    "signalHttpFinish",
    "Modules",
    "slotHttpFinish",
    "id",
    "res",
    "err",
    "mod",
    "json"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHttpMgrENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   50,    2, 0x06,    1 /* Public */,
       5,    4,   59,    2, 0x06,    6 /* Public */,
       6,    4,   68,    2, 0x06,   11 /* Public */,
       7,    4,   77,    2, 0x06,   16 /* Public */,
       8,    5,   86,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    5,   97,    2, 0x08,   27 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::QJsonObject,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::QJsonObject,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::QJsonObject,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::QJsonObject,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, 0x80000000 | 9, QMetaType::QJsonObject,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4, 0x80000000 | 9, QMetaType::QJsonObject,   11,   12,   13,   14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject HttpMgr::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSHttpMgrENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHttpMgrENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHttpMgrENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HttpMgr, std::true_type>,
        // method 'signalLoginMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'signalResetMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'signalEnrollMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'signalMusicMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'signalHttpFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<Modules, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'slotHttpFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<Modules, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>
    >,
    nullptr
} };

void HttpMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpMgr *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLoginMod((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        case 1: _t->signalResetMod((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        case 2: _t->signalEnrollMod((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        case 3: _t->signalMusicMod((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        case 4: _t->signalHttpFinish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<Modules>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[5]))); break;
        case 5: _t->slotHttpFinish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<Modules>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpMgr::*)(ReqId , QByteArray , ErrorCodes , QJsonObject );
            if (_t _q_method = &HttpMgr::signalLoginMod; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QByteArray , ErrorCodes , QJsonObject );
            if (_t _q_method = &HttpMgr::signalResetMod; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QByteArray , ErrorCodes , QJsonObject );
            if (_t _q_method = &HttpMgr::signalEnrollMod; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QByteArray , ErrorCodes , QJsonObject );
            if (_t _q_method = &HttpMgr::signalMusicMod; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HttpMgr::*)(ReqId , QByteArray , ErrorCodes , Modules , QJsonObject );
            if (_t _q_method = &HttpMgr::signalHttpFinish; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *HttpMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHttpMgrENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<HttpMgr>"))
        return static_cast< Singleton<HttpMgr>*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<HttpMgr>"))
        return static_cast< std::enable_shared_from_this<HttpMgr>*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HttpMgr::signalLoginMod(ReqId _t1, QByteArray _t2, ErrorCodes _t3, QJsonObject _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpMgr::signalResetMod(ReqId _t1, QByteArray _t2, ErrorCodes _t3, QJsonObject _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HttpMgr::signalEnrollMod(ReqId _t1, QByteArray _t2, ErrorCodes _t3, QJsonObject _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HttpMgr::signalMusicMod(ReqId _t1, QByteArray _t2, ErrorCodes _t3, QJsonObject _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HttpMgr::signalHttpFinish(ReqId _t1, QByteArray _t2, ErrorCodes _t3, Modules _t4, QJsonObject _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
