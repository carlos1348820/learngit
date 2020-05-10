#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮默认选中
    ui->radioButton->setChecked(true);
    //选NO后打印信息
    connect(ui->radioButtonNO,&QRadioButton::clicked,this,[=](){
        qDebug()<<"选择no";
    });
    //多选按钮  2是选中   0是选中   1是半选
    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });

//    //利用listWidget写
//   QListWidgetItem* item=new QListWidgetItem("aaaa") ;
//   //将写入的放入控件中
//   ui->listWidget->addItem(item);
//   item->setTextAlignment(4);
    QStringList list;//类似于容器
    list<<"aaa"<<"bbb"<<"ccc"<<"ddd";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

