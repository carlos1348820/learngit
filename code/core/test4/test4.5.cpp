/*运算符重载：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型,也可以发生函数重载
             对于内置的数据类型的表达式的的运算符是不可能改变的    不要滥用运算符重载  
            作用：1.实现两个自定义数据类型相加的运算   operator+ 

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

int main()
{
    test1();
    system ("pause");
    return 0;
}