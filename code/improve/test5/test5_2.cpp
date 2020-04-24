//查找算法   find    find_if  adjacent_find   binary_search  count  count_if
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//find(iterator beg, iterator end, value);
//find_if(iterator beg, iterator end, _Pred);  
//查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()    自定义数据类型时候，需要配合重载 operator==
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
    //重载==号，让find知道如何对比person数据类型
    bool operator==(const person &p)
    {
        if(this->m_age==p.m_age)  return true;
        else return false;
    }
};
class bigger
{
    public:
    bool operator()(int v)
    {
        return v>5;
    }
};
class biggerthan
{
    public:
    bool operator()(person p)
    {
        return p.m_age>20;
    }
};
void test1()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator set=find(v.begin(),v.end(),5);
    if(set==v.end())  cout<<"we didn't find it"<<endl;
    else cout<<"we find: "<<*set<<endl;
    set=find_if(v.begin(),v.end(),bigger());
    if(set==v.end())  cout<<"we didn't find it"<<endl;
    else cout<<"we find: "<<*set<<endl;

    vector<person> v1;
    person p1("bit1",15);
    person p2("bit2",16);
    person p3("bit3",15);
    person p4("bit4",18);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    vector<person>::iterator it=find(v1.begin(),v1.end(),p2);
    if(it==v1.end())  cout<<"we didn't find it"<<endl;
    else cout<<"we find. name: "<<(*it).m_name<<"  age: "<<it->m_age<<endl;
    it=find_if(v1.begin(),v1.end(),biggerthan());
    if(it==v1.end())  cout<<"we didn't find it"<<endl;
    else cout<<"we find. name: "<<(*it).m_name<<"  age: "<<it->m_age<<endl;
}

//adjacent_find(iterator beg, iterator end); 
//查找相邻重复元素,返回相邻元素的第一个位置的迭代器
void test2()
{
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
    vector<int>::iterator set=adjacent_find(v.begin(),v.end());
    if(set==v.end())  cout<<"we didn't find it"<<endl;
    else cout<<"we find: "<<*set<<endl;
}

//bool binary_search(iterator beg, iterator end, value); 
//查找指定的元素，查到 返回true  否则false    在无序序列中不可用
void test3()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    if(binary_search(v.begin(),v.end(),9))  cout<<"we find it"<<endl;
    else cout<<"we didn't find it"<<endl;
}

//count(iterator beg, iterator end, value);  
//统计元素出现次数        统计自定义数据类型时候，需要配合重载 operator==
void test4()
{
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
    cout<<"the count of element 4 is "<<count(v.begin(),v.end(),4)<<endl;


    vector<person> v1;
	person p1("刘备", 35);
	person p2("关羽", 35);
	person p3("张飞", 35);
	person p4("赵云", 30);
	person p5("曹操", 25);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
    person p("aaa",35);
    cout<<"the count of element whose age is 35 is "<<count(v1.begin(),v1.end(),p)<<endl;
}

//count_if(iterator beg, iterator end, _Pred);  
//按条件统计元素个数
class biggerfour
{
    public:
    bool operator()(int val)
    {
        return val>=4;
    }
};
class ageGrater
{
    public:
    bool operator()(const person p)
    {
        return p.m_age>30;
    }
};
void test5()
{
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
    cout<<"the number of element bigger than or equal to 4 is "<<count_if(v.begin(),v.end(),biggerfour())<<endl;


    vector<person> v1;
	person p1("刘备", 35);
	person p2("关羽", 35);
	person p3("张飞", 35);
	person p4("赵云", 30);
	person p5("曹操", 25);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
    cout<<"the number of people whose age is bigger than 30 is "<<count_if(v1.begin(),v1.end(),ageGrater())<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    system ("pause");
    return 0;
}