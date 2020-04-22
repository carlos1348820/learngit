/*类模板
作用：建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表
语法：template<typename T>    template-声明创建模板    typename-表面其后面的符号是一种数据类型，可以用class代替
      类                      T-通用的数据类型，名称可以替换，通常为大写字母
类模板与函数模板区别：1.类模板没有自动类型推导的使用方式
                     2.类模板在模板参数列表中可以有默认参数
类模板中成员函数创建时机：普通类中的成员函数一开始就可以创建,类模板中的成员函数在调用时才创建
类模板对象做函数参数共有三种传入方式：1.指定传入的类型-直接显示对象的数据类型      较常用
                                    2.参数模板化-将对象中的参数变为模板进行传递
                                    3.整个类模板化-将这个对象类型 模板化进行传递
当类模板碰到继承时：1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
                   2.如果想灵活指定出父类中T的类型，子类也需变为类模板,不同子类继承时，父类数据类型可以不同
类模板成员函数类外实现 
类模板与友元：尽量不要类外实现
*/
#include <iostream>
#include <string>
#include <cxxabi.h>//使用abi
using namespace std;

template<class nametype,class agetype> class person;//先声明（因为类外实现定义用了person）
template<class nametype, class agetype>//函数模板实现,类外实现先定义
void printperson2(person<nametype,agetype>& p)
{
	cout << "类外实现 ---- 姓名： " << p.m_name << " 年龄：" << p.m_age << endl;
}

template<class nametype,class agetype=int>//默认年龄为整型
class person
{
    public:
    person (nametype name,agetype age)
    {
        m_name=name;
        m_age=age;
    }
    void showperson();
    //1、全局函数配合友元   类内实现
    friend void printperson1(person<nametype,agetype> &p)
    {
        cout<<"name= "<<p.m_name
        <<"   age= "<<p.m_age<<endl;
    }
    //全局函数配合友元  类外实现
    friend void printperson2<>(person<nametype,agetype> &p);//<>为空目标的参数列表

    nametype m_name;
    agetype m_age;
};
//成员函数类外实现
template<class nametype,class agetype>//不可以省，而且不能默认类型
void person<nametype,agetype>::showperson()//参数列表不可省
{
    cout<<"name= "<<m_name
    <<"   age= "<<m_age<<endl;
}


//指定传入的类型
void printp1(person<string,int> &p)
{
    p.showperson();
}
//参数模板化
template<class nametype,class agetype>
void printp2(person<nametype,agetype> &p)
{
    p.showperson();
    cout<<"nametype 类型为  "<<abi::__cxa_demangle(typeid(nametype).name(),0,0,0)<<endl;//第一个横线为两个下划线
    cout<<"agetype 类型为  "<<abi::__cxa_demangle(typeid(agetype).name(),0,0,0)<<endl;//数据类型显示方法
}
//整个类模板化
template<class T>
void printp3(T &p)
{
    p.showperson();
    cout<<"T 类型为  "<<abi::__cxa_demangle(typeid(T).name(),0,0,0)<<endl;
}


class person1
{
    public:
    void showperson1()
    {
        cout<<"person1 show"<<endl;
    }
};

class person2
{
    public:
    void showperson2()
    {
        cout<<"person2 show"<<endl;
    }
};

template<class T>
class myClass
{
    public:
    T obj;
    void func1()
    {
        obj.showperson1();
    }
    void func2()
    {
        obj.showperson2();
    }
};


template <class T>
class base
{
    T m;
};
class son1:public base<int> {} ;//必须指定T数据类型
template<class T1,class T2>
class son2:public base<T2>
{
    public:
    T1 obj;
};


void test1()
{
    person<string> p1("TOM",19);//person p1("Tom",19);会报错，无法自动类型推导
    p1.showperson();
    person<string,string> p2("jerry","a");
    p2.showperson();
    printp1(p1);
    printp2(p2);
    printp3(p2);
}
void test2()
{
    myClass<person1> m;
    m.func1();
    //m.func2();
}
void test3()
{
    son1 s1;
    son2<int,char> s2;
}
void test4()
{
    person<string,int> p3("BIT",22);
    printperson1(p3);
    printperson2(p3);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    system ("pause");
    return 0;
}