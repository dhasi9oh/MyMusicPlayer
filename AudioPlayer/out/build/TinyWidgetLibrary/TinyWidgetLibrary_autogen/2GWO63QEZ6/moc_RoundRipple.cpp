/****************************************************************************
** Meta object code from reading C++ file 'RoundRipple.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TinyWidgetLibrary/MyWidget/Helper/Ripple/RoundRipple.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoundRipple.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::RoundRipple",
    "radius",
    "opacity"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[31];
    char stringdata1[7];
    char stringdata2[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS = {
    {
        QT_MOC_LITERAL(0, 30),  // "TinyWidgetLibrary::RoundRipple"
        QT_MOC_LITERAL(31, 6),  // "radius"
        QT_MOC_LITERAL(38, 7)   // "opacity"
    },
    "TinyWidgetLibrary::RoundRipple",
    "radius",
    "opacity"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QReal, 0x00015103, uint(-1), 0,
       2, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::RoundRipple::staticMetaObject = { {
    QMetaObject::SuperData::link<Ripple::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS_t,
        // property 'radius'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'opacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RoundRipple, std::true_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::RoundRipple::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RoundRipple *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getRadius(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getOpacity(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RoundRipple *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRadius(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *TinyWidgetLibrary::RoundRipple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::RoundRipple::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPERoundRippleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Ripple::qt_metacast(_clname);
}

int TinyWidgetLibrary::RoundRipple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Ripple::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
