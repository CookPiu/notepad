#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    
    // 新增的工具栏按钮槽函数
    void on_actionBold_triggered();
    void on_actionItalic_triggered();
    void on_actionUnderline_triggered();
    void on_actionCode_triggered();
    void on_actionTitle1_triggered();
    void on_actionPreviewMode_triggered();

private:
    Ui::MainWindow *ui;                ///< UI界面
    FileHandler *m_fileHandler;        ///< 文件处理器
    EditorHandler *m_editorHandler;    ///< 编辑器处理器
    QString m_previewContent; // 用于保存预览模式前的内容
};

#endif // MAINWINDOW_H
