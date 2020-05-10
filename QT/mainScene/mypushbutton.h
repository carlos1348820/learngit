#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    //构造函数（正常显示路径，按下后显示图片路径）
    myPushButton(QString normalImg,QString pressImg="");
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();//向下跳
    void zoom2();//向上跳

    //重新按钮按下与释放时间
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

signals:

};

#endif // MYPUSHBUTTON_H
