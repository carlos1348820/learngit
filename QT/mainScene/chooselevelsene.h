#ifndef CHOOSELEVELSENE_H
#define CHOOSELEVELSENE_H

#include <QMainWindow>
#include "playscene.h"
class chooseLevelSene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseLevelSene(QWidget *parent = nullptr);
    //重写paintEvent事件
    void paintEvent(QPaintEvent*);
    playScene* play=NULL;

signals:
    //自定义信号，告诉主场景点击了返回
    void chooseSceneBack();

};

#endif // CHOOSELEVELSENE_H
