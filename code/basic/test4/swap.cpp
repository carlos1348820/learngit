#include "swap.h"
//函数定义
void swap(int num1,int num2)//函数不需要返回值，可以声明时写void，不需要写return
{
    cout<<"交换前num1="<<num1<<endl;
    cout<<"交换前num2="<<num2<<endl;
    int num3=num1;
    num1=num2;
    num2=num3;
    cout<<"交换后num1="<<num1<<endl;
    cout<<"交换后num2="<<num2<<endl;
}