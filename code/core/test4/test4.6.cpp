/*继承      class 子类：继承方式 父类           子类也称派生类，父类也称基类
//继承方式一共有三种：公共继承   保护继承   私有继承
                       父类权限   公共继承权限    保护继承权限   私有继承权限
                         公共        公共              保护        私有
                         保护        保护              保护        私有
                         私有        不可访问          不可访问    不可访问
                   //父类中所以非静态成员属性都被子类继承
                   //父类的私有成员属性被编译器影藏，但确实被继承
继承中构造和析构顺序：子类继承父类后，当创建子类对象，也会调用父类的构造函数
                    继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
继承同名成员处理方式：当子类与父类出现同名的成员，通过子类对象   ，访问子类同名成员   直接访问即可
                                                             ，访问父类同名成员   需要加作用域
                    若子类中出现父类同名成员函数，子类同名成员会隐藏父类所有成员函数
继承同名静态成员处理方式：静态成员和非静态成员出现同名，处理方式一致
多继承语法：class 子类 ：继承方式 父类1 ， 继承方式 父类2...
          多继承可能会引发父类中有同名成员出现，需要加作用域区分     C++实际开发中不建议用多继承
菱形继承:两个派生类继承同一个基类      又有某个类同时继承者两个派生类      这种继承被称为菱形继承，或者钻石继承
        虚继承解决：virtual   最大的基类称为虚基类
        vbptr  v--virtual b--base  ptr--pointer  虚基类指针   指向vbtable(虚基类表)
*/
#include <iostream>
#include <string>
using namespace std;
class basepage
{
    public:
    void header()
    {
        cout<<"首页。。。公共头部"<<endl;
    }
    void footer()
    {
        cout<<"帮助。。。公共底部"<<endl;
    }
    void left()
    {
        cout<<"java,python,cpp公共分类列表"<<endl;
    }
};

class java:public basepage
{
    public:
    void content()
    {
        cout<<"java 视频"<<endl;
    }
};

class python:public basepage
{
    public:
    void content()
    {
        cout<<"python 视频"<<endl;
    }
};

class cpp:public basepage
{
    public:
    void content()
    {
        cout<<"c++ 视频"<<endl;
    }
};

class base
{
    public:
    base()
    {
        m_a=100;
    }
    void func()
    {
        cout<<"base 作用域下 func() 函数"<<endl;
    }
    void func(int a)
    {
        cout<<"base 作用域下 func(int a) 函数"<<endl;
    }
    int m_a;
};

class son:public base
{
    public:
    son()
    {
        m_a=200;
    }
    void func()
    {
        cout<<"son  作用域下 func() 函数"<<endl;
    }
    int m_a;
};

class base1
{
    public:
    static int m_a;
    static void func()
    {
        cout<<"base1 中静态 func()"<<endl;
    }
};
int base1::m_a=100;

class son1:public base1
{
    public:
    static int m_a;
    static void func()
    {
        cout<<"son1 中静态 func()"<<endl;
    }
};
int son1::m_a=200;

class son2:public base,public base1
{
    public:
    son2()
    {
        m_c=100;
        m_d=200;
    }
    int m_c;
    int m_d;
};

class animal
{
    public:
    int m_age;
};

class sheep:virtual public animal {};

class tuo:virtual public animal {};

class sheeptuo:public sheep,public tuo {};

void test1()
{
    cout<<"java 下载页面如下："<<endl;
    java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    cout<<"python 下载页面如下："<<endl;
    python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    cout<<"c++ 下载页面如下："<<endl;
    cpp cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
    cout << "--------------------" << endl;
}

void test2()
{
    son so;
    cout<<"son m_a="<<so.m_a<<endl;
    cout<<"base m_a="<<so.base::m_a<<endl; //若通过子类对象访问父类中同名成员，需加作用域
}

void test3()
{
    son so1;
    so1.func();
    so1.base::func();
    so1.base::func(1);
    //so1.func(1);     出错 //若子类中出现父类同名成员函数，子类同名成员会隐藏父类所有成员函数
}

void test4()
{
    son1 so2;
    cout<<"son1 m_a= "<<so2.m_a<<endl;    //通过对象访问静态成员
    cout<<"base1 m_a="<<so2.base1::m_a<<endl;
    cout<<"son1 m_a="<<son1::m_a<<endl;   //通过类名方式访问静态成员
    cout<<"base1 m_a="<<son1::base1::m_a<<endl;//第一个：：表示类名访问，第二个::代表父类作用域下
    so2.func();
    so2.base1::func();
    son1::func();
    son1::base1::func();
}

void test5()
{
    son2 so3;
    cout<<"sizeof(son2)= "<<sizeof(so3)<<endl;
    cout<<so3.base::m_a<<endl;
}

void test6()
{
    sheeptuo st;
    st.sheep::m_age=18;
    st.tuo::m_age=28;
    //菱形继承，两个父类具有相同数据，需加作用域区分，但这资源浪费了，利用虚继承可以解决这问题
    cout<<"st.sheep::m_age= "<<st.sheep::m_age<<endl;
    cout<<"st.tuo::m_age= "<<st.tuo::m_age<<endl;
    cout<<"st.m_age= "<<st.m_age<<endl;

}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    system ("pause");
    return 0;
}
