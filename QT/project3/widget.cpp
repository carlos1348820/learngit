#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"open file","E:\\Users\\13488\\Desktop");
        ui->lineEdit->setText(path);
        //编码格式类
        QTextCodec* codec=QTextCodec::codecForName("gbk");
        //读取内容放入textedit中,QFile默认支持的格式是UTF8
        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);
//        QByteArray array= file.readAll();
        QByteArray array;
        while (!file.atEnd())
        {
            array+=file.readLine();
        }
        //读到的数据放入textedit中
//        ui->textEdit->setText(codec->toUnicode( array));
        ui->textEdit->setText(array);
        file.close();


        //进行写入文件
        file.open(QIODevice::Append);//以追加方式写入,write是重新开始写
        file.write("aaaa");
        file.close();

        //QFileInfo文件信息类
        QFileInfo info(path);
        qDebug()<<"大小:"<<info.size()<<"  后缀名："<<info.suffix()<<"  文件名："<<info.fileName()<<"  文件路径"<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后的修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");

    });
}

Widget::~Widget()
{
    delete ui;
}

