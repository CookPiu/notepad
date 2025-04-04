#include "editorhandler.h"
#include <QFileDialog>
#include <QImage>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextImageFormat>
#include <QUrl>
#include <QTextBlockFormat>
#include <QFontDialog>
#include <QColorDialog>

EditorHandler::EditorHandler(QObject *parent, QTextEdit *textEdit)
    : QObject(parent),
      m_textEdit(textEdit)
{
}

void EditorHandler::copy()
{
    m_textEdit->copy();
}

void EditorHandler::paste()
{
    m_textEdit->paste();
}

void EditorHandler::cut()
{
    m_textEdit->cut();
}

void EditorHandler::undo()
{
    m_textEdit->undo();
}

void EditorHandler::redo()
{
    m_textEdit->redo();
}

void EditorHandler::print()
{
    QPrinter printer;
    printer.setPrinterName("打印机名称");
    QPrintDialog pDialog(&printer, nullptr);
    if (pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(nullptr, "警告", "无法访问打印机");
        return;
    }
    m_textEdit->print(&printer);
}

void EditorHandler::insertImage()
{
    // 打开文件对话框选择图片
    QString fileName = QFileDialog::getOpenFileName(nullptr,
        "选择图片", "", "图片文件 (*.png *.jpg *.bmp *.gif)");
    
    if (fileName.isEmpty())
        return;
    
    // 加载图片
    QImage image(fileName);
    if (image.isNull()) {
        QMessageBox::warning(nullptr, "插入图片",
                             QString("无法加载图片 %1.").arg(fileName));
        return;
    }
    
    // 将图片插入到文档中
    QTextCursor cursor = m_textEdit->textCursor();
    QTextDocument *document = m_textEdit->document();
    
    // 将图片添加到文档资源中
    document->addResource(QTextDocument::ImageResource,
                         QUrl(fileName), QVariant(image));
    
    // 插入图片
    QTextImageFormat imageFormat;
    imageFormat.setName(fileName);
    
    // 如果图片太大，调整大小
    if (image.width() > 800) {
        int newWidth = 800;
        int newHeight = (image.height() * newWidth) / image.width();
        imageFormat.setWidth(newWidth);
        imageFormat.setHeight(newHeight);
    } else {
        imageFormat.setWidth(image.width());
        imageFormat.setHeight(image.height());
    }
    
    cursor.insertImage(imageFormat);
}

void EditorHandler::setFontFamily(const QString &family)
{
    QTextCharFormat format;
    format.setFontFamily(family);
    m_textEdit->mergeCurrentCharFormat(format);
}

void EditorHandler::setFontSize(int size)
{
    QTextCharFormat format;
    format.setFontPointSize(size);
    m_textEdit->mergeCurrentCharFormat(format);
}

void EditorHandler::setTextColor(const QColor &color)
{
    QTextCharFormat format;
    format.setForeground(color);
    m_textEdit->mergeCurrentCharFormat(format);
}

void EditorHandler::setTextBackgroundColor(const QColor &color)
{
    QTextCharFormat format;
    format.setBackground(color);
    m_textEdit->mergeCurrentCharFormat(format);
}

void EditorHandler::setAlignment(Qt::Alignment alignment)
{
    m_textEdit->setAlignment(alignment);
}