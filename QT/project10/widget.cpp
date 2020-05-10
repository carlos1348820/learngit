#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 栈控件使用
    //设置默认值
    ui->stackedWidget->setCurrentIndex(0);
    //scrollArea按钮
    connect(ui->scrollArea_push,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //toolBox按钮
    connect(ui->toolBoxPush,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //tabwidget按钮
    connect(ui->tabWidgetPush,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //combobox下拉框
    ui->comboBox->addItem("aaa");
    ui->comboBox->addItem("bbb");
    ui->comboBox->addItem("ccc");
    ui->comboBox->addItem("ddd");
    connect(ui->pushButtonBox,&QPushButton::clicked,this,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("ccc");
    });
    //利用label显示图片
//    ui->label->setPixmap(QPixmap(":/butterfly.png"));
    //利用label显示gif动态图片
    QMovie* movie=new QMovie(":/mario.gif");
    ui->label->setMovie(movie);
    //播放
    movie->start();

    //点击获取控件当前值
    connect(ui->get,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getNum();
    });
    //设置到一半
    connect(ui->half,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
     });
}

Widget::~Widget()
{
    delete ui;
}

