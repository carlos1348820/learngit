#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("yas"));
    QStringList namelist;
    namelist<<"aaa"<<"bbb"<<"ccc"<<"ddd"<<"eee";
    QList<QString> sexlist;
    sexlist<<"man"<<"woman"<<"man"<<"man"<<"woman";

    for(int i=0;i<5;i++)
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexlist[i]));//sexlist.at(i);
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(18+i)));//int转QString
    }
}

Widget::~Widget()
{
    delete ui;
}

