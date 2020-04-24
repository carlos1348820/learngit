/*  set（不可以有相同元素）  和  multiset （可以）
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;

void printSet(const set<int> &s)
{
    for(set<int>::const_iterator i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;
}

void test1()//构造和赋值    operator+  
{
    set<int> s1;
    s1.insert(20);   //set容器插入数据只有insert
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);  //set容器元素插入时自动排序。插入重复元素值不会成功
    set<int> s2(s1);
    printSet(s2);
    set<int> s3;
    s3=s2;
    printSet(s3);
}

void test2()//大小和交换   size  empty  swap
{
    set<int> s1;
    s1.insert(20);
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(30);
    set<int> s2;
    s2.insert(200);
    s2.insert(400);
    s2.insert(100);
    s2.insert(300);
    if(s1.empty())  cout<<"s1 is empty"<<endl;
    else cout<<"size of s1: "<<s1.size()<<endl;
    s1.swap(s2);
    printSet(s1);
}

void test3()//插入和删除    insert    erase    clear
{
    set<int> s1;
    s1.insert(20);
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    s1.erase(++s1.begin());//删除某个位置
    printSet(s1);
    s1.erase(30);//删除某个元素
    printSet(s1);
    s1.erase(s1.begin(),s1.end());
    s1.clear();
    printSet(s1);
}

void test4()//查找和统计    find   count
{
    //find    查找是否存在,若存在，返回该键的元素的迭代器；若不存在，返回end
    set<int> s1;
    s1.insert(20);
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    if(s1.find(50)!=s1.end())  cout<<"we find the element"<<endl;
    else cout<<"we didn't find the element"<<endl;
    cout<<"the number of element 20 is "<<s1.count(20)<<endl;//set是0或1
}

void test5()//set和multiset区别
{
    set<int> s1;
    pair<set<int>::iterator,bool> ret=s1.insert(10);//set插入数据时返回一个迭代器和一个bool数据
    if(ret.second)  cout<<"插入数据成功"<<endl;
    else cout<<"插入数据失败"<<endl;
    ret=s1.insert(10);
    if(ret.second)  cout<<"插入数据成功"<<endl;
    else cout<<"插入数据失败"<<endl;
    multiset<int> m1;
    m1.insert(20);//multiset插入数据时只返回迭代器
    m1.insert(20);
    for (multiset<int>::iterator i=m1.begin();i!=m1.end();i++)
    {
        cout<<*i<<"  ";
    }
    cout<<endl;
}

void test6()//pair对组创建   make_pair
{
    pair<string,int> p("Tom",20);
    cout<<"name: "<<p.first
    <<"  age: "<<p.second<<endl;
    pair<string,int> p2=make_pair("Terry",18);
}

class myCompare
{
    public:
    bool operator()(int v1,int v2)  
    {
        return v1>v2;
    }
};
class person
{
    public:
    string m_name;
    int m_age;
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
};
class myCom
{
    public:
    bool operator()(const person &p1,const person &p2)
    {
        return p1.m_age>p2.m_age;
    }
};
void test7()//set容器排序    
{
    //set存放内置数据类型
    set<int,myCompare> s1; //默认从小到大,利用仿函数可以变成从大到小排序
    s1.insert(20);
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(50);
    for(set<int,myCompare>::const_iterator i=s1.begin();i!=s1.end();i++)
    {
        cout<<*i<<"  ";
    } 
    cout<<endl;

    //set存放自定义数据类型
    set<person,myCom> s;  //自定义数据类型要指定排序规则
    person p1("刘备", 23);
	person p2("关羽", 27);
	person p3("张飞", 25);
	person p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
    for(set<person,myCom>::const_iterator i=s.begin();i!=s.end();i++)
    {
        cout<<"name: "<<(*i).m_name<<"  age: "<<(*i).m_age<<endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    system ("pause");
    return 0;
}