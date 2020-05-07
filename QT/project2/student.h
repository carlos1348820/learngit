#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //槽函数写在slots,public,全局  下都可以   无返回值   需要声明和实现  可有参数
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
