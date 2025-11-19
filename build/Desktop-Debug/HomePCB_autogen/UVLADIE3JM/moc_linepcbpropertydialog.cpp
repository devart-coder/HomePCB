/****************************************************************************
** Meta object code from reading C++ file 'linepcbpropertydialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/linepcbpropertydialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linepcbpropertydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
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
struct qt_meta_tag_ZN21LinePCBPropertyDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto LinePCBPropertyDialog::qt_create_metaobjectdata<qt_meta_tag_ZN21LinePCBPropertyDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LinePCBPropertyDialog",
        "startXPositionChanged",
        "",
        "value",
        "startYPositionChanged",
        "endXPositionChanged",
        "endYPositionChanged",
        "widthChanged",
        "colorChange",
        "QColor",
        "color",
        "getStartXPosition",
        "d",
        "getStartYPosition",
        "getEndXPosition",
        "getEndYPosition",
        "getWidth"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'startXPositionChanged'
        QtMocHelpers::SignalData<void(const double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'startYPositionChanged'
        QtMocHelpers::SignalData<void(const double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'endXPositionChanged'
        QtMocHelpers::SignalData<void(const double)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'endYPositionChanged'
        QtMocHelpers::SignalData<void(const double)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void(const double)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'colorChange'
        QtMocHelpers::SignalData<void(const QColor)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Slot 'getStartXPosition'
        QtMocHelpers::SlotData<void(double)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 12 },
        }}),
        // Slot 'getStartYPosition'
        QtMocHelpers::SlotData<void(double)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 12 },
        }}),
        // Slot 'getEndXPosition'
        QtMocHelpers::SlotData<void(double)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 12 },
        }}),
        // Slot 'getEndYPosition'
        QtMocHelpers::SlotData<void(double)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 12 },
        }}),
        // Slot 'getWidth'
        QtMocHelpers::SlotData<void(double)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LinePCBPropertyDialog, qt_meta_tag_ZN21LinePCBPropertyDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject LinePCBPropertyDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21LinePCBPropertyDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21LinePCBPropertyDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21LinePCBPropertyDialogE_t>.metaTypes,
    nullptr
} };

void LinePCBPropertyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LinePCBPropertyDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startXPositionChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->startYPositionChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->endXPositionChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->endYPositionChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->widthChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->colorChange((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1]))); break;
        case 6: _t->getStartXPosition((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->getStartYPosition((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->getEndXPosition((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->getEndYPosition((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->getWidth((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const double )>(_a, &LinePCBPropertyDialog::startXPositionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const double )>(_a, &LinePCBPropertyDialog::startYPositionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const double )>(_a, &LinePCBPropertyDialog::endXPositionChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const double )>(_a, &LinePCBPropertyDialog::endYPositionChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const double )>(_a, &LinePCBPropertyDialog::widthChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (LinePCBPropertyDialog::*)(const QColor )>(_a, &LinePCBPropertyDialog::colorChange, 5))
            return;
    }
}

const QMetaObject *LinePCBPropertyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinePCBPropertyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21LinePCBPropertyDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LinePCBPropertyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void LinePCBPropertyDialog::startXPositionChanged(const double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void LinePCBPropertyDialog::startYPositionChanged(const double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void LinePCBPropertyDialog::endXPositionChanged(const double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void LinePCBPropertyDialog::endYPositionChanged(const double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void LinePCBPropertyDialog::widthChanged(const double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void LinePCBPropertyDialog::colorChange(const QColor _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
