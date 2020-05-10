#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //配置主场景
    //设置固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置 标题
    setWindowTitle("翻金币");
    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮音效
    QSound* startSound=new QSound(":/res/TapButtonSound.wav",this);
    //startSound->setLoops(-1);//设置无限循环播放

    //开始按钮
    myPushButton* startBtn=new myPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    //实例化选择关卡场景
    chooseScene=new chooseLevelSene;
    //监听选择关卡返回按钮信号
    connect(chooseScene,&chooseLevelSene::chooseSceneBack,this,[=](){
        QTimer::singleShot(300,this,[=](){
            this->setGeometry(chooseScene->geometry());
            this->show();
            chooseScene->hide();
        });
    });
    connect(startBtn,&QPushButton::clicked,[=](){
        //qDebug()<<"clicked";
        //播放开始音效资源
        startSound->play();
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();
        //延时
        QTimer::singleShot(500,this,[=](){
            //进入选择关卡场景中位置
            chooseScene->setGeometry(this->geometry());

            //自身影藏
            this->hide();
            chooseScene->show();
        });
    });

}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    //画背景图
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画背景上的图标
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

