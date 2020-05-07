#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);//重置窗口大小

    QMenuBar* bar=menuBar();//创建菜单栏(最多只能有一个)
    setMenuBar(bar);//菜单栏放入窗口中
    QMenu* fileMenu=bar->addMenu("file");//创建菜单
    QMenu* editMenu=bar->addMenu("edit");
    fileMenu->addAction("new");//创建菜单项
    fileMenu->addSeparator();//添加分隔符
    fileMenu->addAction("open");
    fileMenu->addSeparator();
    fileMenu->addAction("save");
    editMenu->addAction("copy");

    QToolBar* toolBar=new QToolBar(this);//创建工具栏(可以有多个)
    addToolBar(Qt::LeftToolBarArea,toolBar);//工具栏放入窗口中,默认是 上方
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);//左或者右停靠
    toolBar->setFloatable(false);//设置浮动
    toolBar->setMovable(true);//设置释放可以移动
    QAction* newAction=fileMenu->addAction("open");
    toolBar->addAction(newAction);//共用一个  open
    toolBar->addSeparator();//分割线
    QPushButton* ptn=new QPushButton("aa",this);
    toolBar->addWidget(ptn);//工具栏放一些按钮

    QStatusBar* stBar=statusBar();//创建状态栏，最多有一个
    setStatusBar(stBar);//状态栏放入窗口
    QLabel* label=new QLabel("tips",this);//放标签控件
    stBar->addWidget(label);
    QLabel* label2=new QLabel("RightTips",this);//放标签控件
    stBar->addPermanentWidget(label2);

    QDockWidget* dockwidget=new QDockWidget("float",this);//浮动窗口
    addDockWidget(Qt::BottomDockWidgetArea,dockwidget);//位置
    dockwidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    QTextEdit* Edit=new QTextEdit(this);//设置中心部件，最多有一个
    setCentralWidget(Edit);
}

MainWindow::~MainWindow()
{
}

