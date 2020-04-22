/*deque （双端数组）
*/
#include <iostream>
#include <deque>
#include <algorithm>//标准算法头文件
using namespace std;

void printDeque(const deque<int> &de)
{
    for(deque<int>::const_iterator i=de.begin();i!=de.end();i++)//不加const 的话上面也不加
    {
        cout<<*i<<"  ";
    }
    cout<<endl;
}

void test1() //构造 
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);
    deque<int> d3(10,100);//10个100
    printDeque(d3);
    deque<int> d4(d3);
    printDeque(d4);
}

void test2()//赋值  operator=  assign
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    deque<int> d2;
    d2=d1;
    deque<int> d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);
    deque<int> d4;
    d4.assign(10,100);//10个100
    printDeque(d4);
}

void test3()//大小操作   empty  size   resize 
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    if(d1.empty())
    {
        cout<<"d1为空"<<endl;
    }
    else
    {
        cout<<"d1不为空"<<endl;
        cout<<"size of d1 is "<<d1.size()<<endl;
    }
    d1.resize(15,1);//以1来填充    容器变长，以默认值填充新位置；容器变短，末尾超出容器长度的元素被删除
    printDeque(d1);
}

void test4()//插入和删除  push_back   push_front  pop_back  pop_front  insert  erase  clear
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_front(i);
    }
    printDeque(d1);
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);
    d1.insert(d1.begin(),2,100);//头插2个100
    d1.insert(d1.end(),200);//尾插1个200
    printDeque(d1);
    deque<int> d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_front(0);
    d1.insert(d1.begin(),d2.begin(),d2.end());//d1头部插入d2的区间[头，尾)
    printDeque(d1);
    d1.erase(d1.begin()+2);//删除第2个元素
    printDeque(d1);
    d1.erase(d1.begin()+2,d1.end()-3);//删除区间[头+2，尾-3)
    printDeque(d1);
    d1.clear();
}

void test5()//数据存取  at  operator[]   front  back
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_front(i);
    }
    for (int i=0;i<d1.size();i++)
    {
        cout<<d1[i]<<"  ";
        cout<<d1.at(i)<<"  ";
    }
    cout<<endl;
    cout<<"front : "<<d1.front()<<endl;//第一个元素
    cout<<"back : "<<d1.back()<<endl;//最后一个元素 
}

void test6()//排序    sort(算法)
{
    deque<int> d;
    d.push_back(10);
    d.push_back(7);
    d.push_back(4);
    d.push_back(5);
    d.push_front(3);
    d.push_front(5);
    d.push_front(7);
    d.push_front(8);
    printDeque(d);
    sort(d.begin(),d.end());  //默认从小到大,对于支持随机访问的迭代器的容器，可利用sort 算法直接排序
    printDeque(d);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    system ("pause");
    return 0;
}