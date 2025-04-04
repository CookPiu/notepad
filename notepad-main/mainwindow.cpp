#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QListWidgetItem>
#include <QMenu>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_fileHandler(nullptr),
    m_editorHandler(nullptr),
    m_noteDock(nullptr),
    m_noteList(nullptr),
    m_currentTheme("light")
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    
    // 创建笔记列表停靠窗口
    m_noteDock = new QDockWidget("笔记列表", this);
    m_noteDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    
    // 创建笔记列表部件
    m_noteList = new QListWidget(m_noteDock);
    m_noteDock->setWidget(m_noteList);
    
    // 设置笔记列表的右键菜单
    m_noteList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_noteList, &QListWidget::customContextMenuRequested, this, &MainWindow::showNoteListContextMenu);
    
    // 连接笔记列表的点击信号
    connect(m_noteList, &QListWidget::itemClicked, this, &MainWindow::openNoteFromList);
    
    addDockWidget(Qt::LeftDockWidgetArea, m_noteDock);
    
    // 设置文本编辑器支持HTML格式
    ui->textEdit->setAcceptRichText(true);
    
    // 初始化文件处理器和编辑器处理器
    m_fileHandler = new FileHandler(this, ui->textEdit);
    m_editorHandler = new EditorHandler(this, ui->textEdit);
    
    // 设置窗口标题
    setWindowTitle("笔记");
    
    // 更新笔记列表
    updateNoteList();
    
    // 连接笔记列表显示/隐藏信号
    connect(ui->actionToggleNoteList, &QAction::triggered, this, &MainWindow::toggleNoteList);
    
    // 连接主题相关信号
    connect(ui->actionThemeLight, &QAction::triggered, this, [this]() { applyTheme("light"); });
    connect(ui->actionThemeDark, &QAction::triggered, this, [this]() { applyTheme("dark"); });
    connect(ui->actionThemeBlue, &QAction::triggered, this, [this]() { applyTheme("blue"); });
    
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
    createNewNote();
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

void MainWindow::toggleNoteList()
{
    if (m_noteDock) {
        m_noteDock->setVisible(!m_noteDock->isVisible());
        ui->actionToggleNoteList->setChecked(m_noteDock->isVisible());
    }
}

void MainWindow::updateNoteList()
{
    if (!m_noteList) return;
    
    m_noteList->clear();
    QDir dir(QDir::currentPath());
    QStringList filters;
    filters << "*.html";
    QStringList files = dir.entryList(filters, QDir::Files);
    
    foreach (QString file, files) {
        QListWidgetItem *item = new QListWidgetItem(file);
        m_noteList->addItem(item);
    }
}

void MainWindow::openNoteFromList(QListWidgetItem *item)
{
    if (!item) return;
    
    QString fileName = item->text();
    QString filePath = QDir::currentPath() + "/" + fileName;
    
    if (m_fileHandler->openFile(filePath)) {
        setWindowTitle(fileName);
    }
}

void MainWindow::showNoteListContextMenu(const QPoint &pos)
{
    QListWidgetItem *item = m_noteList->itemAt(pos);
    if (!item) return;
    
    QMenu menu(this);
    QAction *renameAction = menu.addAction("重命名");
    QAction *deleteAction = menu.addAction("删除");
    
    QAction *selectedAction = menu.exec(m_noteList->mapToGlobal(pos));
    if (selectedAction == renameAction) {
        bool ok;
        QString newName = QInputDialog::getText(this, "重命名笔记", "请输入新的笔记名称:",
                                              QLineEdit::Normal, item->text(), &ok);
        if (ok && !newName.isEmpty()) {
            QString oldPath = QDir::currentPath() + "/" + item->text();
            QString newPath = QDir::currentPath() + "/" + newName;
            if (QFile::rename(oldPath, newPath)) {
                item->setText(newName);
            } else {
                QMessageBox::warning(this, "错误", "无法重命名文件");
            }
        }
    } else if (selectedAction == deleteAction) {
        if (QMessageBox::question(this, "确认删除", "确定要删除这个笔记吗？",
                                QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            QString filePath = QDir::currentPath() + "/" + item->text();
            if (QFile::remove(filePath)) {
                delete m_noteList->takeItem(m_noteList->row(item));
            } else {
                QMessageBox::warning(this, "错误", "无法删除文件");
            }
        }
    }
}

void MainWindow::createNewNote()
{
    bool ok;
    QString noteName = QInputDialog::getText(this, "新建笔记", "请输入笔记名称:", 
                                           QLineEdit::Normal, "", &ok);
    if (ok && !noteName.isEmpty()) {
        // 确保文件名以 .html 结尾
        if (!noteName.endsWith(".html")) {
            noteName += ".html";
        }
        
        QString filePath = QDir::currentPath() + "/" + noteName;
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QFile::Text)) {
            // 写入基本的HTML结构
            QTextStream out(&file);
            out << "<!DOCTYPE html>\n"
                << "<html>\n"
                << "<head>\n"
                << "<meta charset=\"UTF-8\">\n"
                << "<title>" << noteName << "</title>\n"
                << "</head>\n"
                << "<body>\n"
                << "</body>\n"
                << "</html>";
            file.close();
            m_fileHandler->newFile();
            setWindowTitle(noteName);
            updateNoteList();
        } else {
            QMessageBox::warning(this, "错误", "无法创建笔记文件");
        }
    }
}

void MainWindow::applyTheme(const QString &themeName)
{
    m_currentTheme = themeName;
    
    // 更新主题动作的选中状态
    ui->actionThemeLight->setChecked(themeName == "light");
    ui->actionThemeDark->setChecked(themeName == "dark");
    ui->actionThemeBlue->setChecked(themeName == "blue");
    
    QString styleSheet;
    if (themeName == "dark") {
        styleSheet = "QMainWindow {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "}"
                    "QMenuBar {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "    border-bottom: 1px solid #3c3c3c;"
                    "}"
                    "QMenuBar::item {"
                    "    background-color: transparent;"
                    "    padding: 6px 12px;"
                    "    margin: 2px;"
                    "}"
                    "QMenuBar::item:selected {"
                    "    background-color: #3c3c3c;"
                    "}"
                    "QMenu {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "    border: 1px solid #3c3c3c;"
                    "}"
                    "QMenu::item {"
                    "    padding: 6px 24px 6px 12px;"
                    "}"
                    "QMenu::item:selected {"
                    "    background-color: #3c3c3c;"
                    "}"
                    "QTextEdit {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "    border: 1px solid #3c3c3c;"
                    "}"
                    "QListWidget {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "    border: 1px solid #3c3c3c;"
                    "}"
                    "QListWidget::item {"
                    "    padding: 6px;"
                    "}"
                    "QListWidget::item:selected {"
                    "    background-color: #3c3c3c;"
                    "}"
                    "QStatusBar {"
                    "    background-color: #2b2b2b;"
                    "    color: #ffffff;"
                    "    border-top: 1px solid #3c3c3c;"
                    "}";
    } else if (themeName == "light") {
        styleSheet = "QMainWindow {"
                    "    background-color: #f5f5f5;"
                    "    color: #333333;"
                    "}"
                    "QMenuBar {"
                    "    background-color: #f5f5f5;"
                    "    color: #333333;"
                    "    border-bottom: 1px solid #e0e0e0;"
                    "}"
                    "QMenuBar::item {"
                    "    background-color: transparent;"
                    "    padding: 6px 12px;"
                    "    margin: 2px;"
                    "}"
                    "QMenuBar::item:selected {"
                    "    background-color: #e0e0e0;"
                    "}"
                    "QMenu {"
                    "    background-color: #ffffff;"
                    "    color: #333333;"
                    "    border: 1px solid #e0e0e0;"
                    "}"
                    "QMenu::item {"
                    "    padding: 6px 24px 6px 12px;"
                    "}"
                    "QMenu::item:selected {"
                    "    background-color: #e0e0e0;"
                    "}"
                    "QTextEdit {"
                    "    background-color: #ffffff;"
                    "    color: #333333;"
                    "    border: 1px solid #e0e0e0;"
                    "}"
                    "QListWidget {"
                    "    background-color: #ffffff;"
                    "    color: #333333;"
                    "    border: 1px solid #e0e0e0;"
                    "}"
                    "QListWidget::item {"
                    "    padding: 6px;"
                    "}"
                    "QListWidget::item:selected {"
                    "    background-color: #e0e0e0;"
                    "}"
                    "QStatusBar {"
                    "    background-color: #f5f5f5;"
                    "    color: #333333;"
                    "    border-top: 1px solid #e0e0e0;"
                    "}";
    } else { // blue theme
        styleSheet = "QMainWindow {"
                    "    background-color: #0078d7;"
                    "    color: #ffffff;"
                    "}"
                    "QMenuBar {"
                    "    background-color: #0078d7;"
                    "    color: #ffffff;"
                    "    border-bottom: 1px solid #005a9e;"
                    "}"
                    "QMenuBar::item {"
                    "    background-color: transparent;"
                    "    padding: 6px 12px;"
                    "    margin: 2px;"
                    "}"
                    "QMenuBar::item:selected {"
                    "    background-color: #005a9e;"
                    "}"
                    "QMenu {"
                    "    background-color: #0078d7;"
                    "    color: #ffffff;"
                    "    border: 1px solid #005a9e;"
                    "}"
                    "QMenu::item {"
                    "    padding: 6px 24px 6px 12px;"
                    "}"
                    "QMenu::item:selected {"
                    "    background-color: #005a9e;"
                    "}"
                    "QTextEdit {"
                    "    background-color: #ffffff;"
                    "    color: #000000;"
                    "    border: 1px solid #005a9e;"
                    "}"
                    "QListWidget {"
                    "    background-color: #ffffff;"
                    "    color: #000000;"
                    "    border: 1px solid #005a9e;"
                    "}"
                    "QListWidget::item {"
                    "    padding: 6px;"
                    "}"
                    "QListWidget::item:selected {"
                    "    background-color: #005a9e;"
                    "    color: #ffffff;"
                    "}"
                    "QStatusBar {"
                    "    background-color: #0078d7;"
                    "    color: #ffffff;"
                    "    border-top: 1px solid #005a9e;"
                    "}";
    }
    
    this->setStyleSheet(styleSheet);
}

