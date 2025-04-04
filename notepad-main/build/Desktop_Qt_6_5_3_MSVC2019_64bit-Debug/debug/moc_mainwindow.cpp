/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
    "on_actionNew_triggered",
    "",
    "on_actionOpen_triggered",
    "on_actionSave_As_triggered",
    "on_actionSave_S_triggered",
    "toggleNoteList",
    "updateNoteList",
    "openNoteFromList",
    "QListWidgetItem*",
    "item",
    "showNoteListContextMenu",
    "pos",
    "createNewNote",
    "on_actionCopy_triggered",
    "on_actionPaste_triggered",
    "on_actionCut_triggered",
    "on_actionUndo_triggered",
    "on_actionRedo_triggered",
    "on_actionInsertImage_triggered",
    "on_actionPrint_triggered",
    "on_actionExit_triggered",
    "on_actionAbout_triggered",
    "on_actionFontFamily_triggered",
    "on_actionFontSize_triggered",
    "on_actionTextColor_triggered",
    "on_actionTextHighlight_triggered",
    "on_actionAlignLeft_triggered",
    "on_actionAlignCenter_triggered",
    "on_actionAlignRight_triggered",
    "on_actionAlignJustify_triggered",
    "showFontDialog",
    "updateFormatButtons"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[66];
    char stringdata0[11];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[27];
    char stringdata5[26];
    char stringdata6[15];
    char stringdata7[15];
    char stringdata8[17];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[24];
    char stringdata12[4];
    char stringdata13[14];
    char stringdata14[24];
    char stringdata15[25];
    char stringdata16[23];
    char stringdata17[24];
    char stringdata18[24];
    char stringdata19[31];
    char stringdata20[25];
    char stringdata21[24];
    char stringdata22[25];
    char stringdata23[30];
    char stringdata24[28];
    char stringdata25[29];
    char stringdata26[33];
    char stringdata27[29];
    char stringdata28[31];
    char stringdata29[30];
    char stringdata30[32];
    char stringdata31[15];
    char stringdata32[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 22),  // "on_actionNew_triggered"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 23),  // "on_actionOpen_triggered"
        QT_MOC_LITERAL(59, 26),  // "on_actionSave_As_triggered"
        QT_MOC_LITERAL(86, 25),  // "on_actionSave_S_triggered"
        QT_MOC_LITERAL(112, 14),  // "toggleNoteList"
        QT_MOC_LITERAL(127, 14),  // "updateNoteList"
        QT_MOC_LITERAL(142, 16),  // "openNoteFromList"
        QT_MOC_LITERAL(159, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(176, 4),  // "item"
        QT_MOC_LITERAL(181, 23),  // "showNoteListContextMenu"
        QT_MOC_LITERAL(205, 3),  // "pos"
        QT_MOC_LITERAL(209, 13),  // "createNewNote"
        QT_MOC_LITERAL(223, 23),  // "on_actionCopy_triggered"
        QT_MOC_LITERAL(247, 24),  // "on_actionPaste_triggered"
        QT_MOC_LITERAL(272, 22),  // "on_actionCut_triggered"
        QT_MOC_LITERAL(295, 23),  // "on_actionUndo_triggered"
        QT_MOC_LITERAL(319, 23),  // "on_actionRedo_triggered"
        QT_MOC_LITERAL(343, 30),  // "on_actionInsertImage_triggered"
        QT_MOC_LITERAL(374, 24),  // "on_actionPrint_triggered"
        QT_MOC_LITERAL(399, 23),  // "on_actionExit_triggered"
        QT_MOC_LITERAL(423, 24),  // "on_actionAbout_triggered"
        QT_MOC_LITERAL(448, 29),  // "on_actionFontFamily_triggered"
        QT_MOC_LITERAL(478, 27),  // "on_actionFontSize_triggered"
        QT_MOC_LITERAL(506, 28),  // "on_actionTextColor_triggered"
        QT_MOC_LITERAL(535, 32),  // "on_actionTextHighlight_triggered"
        QT_MOC_LITERAL(568, 28),  // "on_actionAlignLeft_triggered"
        QT_MOC_LITERAL(597, 30),  // "on_actionAlignCenter_triggered"
        QT_MOC_LITERAL(628, 29),  // "on_actionAlignRight_triggered"
        QT_MOC_LITERAL(658, 31),  // "on_actionAlignJustify_triggered"
        QT_MOC_LITERAL(690, 14),  // "showFontDialog"
        QT_MOC_LITERAL(705, 19)   // "updateFormatButtons"
    },
    "MainWindow",
    "on_actionNew_triggered",
    "",
    "on_actionOpen_triggered",
    "on_actionSave_As_triggered",
    "on_actionSave_S_triggered",
    "toggleNoteList",
    "updateNoteList",
    "openNoteFromList",
    "QListWidgetItem*",
    "item",
    "showNoteListContextMenu",
    "pos",
    "createNewNote",
    "on_actionCopy_triggered",
    "on_actionPaste_triggered",
    "on_actionCut_triggered",
    "on_actionUndo_triggered",
    "on_actionRedo_triggered",
    "on_actionInsertImage_triggered",
    "on_actionPrint_triggered",
    "on_actionExit_triggered",
    "on_actionAbout_triggered",
    "on_actionFontFamily_triggered",
    "on_actionFontSize_triggered",
    "on_actionTextColor_triggered",
    "on_actionTextHighlight_triggered",
    "on_actionAlignLeft_triggered",
    "on_actionAlignCenter_triggered",
    "on_actionAlignRight_triggered",
    "on_actionAlignJustify_triggered",
    "showFontDialog",
    "updateFormatButtons"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  182,    2, 0x08,    1 /* Private */,
       3,    0,  183,    2, 0x08,    2 /* Private */,
       4,    0,  184,    2, 0x08,    3 /* Private */,
       5,    0,  185,    2, 0x08,    4 /* Private */,
       6,    0,  186,    2, 0x08,    5 /* Private */,
       7,    0,  187,    2, 0x08,    6 /* Private */,
       8,    1,  188,    2, 0x08,    7 /* Private */,
      11,    1,  191,    2, 0x08,    9 /* Private */,
      13,    0,  194,    2, 0x08,   11 /* Private */,
      14,    0,  195,    2, 0x08,   12 /* Private */,
      15,    0,  196,    2, 0x08,   13 /* Private */,
      16,    0,  197,    2, 0x08,   14 /* Private */,
      17,    0,  198,    2, 0x08,   15 /* Private */,
      18,    0,  199,    2, 0x08,   16 /* Private */,
      19,    0,  200,    2, 0x08,   17 /* Private */,
      20,    0,  201,    2, 0x08,   18 /* Private */,
      21,    0,  202,    2, 0x08,   19 /* Private */,
      22,    0,  203,    2, 0x08,   20 /* Private */,
      23,    0,  204,    2, 0x08,   21 /* Private */,
      24,    0,  205,    2, 0x08,   22 /* Private */,
      25,    0,  206,    2, 0x08,   23 /* Private */,
      26,    0,  207,    2, 0x08,   24 /* Private */,
      27,    0,  208,    2, 0x08,   25 /* Private */,
      28,    0,  209,    2, 0x08,   26 /* Private */,
      29,    0,  210,    2, 0x08,   27 /* Private */,
      30,    0,  211,    2, 0x08,   28 /* Private */,
      31,    0,  212,    2, 0x08,   29 /* Private */,
      32,    0,  213,    2, 0x08,   30 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_actionNew_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOpen_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_As_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_S_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleNoteList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateNoteList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openNoteFromList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'showNoteListContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'createNewNote'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCopy_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPaste_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCut_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionUndo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRedo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionInsertImage_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionPrint_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAbout_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFontFamily_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFontSize_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionTextColor_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionTextHighlight_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAlignLeft_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAlignCenter_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAlignRight_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAlignJustify_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showFontDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFormatButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionNew_triggered(); break;
        case 1: _t->on_actionOpen_triggered(); break;
        case 2: _t->on_actionSave_As_triggered(); break;
        case 3: _t->on_actionSave_S_triggered(); break;
        case 4: _t->toggleNoteList(); break;
        case 5: _t->updateNoteList(); break;
        case 6: _t->openNoteFromList((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 7: _t->showNoteListContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 8: _t->createNewNote(); break;
        case 9: _t->on_actionCopy_triggered(); break;
        case 10: _t->on_actionPaste_triggered(); break;
        case 11: _t->on_actionCut_triggered(); break;
        case 12: _t->on_actionUndo_triggered(); break;
        case 13: _t->on_actionRedo_triggered(); break;
        case 14: _t->on_actionInsertImage_triggered(); break;
        case 15: _t->on_actionPrint_triggered(); break;
        case 16: _t->on_actionExit_triggered(); break;
        case 17: _t->on_actionAbout_triggered(); break;
        case 18: _t->on_actionFontFamily_triggered(); break;
        case 19: _t->on_actionFontSize_triggered(); break;
        case 20: _t->on_actionTextColor_triggered(); break;
        case 21: _t->on_actionTextHighlight_triggered(); break;
        case 22: _t->on_actionAlignLeft_triggered(); break;
        case 23: _t->on_actionAlignCenter_triggered(); break;
        case 24: _t->on_actionAlignRight_triggered(); break;
        case 25: _t->on_actionAlignJustify_triggered(); break;
        case 26: _t->showFontDialog(); break;
        case 27: _t->updateFormatButtons(); break;
        default: ;
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 28;
    }
    return _id;
}
QT_WARNING_POP
