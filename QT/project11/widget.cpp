#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    ID=startTimer(1000);//参数：间隔（单位毫秒）
    ID1=startTimer(2000);

    //定时器第二种方式
    QTimer* timer=new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num=1;
        ui->label_4->setText(QString::number(num++));
    });

    //点击定时按钮，定时器暂停
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer->stop();
    });


    //给label安装事件过滤器
    ui->label->installEventFilter(this);
}
//重写eventfilter事件
bool Widget::eventFilter(QObject *obj,QEvent *e)
{
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent* ev=static_cast<QMouseEvent*>(e);// 强制类型转换
            QString str=QString("事件过滤器函数中，鼠标按下 x=%1   y=%2  globalx=%3   globaly%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<str;
            return true;//不向下分发
        }
    }
    return QWidget::eventFilter(obj,e);
}

void Widget::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId()==ID)
    {
         static int num=1;
         ui->label_2->setText(QString::number(num++));
    }
    else if(ev->timerId()==ID1)
    {
        static int num1=1;
        ui->label_3->setText(QString::number(num1++));
    }
}

Widget::~Widget()
{
    delete ui;
}

