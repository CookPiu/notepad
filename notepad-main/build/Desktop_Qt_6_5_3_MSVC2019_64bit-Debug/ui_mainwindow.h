/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionToggleNoteList;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave_S;
    QAction *actionAbout;
    QAction *actionInsertImage;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionFontDialog;
    QAction *actionFontFamily;
    QAction *actionFontSize;
    QAction *actionTextColor;
    QAction *actionTextHighlight;
    QAction *actionAlignLeft;
    QAction *actionAlignCenter;
    QAction *actionAlignRight;
    QAction *actionAlignJustify;
    QAction *actionThemeLight;
    QAction *actionThemeDark;
    QAction *actionThemeBlue;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QMenu *menuView;
    QMenu *menuTheme;
    QMenu *menuHelp;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(516, 288);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 6px 12px;\n"
"    margin: 2px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff;\n"
"    color: #333333;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 6px 24px 6px 12px;\n"
"    border-radius: 4px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: #f5f5f5;\n"
"    color: #666666;\n"
"    border-top: 1px solid #e0e0e0;\n"
"}"));
        actionToggleNoteList = new QAction(MainWindow);
        actionToggleNoteList->setObjectName("actionToggleNoteList");
        actionToggleNoteList->setCheckable(true);
        actionToggleNoteList->setChecked(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName("actionPrint");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionSave_S = new QAction(MainWindow);
        actionSave_S->setObjectName("actionSave_S");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionInsertImage = new QAction(MainWindow);
        actionInsertImage->setObjectName("actionInsertImage");
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName("actionBold");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/icons/bold.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName("actionItalic");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/icons/italic.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon1);
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName("actionUnderline");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/icons/underline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon2);
        actionFontDialog = new QAction(MainWindow);
        actionFontDialog->setObjectName("actionFontDialog");
        actionFontFamily = new QAction(MainWindow);
        actionFontFamily->setObjectName("actionFontFamily");
        actionFontSize = new QAction(MainWindow);
        actionFontSize->setObjectName("actionFontSize");
        actionTextColor = new QAction(MainWindow);
        actionTextColor->setObjectName("actionTextColor");
        actionTextHighlight = new QAction(MainWindow);
        actionTextHighlight->setObjectName("actionTextHighlight");
        actionAlignLeft = new QAction(MainWindow);
        actionAlignLeft->setObjectName("actionAlignLeft");
        actionAlignCenter = new QAction(MainWindow);
        actionAlignCenter->setObjectName("actionAlignCenter");
        actionAlignRight = new QAction(MainWindow);
        actionAlignRight->setObjectName("actionAlignRight");
        actionAlignJustify = new QAction(MainWindow);
        actionAlignJustify->setObjectName("actionAlignJustify");
        actionThemeLight = new QAction(MainWindow);
        actionThemeLight->setObjectName("actionThemeLight");
        actionThemeLight->setCheckable(true);
        actionThemeDark = new QAction(MainWindow);
        actionThemeDark->setObjectName("actionThemeDark");
        actionThemeDark->setCheckable(true);
        actionThemeBlue = new QAction(MainWindow);
        actionThemeBlue->setObjectName("actionThemeBlue");
        actionThemeBlue->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout->addLayout(verticalLayout_2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #ffffff;\n"
"    color: #333333;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    padding: 10px;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 13px;\n"
"    selection-background-color: #4a90e2;\n"
"    selection-color: #ffffff;\n"
"    box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    border: 1px solid #4a90e2;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 1px solid #4a90e2;\n"
"    box-shadow: 0px 2px 8px rgba(74, 144, 226, 0.2);\n"
"}"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 516, 29));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuFormat = new QMenu(menuBar);
        menuFormat->setObjectName("menuFormat");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        menuTheme = new QMenu(menuBar);
        menuTheme->setObjectName("menuTheme");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setStyleSheet(QString::fromUtf8("QToolBar {\n"
"    background-color: #f5f5f5;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    spacing: 6px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QToolBar::separator {\n"
"    width: 1px;\n"
"    background-color: #e0e0e0;\n"
"    margin: 6px 10px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid transparent;\n"
"    border-radius: 8px;\n"
"    color: #333333;\n"
"    padding: 6px;\n"
"    margin: 2px;\n"
"    min-width: 32px;\n"
"    min-height: 32px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"\n"
"QToolButton:checked {\n"
"    background-color: #e6f0fa;\n"
"    border: 1px solid #4a90e2;\n"
"}"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFormat->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuTheme->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_S);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionInsertImage);
        menuFormat->addAction(actionFontDialog);
        menuFormat->addAction(actionFontFamily);
        menuFormat->addAction(actionFontSize);
        menuFormat->addSeparator();
        menuFormat->addAction(actionTextColor);
        menuFormat->addAction(actionTextHighlight);
        menuFormat->addSeparator();
        menuFormat->addAction(actionAlignLeft);
        menuFormat->addAction(actionAlignCenter);
        menuFormat->addAction(actionAlignRight);
        menuFormat->addAction(actionAlignJustify);
        menuView->addAction(actionToggleNoteList);
        menuTheme->addAction(actionThemeLight);
        menuTheme->addAction(actionThemeDark);
        menuTheme->addAction(actionThemeBlue);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionFontDialog);
        toolBar->addSeparator();
        toolBar->addAction(actionAlignLeft);
        toolBar->addAction(actionAlignCenter);
        toolBar->addAction(actionAlignRight);
        toolBar->addAction(actionAlignJustify);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\254\224\350\256\260", nullptr));
        actionToggleNoteList->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272/\351\232\220\350\227\217\347\254\224\350\256\260\345\210\227\350\241\250", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
        actionSave_S->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        actionInsertImage->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\345\233\276\347\211\207", nullptr));
#if QT_CONFIG(shortcut)
        actionInsertImage->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBold->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#if QT_CONFIG(tooltip)
        actionBold->setToolTip(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionItalic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actionItalic->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionItalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUnderline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actionUnderline->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUnderline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFontDialog->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actionFontDialog->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFontDialog->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFontFamily->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\346\227\217", nullptr));
#if QT_CONFIG(tooltip)
        actionFontFamily->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\255\227\344\275\223\346\227\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontSize->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\217\267", nullptr));
#if QT_CONFIG(tooltip)
        actionFontSize->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\255\227\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTextColor->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionTextColor->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTextHighlight->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\351\253\230\344\272\256", nullptr));
#if QT_CONFIG(tooltip)
        actionTextHighlight->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\226\207\346\234\254\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAlignLeft->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", nullptr));
#if QT_CONFIG(tooltip)
        actionAlignLeft->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAlignCenter->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
#if QT_CONFIG(tooltip)
        actionAlignCenter->setToolTip(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAlignRight->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", nullptr));
#if QT_CONFIG(tooltip)
        actionAlignRight->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAlignJustify->setText(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220", nullptr));
#if QT_CONFIG(tooltip)
        actionAlignJustify->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actionThemeLight->setText(QCoreApplication::translate("MainWindow", "\346\265\205\350\211\262\344\270\273\351\242\230", nullptr));
        actionThemeDark->setText(QCoreApplication::translate("MainWindow", "\346\267\261\350\211\262\344\270\273\351\242\230", nullptr));
        actionThemeBlue->setText(QCoreApplication::translate("MainWindow", "\350\223\235\350\211\262\344\270\273\351\242\230", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\234\250\346\255\244\350\276\223\345\205\245\346\226\207\345\255\227\345\206\205\345\256\271...", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuFormat->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("MainWindow", "\344\270\273\351\242\230", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
