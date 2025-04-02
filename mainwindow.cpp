#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    
    // 设置文本编辑器支持HTML格式
    ui->textEdit->setAcceptRichText(true);
    
    // 初始化文件处理器和编辑器处理器
    m_fileHandler = new FileHandler(this, ui->textEdit);
    m_editorHandler = new EditorHandler(this, ui->textEdit);
    
    // 设置窗口标题
    setWindowTitle("笔记");
    

    
    // 连接字体编辑相关信号
    connect(ui->actionFontDialog, &QAction::triggered, this, &MainWindow::showFontDialog);
    connect(ui->actionAlignLeft, &QAction::triggered, this, &MainWindow::on_actionAlignLeft_triggered);
    connect(ui->actionAlignCenter, &QAction::triggered, this, &MainWindow::on_actionAlignCenter_triggered);
    connect(ui->actionAlignRight, &QAction::triggered, this, &MainWindow::on_actionAlignRight_triggered);
    connect(ui->actionAlignJustify, &QAction::triggered, this, &MainWindow::on_actionAlignJustify_triggered);
    

    
    // 连接文本光标位置变化信号，用于更新工具栏按钮状态
    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &MainWindow::updateFormatButtons);
}

MainWindow::~MainWindow()
{
    delete ui;
    // FileHandler和EditorHandler会随着父对象MainWindow的销毁而自动销毁
}

void MainWindow::on_actionNew_triggered()
{
    m_fileHandler->newFile();
    setWindowTitle("QtNotepad");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = m_fileHandler->openFile();
    if (!fileName.isEmpty()) {
        setWindowTitle(fileName);
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = m_fileHandler->saveFileAs();
    if (!fileName.isEmpty()) {
        setWindowTitle(fileName);
    }
}

void MainWindow::on_actionPrint_triggered()
{
    m_editorHandler->print();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    m_editorHandler->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    m_editorHandler->paste();
}

void MainWindow::on_actionCut_triggered()
{
    m_editorHandler->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    m_editorHandler->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    m_editorHandler->redo();
}

void MainWindow::on_actionSave_S_triggered()
{
    if (m_fileHandler->getCurrentFilePath().isEmpty()) {
        on_actionSave_As_triggered();
    } else {
        if (m_fileHandler->saveFile(m_fileHandler->getCurrentFilePath())) {
            setWindowTitle(m_fileHandler->getCurrentFilePath());
        }
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "关于 QtNotepad", 
                      "<h2>QtNotepad</h2>"
                      "<p>一个简单的基于Qt的富文本编辑器</p>"
                      "<p>支持基本的文本编辑功能和图片插入</p>"
                      "<p>版本: 1.0</p>");
}

void MainWindow::on_actionInsertImage_triggered()
{
    m_editorHandler->insertImage();
}



void MainWindow::showFontDialog()
{
    bool ok;
    QFont font = ui->textEdit->currentFont();
    font = QFontDialog::getFont(&ok, font, this, "选择字体");
    if (ok) {
        // 设置字体族
        m_editorHandler->setFontFamily(font.family());
        // 设置字体大小
        m_editorHandler->setFontSize(font.pointSize());
        // 设置字体粗细
        QTextCharFormat format;
        format.setFontWeight(font.weight());
        ui->textEdit->mergeCurrentCharFormat(format);
        // 设置斜体
        format.setFontItalic(font.italic());
        ui->textEdit->mergeCurrentCharFormat(format);
        // 设置下划线
        format.setFontUnderline(font.underline());
        ui->textEdit->mergeCurrentCharFormat(format);
    }
}

void MainWindow::on_actionFontFamily_triggered()
{
    bool ok;
    QString family = QFontDialog::getFont(&ok, ui->textEdit->currentFont(), this, "选择字体族").family();
    if (ok) {
        m_editorHandler->setFontFamily(family);
    }
}

void MainWindow::on_actionFontSize_triggered()
{
    bool ok;
    int size = QInputDialog::getInt(this, "设置字号", "字号:", 
                                  ui->textEdit->currentFont().pointSize(), 
                                  6, 72, 1, &ok);
    if (ok) {
        m_editorHandler->setFontSize(size);
    }
}

void MainWindow::on_actionTextColor_triggered()
{
    QColor color = QColorDialog::getColor(ui->textEdit->textColor(), this, "选择文本颜色");
    if (color.isValid()) {
        m_editorHandler->setTextColor(color);
    }
}

void MainWindow::on_actionTextHighlight_triggered()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    QColor color = QColorDialog::getColor(format.background().color(), this, "选择高亮颜色");
    if (color.isValid()) {
        m_editorHandler->setTextBackgroundColor(color);
    }
}

void MainWindow::on_actionAlignLeft_triggered()
{
    m_editorHandler->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionAlignCenter_triggered()
{
    m_editorHandler->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionAlignRight_triggered()
{
    m_editorHandler->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionAlignJustify_triggered()
{
    m_editorHandler->setAlignment(Qt::AlignJustify);
}

void MainWindow::updateFormatButtons()
{
    // 由于已删除加粗、斜体和下划线按钮，此函数保留但不再需要更新这些按钮状态
}

