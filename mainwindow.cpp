#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>

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
    
    // 连接工具栏按钮信号
    connect(ui->actionBold, &QAction::triggered, this, &MainWindow::on_actionBold_triggered);
    connect(ui->actionItalic, &QAction::triggered, this, &MainWindow::on_actionItalic_triggered);
    connect(ui->actionUnderline, &QAction::triggered, this, &MainWindow::on_actionUnderline_triggered);
    connect(ui->actionCode, &QAction::triggered, this, &MainWindow::on_actionCode_triggered);
    connect(ui->actionTitle1, &QAction::triggered, this, &MainWindow::on_actionTitle1_triggered);
    connect(ui->actionPreviewMode, &QAction::triggered, this, &MainWindow::on_actionPreviewMode_triggered);
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

void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(ui->textEdit->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_actionItalic_triggered()
{
    QTextCharFormat format;
    format.setFontItalic(!ui->textEdit->fontItalic());
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_actionUnderline_triggered()
{
    QTextCharFormat format;
    format.setFontUnderline(!ui->textEdit->fontUnderline());
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_actionCode_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();
    
    if (blockFormat.leftMargin() == 20) {
        // 取消代码块格式
        blockFormat.setLeftMargin(0);
        blockFormat.setBackground(QBrush(Qt::transparent));
    } else {
        // 设置代码块格式
        blockFormat.setLeftMargin(20);
        blockFormat.setBackground(QBrush(QColor("#333333")));
    }
    
    cursor.setBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_actionTitle1_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    format.setFontPointSize(18);
    format.setFontWeight(QFont::Bold);
    cursor.select(QTextCursor::LineUnderCursor);
    cursor.mergeCharFormat(format);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_actionPreviewMode_triggered()
{
    static bool isPreviewMode = false;
    isPreviewMode = !isPreviewMode;
    
    if (isPreviewMode) {
        // 保存当前内容
        m_previewContent = ui->textEdit->toHtml();
        // 设置为只读模式
        ui->textEdit->setReadOnly(true);
        // 更改背景色为更深的颜色
        ui->textEdit->setStyleSheet("QTextEdit { background-color: #1a1a1a; color: #e0e0e0; border: 1px solid #3a3a3a; border-radius: 8px; padding: 5px; }");
    } else {
        // 恢复编辑模式
        ui->textEdit->setReadOnly(false);
        // 恢复原来的样式
        ui->textEdit->setStyleSheet("QTextEdit { background-color: #252525; color: #e0e0e0; border: 1px solid #3a3a3a; border-radius: 8px; padding: 5px; }");
    }
}

