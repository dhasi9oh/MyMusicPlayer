/****************************************************************************
** Meta object code from reading C++ file 'CheckableButton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TinyWidgetLibrary/MyWidget/Helper/Button/CheckableButton.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CheckableButton.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::CheckableButton",
    "scale"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS_t {
    uint offsetsAndSizes[4];
    char stringdata0[35];
    char stringdata1[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS = {
    {
        QT_MOC_LITERAL(0, 34),  // "TinyWidgetLibrary::CheckableB..."
        QT_MOC_LITERAL(35, 5)   // "scale"
    },
    "TinyWidgetLibrary::CheckableButton",
    "scale"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::CheckableButton::staticMetaObject = { {
    QMetaObject::SuperData::link<OverlayAbstractButton::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS_t,
        // property 'scale'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CheckableButton, std::true_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::CheckableButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CheckableButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getScale(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CheckableButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScale(*reinterpret_cast< qreal*>(_v)); break;
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

const QMetaObject *TinyWidgetLibrary::CheckableButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::CheckableButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPECheckableButtonENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return OverlayAbstractButton::qt_metacast(_clname);
}

int TinyWidgetLibrary::CheckableButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OverlayAbstractButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
