#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号写到singnal下   无返回值，只需声明无需实现   可以有参数，可重载
    void hungry();
    void hungry(QString foodName);

};

#endif // TEACHER_H
