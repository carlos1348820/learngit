/*
浅拷贝：简单的赋值拷贝操作(编译器自动提供的拷贝构造)
深拷贝：在堆区重新申请空间，进行拷贝操作
//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
初始化列表：初始化属性    构造函数 (): 属性1(值1)，属性2(值2)  {}
类对象作为类成员    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	               //析构顺序与构造相反
静态成员：static    静态成员两种访问方式:通过对象，通过类名   静态成员都有访问权限
        1.静态成员变量(也有访问权限)：所有对象共享同一份数据 ，在编译阶段分配内存 ，类内声明，类外初始化
        2.静态成员函数：所有对象共享同一个函数 ，静态成员函数只能访问静态成员变量
*/
#include <iostream>
#include <string>
using namespace std;

class phone
{
    public:
    string name;
    phone () {} //必须包含
    phone (string n):name(n) {}
};

class person
{
    public:
    int age;
    int* height;
    phone ph;
    public:
    // person (int a,int h)
    // {
    //     age=a;
    //     height=new int(h);//堆区
    // }
    person (int a,int b,string n):age(a),height(new int(b)),ph(n) {}    //初始化列表
    person (const person &p)
    {
        age=p.age;
        ph=p.ph;
        //height=p.height;  //默认的浅拷贝代码
        height=new int(*p.height);  //深拷贝
    }
    ~person()
    {
        //析构代码，将堆区开辟的数据释放
        if (height!=NULL)
        {
            delete height;  //浅拷贝带来堆区内存重复释放,解决：深拷贝
            height=NULL; 
        }
    }
};

class people
{
    public:
    static int ppa;
    int ppc;
    static void func()
    {
        cout<<"static void func()的调用"<<endl;
        ppa=100;
        //ppc=10;   //静态成员函数不可以访问静态成员变量,因为无法区分它属于哪个对象
    }
    private:
    static int ppb;
};
int people::ppa=1;
int people::ppb=10;//不可以省

void test1()
{
    person p1(18,160,"pp");
    cout<<"The age of p1 is "<<p1.age<<". The height of p1 is "<<*p1.height<<". The phone of p1 is "<<p1.ph.name<<endl;
    person p2(p1);
    cout<<"The age of p2 is "<<p2.age<<". The height of p2 is "<<*p2.height<<". The phone of p2 is "
           <<p2.ph.name<<endl;
}

void test2()
{
    //1、通过对象访问静态成员
    people pp1;
    pp1.ppa=100;
    pp1.func();
    cout<<"pp1.ppa="<<pp1.ppa<<endl;
    people pp2;
    pp2.ppa=200;
    cout<<"pp1.ppa="<<pp1.ppa<<endl; //共享同一份数据
    cout<<"pp2.ppa="<<pp2.ppa<<endl;
    //2、通过成员访问静态成员
    cout<<"ppa="<<people::ppa<<endl;
    people::func();
    //cout<<"ppb="<<people::ppb<<endl; //私有权限无法访问
}
int main()
{
    test1();
    test2();
    system ("pause");
    return 0;
}