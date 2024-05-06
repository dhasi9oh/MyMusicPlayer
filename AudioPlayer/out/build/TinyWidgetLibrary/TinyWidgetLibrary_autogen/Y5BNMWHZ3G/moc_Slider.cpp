/****************************************************************************
** Meta object code from reading C++ file 'Slider.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TinyWidgetLibrary/MyWidget/Progress/Slider.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Slider.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::Slider",
    "onSliderMoved",
    "",
    "position"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[26];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS = {
    {
        QT_MOC_LITERAL(0, 25),  // "TinyWidgetLibrary::Slider"
        QT_MOC_LITERAL(26, 13),  // "onSliderMoved"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 8)   // "position"
    },
    "TinyWidgetLibrary::Slider",
    "onSliderMoved",
    "",
    "position"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPESliderENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::Slider::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSlider::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPESliderENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Slider, std::true_type>,
        // method 'onSliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint32, std::false_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::Slider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Slider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSliderMoved((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *TinyWidgetLibrary::Slider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::Slider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPESliderENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractSlider::qt_metacast(_clname);
}

int TinyWidgetLibrary::Slider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
