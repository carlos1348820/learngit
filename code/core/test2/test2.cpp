/*引用 ：给变量起别名
         引用必须初始化，且初始化后不可以改变
  引用做函数参数:函数传参时，可以利用引用的技术让形参修饰实参，可以简化指针修改实参
  引用做函数返回值：不要返回局部变量引用，函数调用作为左值
  引用的本质:指针常量 int* const(指向不可改,值可以改)
  常量引用：修饰形参，防止误操作
*/
#include <iostream>
#include <string>
using namespace std;

//值传递
void swap1(int a,int b)
{
    int c=a;
    a=b;
    b=c;
}
//地址传递
void swap2(int* a,int* b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
//引用传递，形参也会修饰实参
void swap3(int &a,int &b)  //这里的a,b只是别名
{
    int c=a;
    a=b;
    b=c;
}

int& test4()  //int&返回引用
{
    int a=10;  //局部变量，栈区
    return a;
}

int& test5()  //int&返回引用
{
    static int e=10; //静态变量，全局区
    return e;
}

void showv(const int &va)  //这样va就无法修改了
{
    //va=100;//函数调用的实参a也改了
    cout<<"value="<<va<<endl;
}

int main()
{
    int a=10;
    int &b=a;  //引用
    b=20;
    cout<<a<<endl;
    int c=100;
    swap1(a,c);
    cout<<"a="<<a<<"   c="<<c<<endl;
    swap2(&a,&c);
    cout<<"a="<<a<<"   c="<<c<<endl;
    swap3(a,c);
    cout<<"a="<<a<<"   c="<<c<<endl;
    //int &d=test4();  //出错了
    int &d=test5();
    cout<<"d="<<d<<endl;
    test5()=1000;  //函数调用作为左值，相当于e=1000;那么d也=1000
    cout<<"d="<<d<<endl;
    const int &f=10  ;//引用必须合法,加速const之后编译器将代码修改为 int temp=10;const int &f=temp;
    //f=20;         //加入const后变为只读，不可以修改
    showv(a);
    cout<<a<<endl;

    system ("pause");
    return 0;
}