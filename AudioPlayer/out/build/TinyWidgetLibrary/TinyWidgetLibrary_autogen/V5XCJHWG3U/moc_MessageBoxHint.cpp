/****************************************************************************
** Meta object code from reading C++ file 'MessageBoxHint.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TinyWidgetLibrary/MyWidget/PopupBox/MessageBoxHint.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageBoxHint.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS = QtMocHelpers::stringData(
    "TinyWidgetLibrary::MessageBoxHint",
    "readyShow",
    "",
    "readyHide",
    "hideTarget",
    "triggerReadyHide",
    "opacity",
    "window_x",
    "window_y"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[34];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[11];
    char stringdata5[17];
    char stringdata6[8];
    char stringdata7[9];
    char stringdata8[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS_t qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS = {
    {
        QT_MOC_LITERAL(0, 33),  // "TinyWidgetLibrary::MessageBox..."
        QT_MOC_LITERAL(34, 9),  // "readyShow"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 9),  // "readyHide"
        QT_MOC_LITERAL(55, 10),  // "hideTarget"
        QT_MOC_LITERAL(66, 16),  // "triggerReadyHide"
        QT_MOC_LITERAL(83, 7),  // "opacity"
        QT_MOC_LITERAL(91, 8),  // "window_x"
        QT_MOC_LITERAL(100, 8)   // "window_y"
    },
    "TinyWidgetLibrary::MessageBoxHint",
    "readyShow",
    "",
    "readyHide",
    "hideTarget",
    "triggerReadyHide",
    "opacity",
    "window_x",
    "window_y"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       3,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    4 /* Public */,
       3,    0,   39,    2, 0x06,    5 /* Public */,
       4,    0,   40,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   41,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QReal, 0x00015103, uint(-1), 0,
       7, QMetaType::Int, 0x00015003, uint(-1), 0,
       8, QMetaType::Int, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject TinyWidgetLibrary::MessageBoxHint::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS_t,
        // property 'opacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'window_x'
        QtPrivate::TypeAndForceComplete<qint32, std::true_type>,
        // property 'window_y'
        QtPrivate::TypeAndForceComplete<qint32, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MessageBoxHint, std::true_type>,
        // method 'readyShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readyHide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideTarget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerReadyHide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TinyWidgetLibrary::MessageBoxHint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageBoxHint *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readyShow(); break;
        case 1: _t->readyHide(); break;
        case 2: _t->hideTarget(); break;
        case 3: _t->triggerReadyHide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessageBoxHint::*)();
            if (_t _q_method = &MessageBoxHint::readyShow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MessageBoxHint::*)();
            if (_t _q_method = &MessageBoxHint::readyHide; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MessageBoxHint::*)();
            if (_t _q_method = &MessageBoxHint::hideTarget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MessageBoxHint *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getOpacity(); break;
        case 1: *reinterpret_cast< qint32*>(_v) = _t->x(); break;
        case 2: *reinterpret_cast< qint32*>(_v) = _t->y(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MessageBoxHint *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setX(*reinterpret_cast< qint32*>(_v)); break;
        case 2: _t->setY(*reinterpret_cast< qint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *TinyWidgetLibrary::MessageBoxHint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TinyWidgetLibrary::MessageBoxHint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTinyWidgetLibrarySCOPEMessageBoxHintENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TinyWidgetLibrary::MessageBoxHint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TinyWidgetLibrary::MessageBoxHint::readyShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TinyWidgetLibrary::MessageBoxHint::readyHide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TinyWidgetLibrary::MessageBoxHint::hideTarget()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
