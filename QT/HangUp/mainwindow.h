#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //四个角色的行动
    int index[4]={0,0,0,0};
    int readAction();

    int ret=0;
signals:
    void setRet();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
