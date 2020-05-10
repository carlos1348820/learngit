#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->pushButton,&QPushButton::clicked,[=](){
//        posx+=20;
//        update();//手动调用绘图事件
//    });


//    //Pixmap绘图设备,专门为平台做了显示的优化
//    QPixmap pix(300,300);
//    //填充颜色
//    pix.fill(Qt::white);
//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(100,100),50,50);
//    //保存
//    pix.save("E:\\Users\\13488\\Desktop\\pix.png");


//    //QImage绘图设备,可以对像素访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawPixmap(0,0,QPixmap(":/Image/Luffy.png"));
//    for(int i=50;i<100;i++)
//    {
//        for(int j=50;j<100;j++)
//        {
//            img.setPixel(i,j,QRgb(qRgb(255,0,0)));
//        }
//    }
//    img.save("E:\\Users\\13488\\Desktop\\img.png");



    //QPicture 绘图设备 可以记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.drawPixmap(0,0,QPixmap(":/Image/Luffy.png"));

    painter.end();
    pic.save("E:\\Users\\13488\\Desktop\\pic.zt");//后缀名随便
    //重现绘图指令
    pic.load("E:\\Users\\13488\\Desktop\\pic.zt");
    QPixmap pix(300,300);
    QPainter painter1(&pix);
    painter1.drawPicture(0,0,pic);
    pix.save("E:\\Users\\13488\\Desktop\\pix1.png");
}

void Widget::paintEvent(QPaintEvent *)
{
    //实例化一个画家
//    QPainter painter(this);
//    //设置颜色
//    QPen pen(QColor(255,0,0));
//    //设置画笔宽度
//    pen.setWidth(3);
//    //设置风格
//    pen.setStyle(Qt::DotLine);
//    //画家使用画笔
//    painter.setPen(pen);
//    //画刷填充颜色
//    QBrush brush(Qt::cyan);//qcolor(,,)
//    //设置画刷风格
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);
//    painter.drawLine(QPoint(0,0),QPoint(100,100));//画线
//    painter.drawEllipse(QPoint(100,100),50,50);//画圆/椭圆
//    painter.drawRect(QRect(QPoint(100,100),QPoint(200,200)));//画矩形
//    painter.drawText(QRect(10,200,100,50),"painter");//画文字

//    //高级设置
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //抗锯齿,但效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    painter.drawRect(QRect(QPoint(100,100),QPoint(200,200)));
//    //画家移动（x，y)
//    painter.translate(100,0);
//    //保存画家状态
//    painter.save();
//    painter.drawRect(QRect(QPoint(100,100),QPoint(200,200)));
//    painter.translate(100,0);
//    //还原画家保存状态
//    painter.restore();
//    painter.drawRect(QRect(QPoint(100,100),QPoint(200,200)));


//    //利用画家画资源图片
//    QPainter painter(this);
//    if(posx>this->width())  posx=0;
//    painter.drawPixmap(posx,0,QPixmap(":/Image/Luffy.png"));


}

Widget::~Widget()
{
    delete ui;
}

