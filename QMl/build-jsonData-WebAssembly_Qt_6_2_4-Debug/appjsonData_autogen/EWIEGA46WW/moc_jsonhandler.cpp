/****************************************************************************
** Meta object code from reading C++ file 'jsonhandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../jsonData/jsonhandler.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jsonhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_jsonHandler_t {
    const uint offsetsAndSize[12];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_jsonHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_jsonHandler_t qt_meta_stringdata_jsonHandler = {
    {
QT_MOC_LITERAL(0, 11), // "jsonHandler"
QT_MOC_LITERAL(12, 13), // "writeJsonFile"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 12), // "readJsonFile"
QT_MOC_LITERAL(40, 13), // "parseJsonFile"
QT_MOC_LITERAL(54, 12) // "sendJsonFile"

    },
    "jsonHandler\0writeJsonFile\0\0readJsonFile\0"
    "parseJsonFile\0sendJsonFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jsonHandler[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x02,    1 /* Public */,
       3,    0,   39,    2, 0x02,    2 /* Public */,
       4,    0,   40,    2, 0x02,    3 /* Public */,
       5,    0,   41,    2, 0x02,    4 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QJsonObject,
    QMetaType::QVariantList,
    QMetaType::Void,

       0        // eod
};

void jsonHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<jsonHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->writeJsonFile(); break;
        case 1: { QJsonObject _r = _t->readJsonFile();
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariantList _r = _t->parseJsonFile();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->sendJsonFile(); break;
        default: ;
        }
    }
}

const QMetaObject jsonHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_jsonHandler.offsetsAndSize,
    qt_meta_data_jsonHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_jsonHandler_t
, QtPrivate::TypeAndForceComplete<jsonHandler, std::true_type>

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *jsonHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jsonHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_jsonHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int jsonHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
