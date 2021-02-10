/****************************************************************************
** Meta object code from reading C++ file 'cardmodel.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ex4/cardmodel.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardmodel.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CardModel_t {
    QByteArrayData data[10];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardModel_t qt_meta_stringdata_CardModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CardModel"
QT_MOC_LITERAL(1, 10, 16), // "cardValueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "correctAnswersChanged"
QT_MOC_LITERAL(4, 50, 23), // "incorrectAnswersChanged"
QT_MOC_LITERAL(5, 74, 13), // "choiceChanged"
QT_MOC_LITERAL(6, 88, 9), // "cardValue"
QT_MOC_LITERAL(7, 98, 14), // "correctAnswers"
QT_MOC_LITERAL(8, 113, 16), // "incorrectAnswers"
QT_MOC_LITERAL(9, 130, 7) // "correct"

    },
    "CardModel\0cardValueChanged\0\0"
    "correctAnswersChanged\0incorrectAnswersChanged\0"
    "choiceChanged\0cardValue\0correctAnswers\0"
    "incorrectAnswers\0correct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495001,
       7, QMetaType::Int, 0x00495001,
       8, QMetaType::Int, 0x00495001,
       9, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void CardModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CardModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cardValueChanged(); break;
        case 1: _t->correctAnswersChanged(); break;
        case 2: _t->incorrectAnswersChanged(); break;
        case 3: _t->choiceChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CardModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardModel::cardValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CardModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardModel::correctAnswersChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CardModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardModel::incorrectAnswersChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CardModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardModel::choiceChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CardModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getCardValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getCorrectAnswers(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getIncorrectAnswers(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isCorrect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CardModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CardModel.data,
    qt_meta_data_CardModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CardModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CardModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CardModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CardModel::cardValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CardModel::correctAnswersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CardModel::incorrectAnswersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CardModel::choiceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
