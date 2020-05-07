#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建对象
    zt=new Teacher(this);
    st=new Student(this);
    //链接
    void(Teacher::*TeacherSignal1)(void)=&Teacher::hungry;
    void(Student::*StudentSlot1)(void)=&Student::treat;
    connect(zt,TeacherSignal1,st,StudentSlot1);
    //调用函数
    classIsOver();

    //重载时  要用  函数指针->函数地址
    void(Teacher::*TeacherSignal)(QString)=&Teacher::hungry;
    void(Student::*StudentSlot)(QString)=&Student::treat;
    connect(zt,TeacherSignal,st,StudentSlot);
    QPushButton* ptn=new QPushButton("class over",this);
    resize(600,400);
    //connect(ptn,&QPushButton::clicked,this,&Widget::classIsOver); //方法一
    connect(ptn,&QPushButton::clicked,zt,TeacherSignal1);// 这里只能调用无参构造，因为槽参数不能多于信号参数 （clicked是布尔类型）
    //断开链接
    disconnect(zt,TeacherSignal1,st,StudentSlot1);
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));//QT4版本，参数直观，但类型不做检测

    //拓展
    //1.信号可以链接信号
    //2.一个信号可以链接多个槽函数
    //3.多个信号可以链接同一个槽函数
    //4.信号和槽函数参数类型必须一一对应,但信号参数个数可以多于槽参数个数


    //Lambda表达式
//[]  = 值传递     mutable 可以修改按值传递进来的拷贝（并不会改变本来的值）[]()multable{}();
    //& 引用传递
    //this 类似于=
    //a  只把a值传递
    //&a 只把a引用传递
    //a,&b       =,&a,&b     &,a,b
//()  各种参数
    [=]()
    {
        ptn->setText("aaa");
    }();
    int ret=[]()->int{return 10;}();
    //利用Lambda表达式关闭窗口
    QPushButton* put1=new QPushButton("close",this);
    put1->move(100,0);
    connect(put1,&QPushButton::clicked,this,[=](){
        this->close();
        emit zt->hungry("food1");
    });
}

Widget::~Widget()
{
    delete ui;
}
//案例
void Widget::classIsOver()
{
    emit zt->hungry();  //emit:信号发生器
    emit zt->hungry("food1");
}


