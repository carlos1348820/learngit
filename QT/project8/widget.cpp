#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"镜灵"<<"亮点");
    QTreeWidgetItem* item1=new QTreeWidgetItem(QStringList()<<"输出");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(item1);
    QTreeWidgetItem* item2=new QTreeWidgetItem(QStringList()<<"治疗");
    ui->treeWidget->addTopLevelItem(item2);
    QTreeWidgetItem* item3=new QTreeWidgetItem(QStringList()<<"控制");
    ui->treeWidget->addTopLevelItem(item3);
    QTreeWidgetItem* item4=new QTreeWidgetItem(QStringList()<<"拉条");
    ui->treeWidget->addTopLevelItem(item4);
    //追加子节点
    QStringList h1;
    h1<<"天狗"<<"队友死亡触发被动，立即无消耗放大";
    QTreeWidgetItem* s1=new QTreeWidgetItem(QStringList()<<h1);
    item1->addChild(s1);
}

Widget::~Widget()
{
    delete ui;
}

