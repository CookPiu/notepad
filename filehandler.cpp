#include "filehandler.h"

FileHandler::FileHandler(QObject *parent, QTextEdit *textEdit)
    : QObject(parent),
      m_textEdit(textEdit),
      m_currentFile("")
{
}

void FileHandler::newFile()
{
    m_currentFile.clear();
    m_textEdit->setText(QString());
}

QString FileHandler::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "打开文件", "", 
                                                "HTML文件 (*.html *.htm);;文本文件 (*.txt);;所有文件 (*)");
    if (fileName.isEmpty())
        return QString();
        
    if (openFile(fileName)) {
        return fileName;
    }
    return QString();
}

bool FileHandler::openFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(nullptr, "警告", "无法打开文件: " + file.errorString());
        return false;
    }
    
    QTextStream in(&file);
    QString text = in.readAll();
    m_textEdit->setHtml(text);
    file.close();
    
    m_currentFile = filePath;
    return true;
}

bool FileHandler::saveFile(const QString &currentFile)
{
    if (currentFile.isEmpty()) {
        return false;
    } else {
        return saveToFile(currentFile);
    }
}

QString FileHandler::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "另存为", "", 
                                                 "HTML文件 (*.html *.htm);;文本文件 (*.txt);;所有文件 (*)");
    if (fileName.isEmpty())
        return QString();

    if (saveToFile(fileName)) {
        m_currentFile = fileName;
        return fileName;
    }
    
    return QString();
}

QString FileHandler::getCurrentFilePath() const
{
    return m_currentFile;
}

void FileHandler::setCurrentFilePath(const QString &path)
{
    m_currentFile = path;
}

bool FileHandler::saveToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(nullptr, "警告", "无法保存文件: " + file.errorString());
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << m_textEdit->toHtml();

    if (out.status() != QTextStream::Ok) {
        QMessageBox::warning(nullptr, "警告", "写入数据到文件失败。");
        file.close();
        return false;
    }

    file.close();
    return true;
}