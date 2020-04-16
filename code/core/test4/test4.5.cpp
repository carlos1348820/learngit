/*运算符重载：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型,也可以发生函数重载;
//           对于内置的数据类型的表达式的的运算符是不可能改变的    不要滥用运算符重载  
//           作用：1.加号运算符重载:实现两个自定义数据类型相加的运算   operator+ 
//                 2.左移运算符重载:输出自定义数据类型                operator<<
//                 3.递增(减)运算符重载:实现自己的整型数据            operator++（operator--）
//                 4.赋值运算符重载:                                 operator=
//                                  若类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
//                 5.关系运算符重载:让两个自定义类型对象进行对比操作   operator==   > !+ < ...
//                 6.函数调用运算符重载:                             operator()
                                      重载后使用的方式非常像函数的调用,称为仿函数,没有固定写法,非常灵活;
*/
#include <iostream>
#include <string>
using namespace std;

class person
{
    public:
    int m_a;
    int m_b;
    //通过成员函数重载+号
    // person& operator+(person &p)  //用了编译器函数名operator+ 可以简化
    // {
    //     this->m_a+=p.m_a;
    //     this->m_b+=p.m_b;
    //     return *this;
    // }
    person() {}
    person(int a,int b)
    {
        m_a=a;
        m_b=b;
    }
};

class person2
{
    friend ostream& operator<<(ostream &cout,person2 p);
    private:
    int m_a;
    int m_b;
    public:
    person2(int a,int b)
    {
        m_a=a;
        m_b=b;
    }
    //成员函数重载左移运算符
    //void operator<<(ostream &cout)    这样的话调用变成了p<<cout   即一般不用成员函数重载左移运算符

    //重载前置++运算符
    person2& operator++()   //返回引用是为了对一个数据递增
    {
        m_a++;
        m_b++;
        return *this;
    }
    //重载后置++运算符
    person2 operator++(int)  //int代表占位参数，可以用于区分前置和后置递增    不能返回引用，因为temp会被释放
    {
        person2 temp=*this;
        m_a++;
        m_b++;
        return temp;
    }
};

//全局函数重载+号
person operator+(person p1,person p2)
{
    person temp;
    temp.m_a=p1.m_a+p2.m_a;
    temp.m_b=p1.m_b+p2.m_b;
    return temp;
}
person operator+(person p1,int a)
{
    person temp;
    temp.m_a=p1.m_a+a;
    temp.m_b=p1.m_b+a;
    return temp;
}

//全局函数重载左移运算符
ostream& operator<<(ostream &out,person2 p)    //???不能用引用
{
    out<<"m_a="<<p.m_a<<"   m_b="<<p.m_b;
    return out;  //链式编程思想
}

void test1()
{
    person p1(13,17);
    person p2=person(21,34);
    person p3=p1+p2;  //本质 person p3=p1.operator+(p2) 成员函数  和  person p3=operator+(p1,p2)  全局函数
    person p4=p1+10;
    cout<<"p3 的 m_a 是"<<p3.m_a<<endl;
    cout<<"p3 的 m_b 是"<<p3.m_b<<endl;
    cout<<"p4 的 m_a 是"<<p4.m_a<<endl;
    cout<<"p4 的 m_b 是"<<p4.m_b<<endl;
}

void test2()
{
    person2 pp1(10,10);
    cout<<pp1<<endl;  //第一个<<调用的是重载左移运算符，第二个<<调用的是默认的
}

void test3()
{
    person2 pp2(0,0);
    cout<<pp2<<endl;
    cout<<++pp2<<endl;
    cout<<pp2++<<endl;
    cout<<pp2<<endl;
}

int main()
{
    test1();
    test2();
    test3();
    system ("pause");
    return 0;
}