/****************************************************************************
** Meta object code from reading C++ file 'scenepcb.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/scenepcb.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scenepcb.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8ScenePCBE_t {};
} // unnamed namespace

template <> constexpr inline auto ScenePCB::qt_create_metaobjectdata<qt_meta_tag_ZN8ScenePCBE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ScenePCB",
        "getCursorPosition",
        "",
        "QPointF",
        "pos",
        "itemAppented",
        "QGraphicsItem*",
        "item",
        "getLineCheckFlag",
        "flag"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'getCursorPosition'
        QtMocHelpers::SignalData<void(const QPointF &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemAppented'
        QtMocHelpers::SignalData<void(QGraphicsItem *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'getLineCheckFlag'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ScenePCB, qt_meta_tag_ZN8ScenePCBE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ScenePCB::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ScenePCBE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ScenePCBE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8ScenePCBE_t>.metaTypes,
    nullptr
} };

void ScenePCB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ScenePCB *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->getCursorPosition((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 1: _t->itemAppented((*reinterpret_cast<std::add_pointer_t<QGraphicsItem*>>(_a[1]))); break;
        case 2: _t->getLineCheckFlag((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ScenePCB::*)(const QPointF & )>(_a, &ScenePCB::getCursorPosition, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ScenePCB::*)(QGraphicsItem * )>(_a, &ScenePCB::itemAppented, 1))
            return;
    }
}

const QMetaObject *ScenePCB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScenePCB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ScenePCBE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int ScenePCB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScenePCB::getCursorPosition(const QPointF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ScenePCB::itemAppented(QGraphicsItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
