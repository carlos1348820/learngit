#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    //初始化按钮
    ui->radioButton_1->setChecked(true);
    ui->radioButton_7->setChecked(true);
    ui->radioButton_13->setChecked(true);
    ui->radioButton_19->setChecked(true);
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ret=1;
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ret==1;
    });
        connect(ui->pushButton,&QPushButton::clicked,this,[=](){
            while (ret==0) {
                //用个定时器QTimer *timer就行,自定义一个槽函数dealWith()，timer时间间隔可以设置为0毫秒，
                //connect(timer,SIGNAL(timeout()),this,SLOT(dealWith()));
                //把while循环里的东西写在定时器对应的槽函数dealWith()里
                QTimer::singleShot(1000,this,[=](){
                    qDebug()<<"doing";
                    readAction();              
                });
            };
        });

}

MainWindow::~MainWindow()
{
    delete ui;
}

//读取角色行动
int MainWindow::readAction()
{
         if(ui->radioButton_1->isChecked()==true)
         {
             index[0]=0;
         }
         else if(ui->radioButton_2->isChecked()==true)
         {
             index[0]=1;
         }
         else if(ui->radioButton_3->isChecked()==true)
         {
             index[0]=2;
         }
         else if(ui->radioButton_4->isChecked()==true)
         {
             index[0]=3;
         }
         else if(ui->radioButton_5->isChecked()==true)
         {
             index[0]=4;
         }
         else if(ui->radioButton_6->isChecked()==true)
         {
             index[0]=5;
         }


         if(ui->radioButton_7->isChecked()==true)
         {
             index[1]=0;
         }
         else if(ui->radioButton_8->isChecked()==true)
         {
             index[1]=1;
         }
         else if(ui->radioButton_9->isChecked()==true)
         {
             index[1]=2;
         }
         else if(ui->radioButton_10->isChecked()==true)
         {
             index[1]=3;
         }
         else if(ui->radioButton_11->isChecked()==true)
         {
             index[1]=4;
         }
         else if(ui->radioButton_12->isChecked()==true)
         {
             index[1]=5;
         }


         if(ui->radioButton_13->isChecked()==true)
         {
             index[2]=0;
         }
         else if(ui->radioButton_14->isChecked()==true)
         {
             index[2]=1;
         }
         else if(ui->radioButton_15->isChecked()==true)
         {
             index[2]=2;
         }
         else if(ui->radioButton_16->isChecked()==true)
         {
             index[2]=3;
         }
         else if(ui->radioButton_17->isChecked()==true)
         {
             index[2]=4;
         }
         else if(ui->radioButton_18->isChecked()==true)
         {
             index[2]=5;
         }

         if(ui->radioButton_19->isChecked()==true)
         {
             index[3]=0;
         }
         else if(ui->radioButton_20->isChecked()==true)
         {
             index[3]=1;
         }
         else if(ui->radioButton_21->isChecked()==true)
         {
             index[3]=2;
         }
         else if(ui->radioButton_22->isChecked()==true)
         {
             index[3]=3;
         }
         else if(ui->radioButton_23->isChecked()==true)
         {
             index[3]=4;
         }
         else if(ui->radioButton_24->isChecked()==true)
         {
             index[3]=5;
         }
}





