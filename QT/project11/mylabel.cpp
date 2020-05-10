#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪状态
    setMouseTracking(true);

}
//鼠标进入事件
//void myLabel::enterEvent(QEvent *event)
//{
//    qDebug()<<"鼠标进入";
//}
//鼠标离开事件
//void myLabel::leaveEvent(QEvent* )
//{
//    qDebug()<<"鼠标离开";
//}
//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)  //注意
//    {
    QString str=QString("鼠标移动 x=%1   y=%2  globalx=%3   globaly%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug()<<str;
//    }
}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键按下提示信息
//    if(ev->button()==Qt::LeftButton)
//    {
    QString str=QString("鼠标按下 x=%1   y=%2  globalx=%3   globaly%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug()<<str;
//    }
}

//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
//    if(ev->button()==Qt::LeftButton)
//    {
    QString str=QString("鼠标释放 x=%1   y=%2").arg(ev->x()).arg(ev->y());
    qDebug()<<str;
//    }
}

//事件拦截
 bool myLabel::event(QEvent *e)
 {
     if(e->type()==QEvent::MouseButtonPress)
     {
         QMouseEvent* ev=static_cast<QMouseEvent*>(e);// 强制类型转换
         QString str=QString("event函数中，鼠标按下 x=%1   y=%2  globalx=%3   globaly%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
         qDebug()<<str;
         return true;//不向下分发
     }
     //其他事件交给父类处理,不向下分发
     return QLabel::event(e);
 }
