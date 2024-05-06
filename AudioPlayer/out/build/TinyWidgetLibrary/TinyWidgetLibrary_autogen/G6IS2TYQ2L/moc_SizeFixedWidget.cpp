/****************************************************************************
** Meta object code from reading C++ file 'SizeFixedWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TinyWidgetLibrary/MyWidget/Helper/Window/SizeFixedWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SizeFixedWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::CoverWidget",
    "makeOpaque",
    "",
    "makeTransparent",
    "opacity",
    "margin_top",
    "margin_left"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[31];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[8];
    char stringdata5[11];
    char stringdata6[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 30),  // "TinyWidgetLibrary::CoverWidget"
        QT_MOC_LITERAL(31, 10),  // "makeOpaque"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 15),  // "makeTransparent"
        QT_MOC_LITERAL(59, 7),  // "opacity"
        QT_MOC_LITERAL(67, 10),  // "margin_top"
        QT_MOC_LITERAL(78, 11)   // "margin_left"
    },
    "TinyWidgetLibrary::CoverWidget",
    "makeOpaque",
    "",
    "makeTransparent",
    "opacity",
    "margin_top",
    "margin_left"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    4 /* Public */,
       3,    0,   27,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00015103, uint(-1), 0,
       5, QMetaType::Int, 0x00015003, uint(-1), 0,
       6, QMetaType::Int, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::CoverWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS_t,
        // property 'opacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'margin_top'
        QtPrivate::TypeAndForceComplete<qint32, std::true_type>,
        // property 'margin_left'
        QtPrivate::TypeAndForceComplete<qint32, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CoverWidget, std::true_type>,
        // method 'makeOpaque'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makeTransparent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::CoverWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoverWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->makeOpaque(); break;
        case 1: _t->makeTransparent(); break;
        default: ;
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CoverWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getOpacity(); break;
        case 1: *reinterpret_cast< qint32*>(_v) = _t->getMarginTop(); break;
        case 2: *reinterpret_cast< qint32*>(_v) = _t->getMarginLeft(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CoverWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setMarginTop(*reinterpret_cast< qint32*>(_v)); break;
        case 2: _t->setMarginLeft(*reinterpret_cast< qint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *TinyWidgetLibrary::CoverWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::CoverWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECoverWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TinyWidgetLibrary::CoverWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::TargetWidget"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 31)   // "TinyWidgetLibrary::TargetWidget"
    },
    "TinyWidgetLibrary::TargetWidget"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS[] = {

 // content:
      11,       // revision
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

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::TargetWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TargetWidget, std::true_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::TargetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *TinyWidgetLibrary::TargetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::TargetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPETargetWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TinyWidgetLibrary::TargetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
