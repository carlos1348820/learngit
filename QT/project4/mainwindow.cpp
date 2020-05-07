#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("E:/Users/13488/learngit/QT/Image/Luffy.png"));
    //使用添加Qt资源(":+前缀名+文件名")  步骤：添加文件夹;add file->Qt->resouse;选中文件添加
    ui->actionnew->setIcon(QIcon(":/Luffy.png"));
    ui->actionopen->setIcon(QIcon(":/LuffyQ.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

