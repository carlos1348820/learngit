/*函数模板
作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
语法：template<typename T>；        template——声明创建模板            typename——表面其后面的符号是一种数据类型，可以用class代替
                                    T——通用的数据类型，名称可以替换，通常为大写字母
注意：1.自动类型推导，必须推导出一致的数据类型T,才可以使用
      2.模板必须要确定出T的数据类型，才可以使用
普通函数与函数模板区别：1.普通函数调用时可以发生自动类型转换（隐式类型转换:把char用ASCII码转换成int）
                       2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
                       3.如果利用显示指定类型的方式，可以发生隐式类型转换    //加<int>之类
调用规则如下：1.如果函数模板和普通函数都可以实现，优先调用普通函数
              2. 可以通过空模板参数列表来强制调用函数模板
              3. 函数模板也可以发生重载
              4. 如果函数模板可以产生更好的匹配,优先调用函数模板
              tip:既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
局限性：模板的通用性并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现


*/
#include <iostream>
#include <string>
using namespace std;
class person
{
    public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    string m_name;
    int m_age;
};
template<typename T>   //typename 可以换成 class
void mySwap(T&a ,T&b)//交换
{
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void func1()
{
    cout<<"this is a function"<<endl;
}

template<class T>//从大到小排序
void func2(T a[],int len)
{
    for (int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[max]<a[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            T temp=a[max];
            a[max]=a[i];
            a[i]=temp;
        }
    }
}

template <class T>
void myPrint(T a,T b)
{
    cout<<"函数模板调用1"<<endl;
}

template <class T>
void myPrint(T a)
{
    cout<<"函数模板调用2"<<endl;
}

void myPrint(int a,int b)
{
    cout<<"普通函数调用"<<endl;
}

template<class T>
bool myCompare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else return false;
}
//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<>bool myCompare(person &p1,person &p2)
{
    if(p1.m_name==p2.m_name&&p1.m_age==p2.m_age) return true;
    else return false;
}

void test1()
{
    int a=10;
    int b=3;
    //mySwap(a,b);
    mySwap<int>(a,b);   //不可以一个double,一个int
    cout<<"a= "<<a<<"   b="<<b<<endl;
    func1<int>();   //直接func1报错，因为T数据类型没确定
}

void test2()
{
    char c[]="asgtw";
    int len=sizeof(c)/sizeof(c[1]);
    func2(c,len);
    for (int i=0;i<len;i++)
    {
        cout<<c[i]<<"   ";
    }
    cout<<endl;
}

void test3()
{
    myPrint(5,6);//优先调用普通函数
    myPrint<>(5,6);//<>空模板参数列表，强制调用函数模板
    myPrint(1);
    myPrint("a","b");//把char转成int，也可以调用普通函数；但用模板更方便，所以优先
}

void test4()
{
    int d=10;
    int e=20;
    cout<<(myCompare(d,e)?"e==d":"e!=d")<<endl;
    person p1("Tom",10);
    person p2("Tom",10);
    cout<<(myCompare(p1,p2)?"p1==p2":"p1!=p2")<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    system ("pause");
    return 0;
}
