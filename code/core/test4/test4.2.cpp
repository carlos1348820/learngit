/*对象的初始化和清理
构造函数(初始化)，析构函数（清理）    //（编译器自动调用）
构造函数语法：类名(){}
            1. 构造函数，没有返回值也不写void
            2. 函数名称与类名相同
            3. 构造函数可以有参数，因此可以发生重载
            4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
析构函数语法：~类名(){}
            1. 析构函数，没有返回值也不写void
            2. 函数名称与类名相同,在名称前加上符号  ~
            3. 析构函数不可以有参数，因此不可以发生重载
            4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
构造函数的分类：按参数分为： 有参构造和无参构造         按类型分为： 普通构造和拷贝构造
构造函数调用方式：括号法   显示法   隐式转换法
拷贝构造函数调用时机:  1.使用一个已经创建完毕的对象来初始化一个新对象
                      2.值传递的方式给函数参数传值
                      3.以值方式返回局部对象

*/
#include <iostream>
using namespace std;
class person
{
    private:
    int age;
    public:
    //普通构造
    person()//无参构造
    {
        cout<<"person无参构造函数的调用"<<endl;
    }
    person(int a)//有参构造
    {
        age=a;
        cout<<"person有参构造函数的调用"<<endl;
    }
    //拷贝构造
    person(const person &p)
    {
        age=p.age;
        cout<<"这是拷贝构造函数的调用"<<endl;
    }
    ~person()
    {
        cout<<"person析构函数的调用"<<endl;
    }
};

void test1()
{
    //括号法调用
    person p1;//局部变量，栈上，函数运行完自动销毁，然后调用析构   //默认构造调用，不要加（）
              //person p1();  //看成函数声明
    person p2(10); //括号法
    person p3(p2);
    //显示法调用
    person p4=person(10);    //person(10)是匿名对象，当前行执行结束系统自动回收
                             //person(p3);    //不要利用拷贝构造函数初始化匿名对象   编译器会认为person(p3)==person p3 重定义了
    person p5=person(p4);
    //隐式转换法调用
    person p6=10; //==person p6=person(10);
    person p7=p6;

}

int main()
{
    person p2;    //调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
    test1();      //自动调用构造和析构
    system ("pause");
    return 0;
}