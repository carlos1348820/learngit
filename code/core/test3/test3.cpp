#include <iostream>
using namespace std;

//函数的默认参数,如果传入数据则用新的，否则用默认的
//注意：1.若某位置已经有了默认参数，那这位置以后必须有默认值
//      2.函数声明和实现只能有一个有默认参数
//int func1(int a,int b=20,int c=30);
int func1(int a,int b=20,int c=30)  
{
    return a+b+c;
}

//函数占位参数
//占位参数可以有默认参数 即int =10（那么后面也可以不传入实参）
void func2(int a,int)
{
    cout<<"This is fun2"<<endl;
}

//函数重载：函数名相同，提高复用性
//满足条件：1.同一作用域下
//          2.函数名相同
//          3.函数参数类型不同，或个数不同，或顺序不同  (返回值不同不行哦)
//注意事项：1.引用作为重载条件
//          2.碰到函数默认参数
void func3()
{
    cout<<"This is func3()"<<endl;
}
void func3(int &a)  //int &a=10;不合法
{
    cout<<"This is func3  &("<<a<<")"<<endl;
}
void func3(const int &a) //const int &a=10;合法
{
    cout<<"This is func3  const &("<<a<<")"<<endl;
}
void func3(double a)
{
    cout<<"This is func3("<<a<<")"<<endl;
}
void func3(int a,double b)
{
    cout<<"This is func3("<<a<<","<<b<<")"<<endl;
}
void func3(double a,int b)
{
    cout<<"This is func3("<<a<<","<<b<<")"<<endl;
}
// void func3(int a,int b=10)   //与int a重复了，二义性，需避免  但func3(10,10)可以
// {
//     cout<<"This is func3("<<a<<","<<b<<")"<<endl;
// }

int main()
{
    cout<<func1(10,30)<<endl;  
    func2(10,20);
    func3();
    int a=10;
    func3(a);
    func3(10);
    func3(2.14);
    func3(10,2.34);
    system ("pause");
    return 0;
}