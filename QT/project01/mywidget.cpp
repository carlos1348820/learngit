#include "mywidget.h"
#include "ui_mywidget.h"
#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>
//命名规范：
//类名：首字母大写，单词与单词间首字母大写
//函数名：首字母小写，单词与单词间首字母大写


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)          //初始化列表
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    QPushButton* btn=new QPushButton;//创建一个按钮
    //btn->show();   //show是以顶层方式弹出窗口控件
    btn->setParent(this);  //让btn对象依赖在myWidget窗口中
    btn->setText("第一个按钮");
    btn->resize(100,30);
    QWidget* myWidget2=new QWidget;
    connect(btn,&QPushButton::clicked,myWidget2,&QWidget::show);

    QPushButton* btn2=new QPushButton("第二个按钮",this);//该方法创建的按钮按控件大小创建窗口
    btn2->move(100,100);//移动第二个按钮
    resize(600,400);//重置窗口 大小
    setFixedSize(600,400); //设置固定窗口大小
    setWindowTitle("第一个窗口"); //标题名字
    connect(btn2,&QPushButton::clicked,myWidget2,&QWidget::close);

    //创建自己按钮的对象
    MyPushButton* myBtn=new MyPushButton;
    myBtn->setParent(this); //设置到对象树中
    myBtn->setText("我的按钮");
    myBtn->move(100,200);
    //connect(发送者，发送的信号(函数地址)，信号接收者，处理的槽函数)
    connect(myBtn,&MyPushButton::clicked,this,&myWidget::close);

}

myWidget::~myWidget()
{
    delete ui;
    qDebug()<<"myWidget析构";
}

