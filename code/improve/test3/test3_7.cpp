/*list
链表的组成：链表由一系列**结点**组成
结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
STL中的链表是一个双向循环链表
*/
#include <iostream>
#include <list>
using namespace std;

void printlist(const list<int> &l)
{
    for(list<int>::const_iterator i=l.begin();i!=l.end();i++)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;
}

void test1()//构造    
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    list<int> l2(l1.begin(),l1.end());
    list<int> l3(l2);
    printlist(l3);
    list<int> l4(10,100);  //10个100
    printlist(l4);
}

void test2()//赋值和交换   operator=   assign    swap
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    list<int> l2;
    l2=l1;
    list<int> l3;
    l3.assign(l2.begin(),l2.end());
    list<int> l4;
    l4.assign(10,100);
    cout<<"交换前："<<endl;
    printlist(l1);
    printlist(l4);
    cout<<"交换后："<<endl;
    l1.swap(l4);
    printlist(l1);
    printlist(l4);
}

void test3()  //大小操作    size  empty  resize  
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    if(l1.empty())
    {
        cout<<"l1为空"<<endl;
    }
    else
    {
        cout<<"l1不为空"<<endl;
        cout<<"size of l1: "<<l1.size()<<endl;
    }
    l1.resize(5,100);
    printlist(l1);
}

void test4()//插入和删除   push_back   push_front pop_back pop_front  insert erase  remove clear
{
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);
    printlist(l);
    l.pop_back();
    l.pop_front();
    printlist(l);
    l.insert(++(l.begin()),10);  //迭代器不支持随机访问，支持双向  所以+=1会报错   ++   -- 可以
    printlist(l);
    l.erase(l.begin());
    printlist(l);
    l.remove(10);//把所有10 删除
    printlist(l);
    l.clear();
    printlist(l);
}

void test5()//数据存取 front  back
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    //l[1];  //不可以用[]访问
    //l1.at(0); //不可以用 at()访问    迭代器不支持跳跃式访问
    cout<<"The first element of l1 is "<<l1.front()<<endl;
    cout<<"The last element of l1 is "<<l1.back()<<endl;
}

bool myCompare(int v1,int v2)
{
    return v1>v2;   //降序
}
void test6()//反转和排序   reverse   sort
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(7);
    printlist(l1);
    l1.reverse();
    printlist(l1);
    //所有不支持随机访问迭代器的容器，不可以用标准算法，内部会提高算法（成员函数）
    l1.sort();    //从小到大排序
    printlist(l1);
    l1.sort(myCompare);//从大到小排序
    printlist(l1);
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