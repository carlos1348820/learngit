#include "chooselevelsene.h"
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QSound>
#include "mypushbutton.h"
chooseLevelSene::chooseLevelSene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,588);
    //设置图标
    setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("选择关卡");
    //创建菜单栏
    QMenuBar* bar= menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu* startMenu= bar->addMenu("开始");
    //创建退出菜单项
    QAction* quitAction= startMenu->addAction("退出");
    //实线点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //选择关卡音效
    QSound* chooseSound=new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    myPushButton* backBtn=new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //点击返回
    connect(backBtn,&QPushButton::clicked,[=](){
        //qDebug()<<"clicked";
        //返回按钮音效
        backSound->play();

        emit this->chooseSceneBack();
    });


    //创建选择关卡按钮
    for(int i=0;i<20;i++)
    {
        myPushButton* menuBtn=new myPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,i/4*70+130);

        //监听每个按钮的点击事件
        connect(menuBtn,&QPushButton::clicked,[=](){
            //QString str=QString("choose %1 level").arg(i+1);
            //qDebug()<<str;

            //播放选择关卡音效
            chooseSound->play();

            //进入游戏场景
            play =new playScene(i+1);
            play->setGeometry(this->geometry());
            play->show();
            this->hide();
            //监听具体关卡返回按钮信号
            connect(play,&playScene::chooseSceneBack,this,[=](){
                QTimer::singleShot(300,this,[=](){
                    this->setGeometry(play->geometry());
                    this->show();
                    delete play;
                    play=NULL;
                });
            });
        });

        QLabel* label=new QLabel(QString::number(i+1),this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->move(25+i%4*70,i/4*70+130);
        //设置文字对齐方式(水平居中和垂直居中)
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //设置让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

//重写paintEvent事件
void chooseLevelSene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画背景上的图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);
}
