/*
C++面向对象的三大特性：分装，继承，多态
具有相同性质的对象，抽象为类
*/
/*
分装的意义：1.将属性和行为作为一个整体，表现生活中的事物    class 类名{ 访问权限：属性/行为};
            2.将属性和行为加以权限控制
权限：public       公共权限    //成员类内可以访问，类外也可以
      protected    保护权限    //        可以         不可以      子可以访问父的保护内容
      private      私有权限    //        可以         不可以        不可以
与stract区别：默认的访问权限不同（stract公有，class私有）
成员属性设为私有优点：1.自己控制读写权限
                     2.对于写权限，我们可以检测数据的有效性
*/
#include <iostream>
#include <string>
using namespace std;
const double pi=3.14;
class circle
{
    public:   //权限
    int r;  //属性：半径
    double calculateZC() //行为：周长
    {
        return 2*pi*r;
    }
};
//类中的属性和行为统一称为成员
//属性也叫成员属性，成员变量
//行为也称成员函数，成员方法
class student
{
    public:   //权限
    string name;   //属性
    int id;
    void showni()   //行为
    {
        cout<<"姓名"<<name<<"  学号："<<id<<endl;
    }
    //给姓名赋值
    void setname(string name1)
    {
        name=name1;
    }
    void setid(int id1)
    {
        id=id1;
    }
};

class person
{
    public:    //公共权限
    string name;
    protected:   //保护权限
    string car;
    private:    //私有权限
    int password;
    public:
    void func()
    {
        name="bitch";
        car="car1";
        password=12345;
    }
};

//成员属性设为私有
class person1 
{
    public:
    //写姓名
    void setname(string namer)
    {
        name=namer;
    }
    //读姓名
    string getname()
    {
        return name;
    }
    //读年龄，写年龄只能0-150
    int getage()
    {
        return age;
    }
    void setage(int ager)
    {
        if(ager<0||ager>150)
        {
            age=0;  //初始化年龄
            cout<<"You are wrong."<<endl;
            return;
        }
            age=ager;   
    }
    //写lover
    void setlover(string loverr)
    {
        lover=loverr;
    }

    private:
    string name;  //可读可写
    int age;      //可读可写
    string lover;  //只写

};

int main()
{
    //通过圆类，创建具体的圆（对象），实例化
    circle c1;
    c1.r=10;
    cout<<"圆的周长为"<<c1.calculateZC()<<endl;
    student s1;
    s1.name="bitch";
    s1.id=12345;
    s1.showni();
    student s2;
    s2.setname("bitch2");
    s2.setid(12344);
    s2.showni();
    person p1;
    p1.name="bitch3";
    // p1.car="car2";    //保护权限在类外访问不到
    // p1.password=1234;    //私有权限在类外访问不到
    p1.func();
    person1 pp;
    pp.setname("bitchi");
    cout<<pp.getname()<<endl;
    pp.setage(300);
    cout<<pp.getage()<<endl;
    pp.setlover("bitchh");

    system ("pause");
    return 0;
}