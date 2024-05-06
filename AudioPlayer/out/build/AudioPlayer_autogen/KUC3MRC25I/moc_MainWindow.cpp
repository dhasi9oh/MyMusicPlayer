/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/Window/MainWindow.h"
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
#error "The header file 'MainWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "login_success",
    "",
    "slotPreButtonClicked",
    "slotNextButtonClicked",
    "slotPlayButtonClicked",
    "slotLocalFileButtonClicked",
    "slotProgressMove",
    "slotProgressRelease",
    "slotSearchSongNameReturn",
    "slotSongItemLoveButtonClicked",
    "SongItem*",
    "slotSongItemRemoveButtonClicked",
    "slotSongItemDownLoadButtonClicked",
    "slotSongItemButtonDoubleClicked",
    "QListWidgetItem*",
    "slotLocalFileSongItemRemoveButtonClicked",
    "FileSongItem*",
    "slotLocalFileSongItemDoubleClicked",
    "slotMusicModFinish",
    "ReqId",
    "ErrorCodes"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[22];
    char stringdata5[22];
    char stringdata6[27];
    char stringdata7[17];
    char stringdata8[20];
    char stringdata9[25];
    char stringdata10[30];
    char stringdata11[10];
    char stringdata12[32];
    char stringdata13[34];
    char stringdata14[32];
    char stringdata15[17];
    char stringdata16[41];
    char stringdata17[14];
    char stringdata18[35];
    char stringdata19[19];
    char stringdata20[6];
    char stringdata21[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "login_success"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 20),  // "slotPreButtonClicked"
        QT_MOC_LITERAL(47, 21),  // "slotNextButtonClicked"
        QT_MOC_LITERAL(69, 21),  // "slotPlayButtonClicked"
        QT_MOC_LITERAL(91, 26),  // "slotLocalFileButtonClicked"
        QT_MOC_LITERAL(118, 16),  // "slotProgressMove"
        QT_MOC_LITERAL(135, 19),  // "slotProgressRelease"
        QT_MOC_LITERAL(155, 24),  // "slotSearchSongNameReturn"
        QT_MOC_LITERAL(180, 29),  // "slotSongItemLoveButtonClicked"
        QT_MOC_LITERAL(210, 9),  // "SongItem*"
        QT_MOC_LITERAL(220, 31),  // "slotSongItemRemoveButtonClicked"
        QT_MOC_LITERAL(252, 33),  // "slotSongItemDownLoadButtonCli..."
        QT_MOC_LITERAL(286, 31),  // "slotSongItemButtonDoubleClicked"
        QT_MOC_LITERAL(318, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(335, 40),  // "slotLocalFileSongItemRemoveBu..."
        QT_MOC_LITERAL(376, 13),  // "FileSongItem*"
        QT_MOC_LITERAL(390, 34),  // "slotLocalFileSongItemDoubleCl..."
        QT_MOC_LITERAL(425, 18),  // "slotMusicModFinish"
        QT_MOC_LITERAL(444, 5),  // "ReqId"
        QT_MOC_LITERAL(450, 10)   // "ErrorCodes"
    },
    "MainWindow",
    "login_success",
    "",
    "slotPreButtonClicked",
    "slotNextButtonClicked",
    "slotPlayButtonClicked",
    "slotLocalFileButtonClicked",
    "slotProgressMove",
    "slotProgressRelease",
    "slotSearchSongNameReturn",
    "slotSongItemLoveButtonClicked",
    "SongItem*",
    "slotSongItemRemoveButtonClicked",
    "slotSongItemDownLoadButtonClicked",
    "slotSongItemButtonDoubleClicked",
    "QListWidgetItem*",
    "slotLocalFileSongItemRemoveButtonClicked",
    "FileSongItem*",
    "slotLocalFileSongItemDoubleClicked",
    "slotMusicModFinish",
    "ReqId",
    "ErrorCodes"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  107,    2, 0x08,    3 /* Private */,
       4,    0,  108,    2, 0x08,    4 /* Private */,
       5,    0,  109,    2, 0x08,    5 /* Private */,
       6,    0,  110,    2, 0x08,    6 /* Private */,
       7,    1,  111,    2, 0x08,    7 /* Private */,
       8,    1,  114,    2, 0x08,    9 /* Private */,
       9,    0,  117,    2, 0x08,   11 /* Private */,
      10,    1,  118,    2, 0x08,   12 /* Private */,
      12,    1,  121,    2, 0x08,   14 /* Private */,
      13,    1,  124,    2, 0x08,   16 /* Private */,
      14,    1,  127,    2, 0x08,   18 /* Private */,
      16,    1,  130,    2, 0x08,   20 /* Private */,
      18,    1,  133,    2, 0x08,   22 /* Private */,
      19,    4,  136,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QByteArray, 0x80000000 | 21, QMetaType::QJsonObject,    2,    2,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<TinyWidgetLibrary::RemovableWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'login_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject, std::false_type>,
        // method 'slotPreButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotNextButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPlayButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotLocalFileButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotProgressMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'slotProgressRelease'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotSearchSongNameReturn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSongItemLoveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SongItem *, std::false_type>,
        // method 'slotSongItemRemoveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SongItem *, std::false_type>,
        // method 'slotSongItemDownLoadButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SongItem *, std::false_type>,
        // method 'slotSongItemButtonDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'slotLocalFileSongItemRemoveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FileSongItem *, std::false_type>,
        // method 'slotLocalFileSongItemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FileSongItem *, std::false_type>,
        // method 'slotMusicModFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ReqId, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        QtPrivate::TypeAndForceComplete<ErrorCodes, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->login_success((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->slotPreButtonClicked(); break;
        case 2: _t->slotNextButtonClicked(); break;
        case 3: _t->slotPlayButtonClicked(); break;
        case 4: _t->slotLocalFileButtonClicked(); break;
        case 5: _t->slotProgressMove((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 6: _t->slotProgressRelease((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->slotSearchSongNameReturn(); break;
        case 8: _t->slotSongItemLoveButtonClicked((*reinterpret_cast< std::add_pointer_t<SongItem*>>(_a[1]))); break;
        case 9: _t->slotSongItemRemoveButtonClicked((*reinterpret_cast< std::add_pointer_t<SongItem*>>(_a[1]))); break;
        case 10: _t->slotSongItemDownLoadButtonClicked((*reinterpret_cast< std::add_pointer_t<SongItem*>>(_a[1]))); break;
        case 11: _t->slotSongItemButtonDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 12: _t->slotLocalFileSongItemRemoveButtonClicked((*reinterpret_cast< std::add_pointer_t<FileSongItem*>>(_a[1]))); break;
        case 13: _t->slotLocalFileSongItemDoubleClicked((*reinterpret_cast< std::add_pointer_t<FileSongItem*>>(_a[1]))); break;
        case 14: _t->slotMusicModFinish((*reinterpret_cast< std::add_pointer_t<ReqId>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ErrorCodes>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SongItem* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SongItem* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SongItem* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FileSongItem* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FileSongItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QJsonObject );
            if (_t _q_method = &MainWindow::login_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return TinyWidgetLibrary::RemovableWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TinyWidgetLibrary::RemovableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::login_success(const QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
