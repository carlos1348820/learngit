/*
c++对象模型：类中成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象上
this 指针：this指针指向被调用的成员函数所属的对象
           this指针是隐含每一个非静态成员函数内的一种指针
           this指针不需要定义，直接使用即可
this指针的用途：1.当形参和成员变量同名时，可用this指针来区分
                2.在类的非静态成员函数中返回对象本身，可使用return *this
空指针访问成员函数:
const修饰成员函数：常函数：成员函数后加const后我们称为这个函数为常函数
                         常函数内不可以修改成员属性
                         成员属性声明时加关键字mutable后，在常函数中依然可以修改
                  常对象：声明对象前加const称该对象为常对象
                         常对象只能调用常函数
*/
#include <iostream>
#include <string>
using namespace std;
class people {};
class person1
{
    int a;//非静态成员变量属于类的对象上
    static int b;//静态成员变量不属于类的对象上
    void func() {}  //非静态成员函数不属于类的对象上
    static void fun2() {}  //静态成员函数不属于类的对象上
};
int person1::b=10;

class person2
{
    public:
    int age;
    person2(int age)
    {
        this->age=age;  //this 指针指向被调用成员函数所属的的对象
    }
    person2& peraddage(person2 &p)//注意这里都要用引用,否则第一次的返回创建了新的对象，所以后面的this指针不适用了
    {
        this->age+=p.age;
        return *this;//this指向被调用成员函数所属的的对象的指针，那么*this 指向被调用成员函数所属的的对象
    }
};

class person3
{
    public:
    int m_age;
    void showclass()
    {
        cout<<"This is person3 class."<<endl;
    }
    void person3age()
    {
        if (this==NULL)
        {
            return;             //防止指针为空
        }
        cout<<"The age is "<<m_age<<endl; //默认为this->m_age ，空指针无法访问
    }
};

class person4
{
    public:
    int m_a=0;
    mutable int m_b=0; //加上关键字mutable，在常函数中依然可以修改
    void showperson() const//this==person* const this  ,这里加了const 变成 const person*const this ，值也不可以修改了
    {
        // m_a=100; //默认为this->m_a  ,this指针本质是一个指针常量：指向不可修改
        this->m_b=100;
    }
    void fun() {}
};

void test1()
{
    //空对象占用内存为1，是为了区分空对象占内存位置
    people pp;
    cout<<"size of pp is "<<sizeof(pp)<<endl;
    //
    person1 p1;
    cout<<"size of p1 is "<<sizeof(p1)<<endl;
}

void test2()
{
    person2 p2(18);
    cout<<"The age of p2 is "<<p2.age<<endl;
    person2 p3(10);
    p3.peraddage(p2).peraddage(p2).peraddage(p2); //链式编程思想
    cout<<"The age of p3 is "<<p3.age<<endl;
}

void test3()
{
    person3* p4=NULL;
    p4->showclass();
    p4->person3age();
}

void test4()
{
    person4 p5;
    p5.showperson();
}

void test5()
{
    const person4 p6;//加const后变成常对象
    //p6.m_a=10; //常对象不可以修改属性
    p6.m_b=100; //但加mutable就可以了
    //p6.fun();   //常对象只能调用常函数
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    system ("pause");
    return 0;
}