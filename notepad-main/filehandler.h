#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextEdit>

/**
 * @brief 文件处理类
 * 负责处理文本编辑器的文件操作，包括打开、保存、创建新文件等功能
 */
class FileHandler : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父对象
     * @param textEdit 关联的文本编辑器控件
     */
    explicit FileHandler(QObject *parent = nullptr, QTextEdit *textEdit = nullptr);

    /**
     * @brief 创建新文件
     */
    void newFile();

    /**
     * @brief 打开文件
     * @return 打开的文件路径，如果取消则返回空字符串
     */
    QString openFile();

    /**
     * @brief 打开指定文件
     * @param filePath 要打开的文件路径
     * @return 如果打开成功返回true，否则返回false
     */
    bool openFile(const QString &filePath);

    /**
     * @brief 保存文件
     * @param currentFile 当前文件路径
     * @return 如果保存成功返回true，否则返回false
     */
    bool saveFile(const QString &currentFile);

    /**
     * @brief 另存为文件
     * @return 新保存的文件路径，如果取消则返回空字符串
     */
    QString saveFileAs();

    /**
     * @brief 获取当前文件路径
     * @return 当前文件路径
     */
    QString getCurrentFilePath() const;

    /**
     * @brief 设置当前文件路径
     * @param path 文件路径
     */
    void setCurrentFilePath(const QString &path);

private:
    QTextEdit *m_textEdit;  ///< 关联的文本编辑器控件
    QString m_currentFile;  ///< 当前打开的文件路径

    /**
     * @brief 保存到指定文件
     * @param filename 文件路径
     * @return 如果保存成功返回true，否则返回false
     */
    bool saveToFile(const QString &filename);
};

#endif // FILEHANDLER_H