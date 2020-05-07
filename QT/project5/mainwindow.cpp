#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建，弹出对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
    //对话框分为模态对话框与非模态对话框（还可以对其他窗口操作）
    //模态创建
//    QDialog dlg(this);
//    dlg.resize(200,100);
//    dlg.exec();  //会堵塞
//    qDebug()<<"模态对话框弹出";
     //非模态对话框
//     QDialog* dlg2=new QDialog(this);
//     dlg2->resize(200,100);
//     dlg2->setAttribute(Qt::WA_DeleteOnClose);
//     dlg2->show();
     //消息对话框
       //QMessageBox::critical(this,"critical","错误");
       //QMessageBox::information(this,"information","错误");
//       if(QMessageBox::Save== QMessageBox::question(this,"critical","错误",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))//五个参数：父亲，标题，提示内容，案件类型，默认关联回车
//        {
//           qDebug()<<"choose save";
//       }
//       else
//       {
//           qDebug()<<"choose cancle";
//       }
       //QMessageBox::warning(this,"information","错误");
      //其他标准对话框
        //颜色对话框
//        QColor color= QColorDialog::getColor(QColor(255,0,0));
//        qDebug()<<"r="<<color.red()<<" g="<<color.green()<<" b="<<color.blue();
        //文件对话框
//          QString str= QFileDialog::getOpenFileName(this,"open","E:\\Users\\13488\\Desktop","(*.txt)");//四个参数：父亲，标题，默认打开路径，过滤文件格式
//          qDebug()<<str;//返回路径
        //选择字体对话框
            bool flag;
            QFont font=QFontDialog::getFont(&flag,QFont("宋体",36));
            qDebug()<<"字体="<<font.family().toUtf8().data()<<" 字号="<<font.pointSize()<<" 是否加粗="<<font.bold()<<" 是否倾斜："<<font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

