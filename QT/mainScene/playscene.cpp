#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QSound>
#include <QPropertyAnimation>
playScene::playScene(int levelNum)
{
    this->levelIndex=levelNum;
    //初始化游戏场景
    this->setFixedSize(320,588);
    //设置图标
    setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    QString str=QString("关卡%1").arg(levelNum);
    setWindowTitle(str);
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

    //金币翻转音效
    QSound* flipSound=new QSound(":/res/ConFlipSound.wav",this);
    //返回按钮音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);
    //胜利音效
    QSound* winSound=new QSound(":/res/LevelWinSound.wav",this);

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

    //显示当前关卡数
    QLabel* label=new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1=QString("Level:%1").arg(levelNum);
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30,this->height()-50,120,50);

    //初始化每个关卡二维数组
    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片显示
    QLabel* winLabel=new QLabel(this);
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->move(0.5*this->width()-0.5*tmpPix.width(),-tmpPix.height());

    //创建金币背景图片
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            label=new QLabel(this);
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->move(57+i*50,200+j*50);

            //创建金币
            QString str2;
            if(gameArray[i][j]==1)
            {
                str2=":/res/Coin0001.png";
            }
            else
            {
                str2=":/res/Coin0008.png";
            }
            myCoin* coin=new myCoin(str2);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);
            //给金币属性赋值
            coin->posx=i;
            coin->posy=j;
            coin->flag=gameArray[i][j];//1正面 0反面

            //将金币放入金币二维数组，以便后期维护
            coinBtn[i][j]=coin;

            //信号槽监听
            connect(coin,&myCoin::clicked,[=](){

                //翻金币音效
                flipSound->play();

                //点击按钮，将所有金币先禁用
                for(int k=0;k<4;k++)
                {
                    for(int z=0;z<4;z++)
                    {
                        coinBtn[k][z]->isWin=true;
                    }
                }

                coin->changeFlag();
                this->gameArray[i][j]=gameArray[i][j]==0?1:0;

                //周围金币翻转,延时
                QTimer::singleShot(300,this,[=](){
                    if(coin->posx+1<4)//右侧
                    {
                        coinBtn[coin->posx+1][coin->posy]->changeFlag();
                        this->gameArray[i+1][j]=gameArray[i+1][j]==0?1:0;
                    }
                    if(coin->posx-1>=0)//左侧
                    {
                        coinBtn[coin->posx-1][coin->posy]->changeFlag();
                        this->gameArray[i-1][j]=gameArray[i-1][j]==0?1:0;
                    }
                    if(coin->posy-1>=0)//上侧
                    {
                        coinBtn[coin->posx][coin->posy-1]->changeFlag();
                        this->gameArray[i][j-1]=gameArray[i][j-1]==0?1:0;
                    }
                    if(coin->posy+1<4)//下侧
                    {
                        coinBtn[coin->posx][coin->posy+1]->changeFlag();
                        this->gameArray[i][j+1]=gameArray[i][j+1]==0?1:0;
                    }

                    //翻完周围金币后解开禁用
                    for(int k=0;k<4;k++)
                    {
                        for(int z=0;z<4;z++)
                        {
                            coinBtn[k][z]->isWin=false;
                        }
                    }

                    //判断是否胜利
                    this->isWin=true;
                    for(int k=0;k<4;k++)
                    {
                        for(int z=0;z<4;z++)
                        {
                            if(coinBtn[k][z]->flag==false)
                            {
                                this->isWin=false;
                                break;
                            }
                        }
                    }
                    if(this->isWin==true)
                    {
                        //win
                        //qDebug()<<"win";
                        //将按钮胜利标志改为true
                        for(int k=0;k<4;k++)
                        {
                            for(int z=0;z<4;z++)
                            {
                                coinBtn[k][z]->isWin=true;
                            }
                        }

                        //胜利音效
                        winSound->play();

                        //将胜利图片显示
                        QPropertyAnimation* animation=new QPropertyAnimation(winLabel,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        //缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();
                    }
                });
            });
        }
    }
}

void playScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画背景上的图标
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}
