#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"treat";
}
void Student::treat(QString foodName)
{
    //Qstring->char*(先转成QByteArry再转成char*)
    qDebug()<<"the food:"<<foodName.toUtf8().data();
}
