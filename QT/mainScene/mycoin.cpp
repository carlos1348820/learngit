#include "mycoin.h"
#include <QDebug>

myCoin::myCoin(QString btnImg)
{
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret)
    {
        qDebug()<<"failed";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1=new QTimer(this);
    timer2=new QTimer(this);

    //监听信号
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断如果翻完将min重置
        if(this->min>this->max)
        {
            min=1;
            isAnimation=false;
            timer1->stop();
        }
    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str=QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断如果翻完将min重置
        if(this->max<this->min)
        {
            max=8;
            isAnimation=false;
            timer2->stop();
        }
    });
}

void myCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(30);
        isAnimation=true;
        flag=false;
    }
    else
    {
        timer2->start(30);
        isAnimation=true;
        flag=true;
    }
}

void myCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation||this->isWin==true)
    {
        return;
    }
    else QPushButton::mousePressEvent(e);
}
