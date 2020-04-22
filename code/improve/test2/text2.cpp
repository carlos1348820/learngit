/*
容器：vector   算法:for_each     迭代器:vector<int>::iterator
int数据类型
自定义数据类型
套娃
*/
#include <vector>  //vector头文件
#include <algorithm> //标准算法头文件
#include <iostream>
using namespace std;

void myPrint(int val)
{
    cout<<val<<endl;
}
void test1()
{
    //创建一个vector容器，数组
    vector<int> v;
    //向容器中插入数据(尾插)
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问容器中数据
    vector<int>::iterator itBegin=v.begin();//起始迭代器：指向容器中第一个元素
    vector<int>::iterator itEnd=v.end();//结束迭代器：指向容器中最后一个元素下一个位置
    //遍历输出(第一种)
    while(itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    //第二种
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    //第三种
    for_each(v.begin(),v.end(),myPrint);
}

class person
{
    public:
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    int m_age;
    string m_name;
};

void test2()
{
    vector<person> v1;
    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    person p4("ddd",40);
    person p5("eee",50);
    //向容器中添加数据
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    //遍历容器中数据
    for(vector<person>::iterator i=v1.begin();i!=v1.end();i++)  //迭代器类似于指针
    {
        cout<<"name: "<<(*i).m_name<<"   age:"<<i->m_age<<endl;
    }
}

void test3()
{
    vector<person*> v1;
    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    person p4("ddd",40);
    person p5("eee",50);
    //向容器中添加数据
    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    v1.push_back(&p4);
    v1.push_back(&p5);
    //遍历容器中数据
    for(vector<person*>::iterator i=v1.begin();i!=v1.end();i++)  //迭代器类似于指针
    {
        cout<<"name: "<<(**i).m_name<<"   age:"<<(*i)->m_age<<endl;
    }
}

void test4()
{
    vector<vector<int>> vv;
    //创建小容器
    vector<int>  v2;
    vector<int>  v3;
    vector<int>  v4;
    vector<int>  v5;
    //向小容器中加元素
    for(int i=0;i<4;i++)
    {
        v2.push_back(i+1);
        v3.push_back(i+2);
        v4.push_back(i+3);
        v5.push_back(i+4);
    }
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    //通过大容器遍历所有数据
    for (vector<vector<int>>::iterator i=vv.begin();i!=vv.end();i++)
    {
        for(vector<int>::iterator j=(*i).begin();j!=(*i).end();j++)
        {
            cout<<*j<<"   ";
        }
        cout<<endl;
    }
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