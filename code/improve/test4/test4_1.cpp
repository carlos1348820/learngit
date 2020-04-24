/*函数对象(仿函数)-----类（本质）
特点：1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
      2.函数对象超出普通函数的概念，函数对象可以有自己的状态
      3.函数对象可以作为参数传递
*/
#include <iostream>
#include <string>
using namespace std;

class myAdd
{
    public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};

class myPrint
{
    public:
    void operator()(string test)
    {
        cout<<test<<endl;
        count++;
    }
    int count;//内部自己状态
    myPrint()
    {
        count=0;
    }
};

void doPrint(myPrint &p,string test)
{
    p(test);
}

void test1()
{
    myAdd m;
    //函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
    cout<<m(10,4)<<endl;
    //函数对象超出普通函数的概念，函数对象可以有自己的状态
    myPrint p;
    p("hello world");
    p("hello world");
    p("hello world");
    cout<<"myPrint() 调用次数: "<<p.count<<endl;
    //函数对象可以作为参数传递
    myPrint p1;
    doPrint(p1,"hello c++");
}
int main()
{
    test1();
    system ("pause");
    return 0;
}

