#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QPushButton *parent): QPushButton(parent)
{
    qDebug()<<"我的按钮类构造调用";
}

MyPushButton::~MyPushButton()
{
    qDebug()<<"我的按钮类的析构";
}
