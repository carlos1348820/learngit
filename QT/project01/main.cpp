#include "mywidget.h"

#include <QApplication>//包含应用程序类的头文件

//main：程序入口  argc：命令行变量的数量  argv：命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，在QT中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    //窗口对象  myWidget:父类->myWidget
    myWidget w;
    //窗口对象，默认不会显示，必须调用
    w.show();
    //让应用程序对象进入消息循环机制
    //让代码堵塞到这行
    return a.exec();
}
