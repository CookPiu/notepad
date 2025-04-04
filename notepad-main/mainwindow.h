#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QListWidget>
#include "filehandler.h"
#include "editorhandler.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 主窗口类
 * 负责处理用户界面和用户交互
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口
     */
    explicit MainWindow(QWidget *parent = 0);
    
    /**
     * @brief 析构函数
     */
    ~MainWindow();

private slots:
    // 文件操作相关槽函数
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_S_triggered();
    void toggleNoteList();
    void updateNoteList();
    void openNoteFromList(QListWidgetItem *item);
    void showNoteListContextMenu(const QPoint &pos);
    void createNewNote();
    
    // 编辑操作相关槽函数
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionInsertImage_triggered();
    
    // 其他操作相关槽函数
    void on_actionPrint_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    

    
    // 字体编辑相关槽函数
    void on_actionFontFamily_triggered();
    void on_actionFontSize_triggered();
    void on_actionTextColor_triggered();
    void on_actionTextHighlight_triggered();
    void on_actionAlignLeft_triggered();
    void on_actionAlignCenter_triggered();
    void on_actionAlignRight_triggered();
    void on_actionAlignJustify_triggered();
    void showFontDialog();
    
    // 更新格式按钮状态
    void updateFormatButtons();

private:
    Ui::MainWindow *ui;                ///< UI界面
    FileHandler *m_fileHandler;        ///< 文件处理器
    EditorHandler *m_editorHandler;    ///< 编辑器处理器
    QDockWidget *m_noteDock;          ///< 笔记列表停靠窗口
    QListWidget *m_noteList;          ///< 笔记列表部件
    QString m_currentTheme;           ///< 当前主题名称
    
    // 主题相关函数
    void applyTheme(const QString &themeName);
    void setupThemes();
};

#endif // MAINWINDOW_H
