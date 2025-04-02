#ifndef EDITORHANDLER_H
#define EDITORHANDLER_H

#include <QObject>
#include <QTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>

/**
 * @brief 编辑器操作类
 * 负责处理文本编辑器的编辑操作，包括复制、粘贴、剪切、撤销、重做等功能
 */
class EditorHandler : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父对象
     * @param textEdit 关联的文本编辑器控件
     */
    explicit EditorHandler(QObject *parent = nullptr, QTextEdit *textEdit = nullptr);

    /**
     * @brief 复制选中的文本
     */
    void copy();

    /**
     * @brief 粘贴文本
     */
    void paste();

    /**
     * @brief 剪切选中的文本
     */
    void cut();

    /**
     * @brief 撤销操作
     */
    void undo();

    /**
     * @brief 重做操作
     */
    void redo();

    /**
     * @brief 打印文档
     */
    void print();

    /**
     * @brief 插入图片
     */
    void insertImage();

private:
    QTextEdit *m_textEdit;  ///< 关联的文本编辑器控件
};

#endif // EDITORHANDLER_H