#ifndef MYCOIN_H
#define MYCOIN_H
#include <QTimer>
#include <QPushButton>

class myCoin : public QPushButton
{
    Q_OBJECT
public:
    myCoin(QString btnImg);//参数代表传入参数的路径
    //金币属性
    int posx;
    int posy;
    bool flag;//正反
    void changeFlag();//翻转
    int min=1;//图片最小值
    int max=8;//图片最大值
    QTimer* timer1;//正面翻反面定时器
    QTimer* timer2;//反面翻正面定时器

    //是否胜利标志
    bool isWin=false;

    //执行动画标准
    bool isAnimation=false;

    //重写按下
    void mousePressEvent(QMouseEvent *e);


signals:

};

#endif // MYCOIN_H
