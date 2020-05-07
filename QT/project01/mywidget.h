#ifndef MYWIDGET_H
#define MYWIDGET_H    //防止头文件重复包含 等价于  program once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT    //宏，允许类中使用信号和槽机制

public:
    myWidget(QWidget *parent = nullptr);   //默认构造
    ~myWidget();    // 析构

private:
    Ui::myWidget *ui;
};
#endif // MYWIDGET_H
