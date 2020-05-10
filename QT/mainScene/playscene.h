#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "mycoin.h"
#include <QMainWindow>

class playScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playScene(QWidget *parent = nullptr);
    playScene(int levelNum);
    int levelIndex;//记录所选关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent*);
    int gameArray[4][4];//二维数组维护每个关卡数据

    myCoin* coinBtn[4][4];

    //是否胜利标志
    bool isWin;

signals:
    void chooseSceneBack();

};

#endif // PLAYSCENE_H
