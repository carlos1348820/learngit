#include <iostream>
#include <cmath>
#include <string>
#include "swap.cpp"  //如果写"swap.h" 不会报错，但运行不出来
#include "add.hpp"   
using namespace std;
//#include "swap.h"
/*函数：返回值类型，函数名，参数列表，函数体语句，return表达式
  值传递时，函数形参改变不会影响实参
  函数常见样式：无参无返，有参无返，无参有返，有参有返
  函数的声明：函数定义前声明，告诉编译器函数名称及如何调用函数，函数声明可以多次，但定义只能一次
  函数的分文件编写：.h源文件  .cpp头文件（要写函数声明）或者 直接一个  .hpp文件
*/
//函数声明
//int max(int a,int b);//函数声明，有了它函数定义可以在主程序后面定义，如果函数定义在主程序之前，可以不用声明
//void swap(int num1,int num2);

//定义函数
// int max(int a,int b)
// {
//     return a>b?a:b;
// }
// void swap(int num1,int num2)//函数不需要返回值，可以声明时写void，不需要写return
// {
//     cout<<"交换前num1="<<num1<<endl;
//     cout<<"交换前num2="<<num2<<endl;
//     int num3=num1;
//     num1=num2;
//     num2=num3;
//     cout<<"交换后num1="<<num1<<endl;
//     cout<<"交换后num2="<<num2<<endl;
// }

int add(int num1,int num2)
{
    int sum=num1+num2;//称num1，num2为形式参数
    return sum;
}

int main()
{
    //函数调用
    int a=10;
    int b=20;
    swap(a,b);
    cout<<a<<"\t"<<b<<endl; //发现a,b没改变，即值传递时，函数形参改变不会影响实参
    int c=add(a,b);//称a,b为实际参数,调用函数后，实参传递给形参
    cout<<c<<endl;

    system ("pause");
    return 0;
}
