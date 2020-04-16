#include <iostream>
#include <string>
using namespace std;

class person
{
    public:
    int* m_age;
    person(int age)
    {
        m_age=new int(age);
    }
    ~person ()
    {
        if (m_age !=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
    }
    person& operator=(person &p)
    {
        if (m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
        m_age=new int(*p.m_age);  //深拷贝
        return *this;
    }
};

class person2
{
    public:
    string m_name;
    int m_age;
    person2(string name,int age)
    {
        m_age=age;
        m_name=name;
    }
    //关系运算符重载
    bool operator==(person2 &p)
    {
        if(m_name==p.m_name&&m_age==p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

class myprint
{
    public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

class myadd
{
    public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};

void test1()
{
    person p1(18);
    person p2(20);//如果直接p2(p1)也要用深拷贝 ，因为p1的参数是new出来的
    p2=p1;   //要用深拷贝
    person p3(25);
    p3=p2=p1;   //p2=p1；和person p2=p1；调用的函数不一样
    cout<<"p1的年龄为  "<<*p1.m_age<<endl;
    cout<<"p2的年龄为  "<<*p2.m_age<<endl;
}

void test2()
{
    person2 pp1("Tom",13);
    person2 pp2("Jerry",13);
    if (pp1==pp2)
    {
        cout<<"pp1  and  pp2 are same."<<endl;
    }
    else
    {
        cout<<"pp1  and  pp2 are not same."<<endl;
    }
}

void test3()
{
    myprint pr;
    pr("hello world");//由于使用类似函数调用，称为仿函数
    myadd ad;
    int ret=ad(10,20);
    cout<<"ret= "<<ret<<endl;
    //匿名函数对象,当前行执行完即释放
    cout<<myadd()(21,12)<<endl;

}

int main()
{
    test1();
    test2();
    test3();
    system ("pause");
    return 0;
}