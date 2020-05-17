#include <iostream>
#include <ctime>
#include "bubbleSort.hpp"
#include "selectSort.hpp"
#include "insertSort.hpp"
#include "shellSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"
using namespace std;

class person
{
    public:
    string m_name;
    int m_age;
    person(){}
    person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    bool operator>(person &p1)
    {
        if(this->m_age>p1.m_age) return true;
        else return false;
    }
    void operator=(person &p)
    {
        this->m_age=p.m_age;
        this->m_name=p.m_name;
    }
};


void test_bubble()
{
    int a[]={0,9,2,4,12,3,6,3,3,0};
    bubble(a);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[]={p1,p2,p3,p4,p5};
    bubble(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}

void test_select()
{
    int a[10]={0,9,2,4,12,3,6,3,3,0};
    select(a);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[5]={p1,p2,p3,p4,p5};
    select(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}

void test_insert()
{
    // clock_t startTime,endTime;
    // int a[100000];
    // int j=0;
    // for(int i=100000;i>0;i--)
    // {
    //     a[j]=i;
    //     j++;
    // }
    // startTime=clock();
    // insert(a);
    // endTime=clock();
    // cout<<"The time of insert sort is "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[5]={p1,p2,p3,p4,p5};
    insert(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}

void test_shell()
{
    // clock_t startTime,endTime;
    // int a[10000];
    // int j=0;
    // for(int i=10000;i>0;i--)
    // {
    //     a[j]=i;
    //     j++;
    // }
    // startTime=clock();
    // shell(a);
    // endTime=clock();
    // cout<<"The time of shell sort is "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[5]={p1,p2,p3,p4,p5};
    shell(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}

void test_merge()
{
    // clock_t startTime,endTime;
    // int a[10000];
    // int j=0;
    // for(int i=10000;i>0;i--)
    // {
    //     a[j]=i;
    //     j++;
    // }
    // startTime=clock();
    // merge(a);
    // endTime=clock();
    // cout<<"The time of merge sort is "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;

    int b[]={0,9,2,4,12,3,6,3,3,0};
    merge(b);
    for(int i=0;i<10;i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[5]={p1,p2,p3,p4,p5};
    merge(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}

void test_quick()
{
    clock_t startTime,endTime;
    int a[10000];
    int j=0;
    for(int i=10000;i>0;i--)
    {
        a[j]=i;
        j++;
    }
    startTime=clock();
    quick(a);
    endTime=clock();
    cout<<"The time of merge sort is "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;

    int b[]={0,9,2,4,12,3,6,3,3,0};
    quick(b);
    for(int i=0;i<10;i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;

    person p1("aaa",14);
    person p2("bbb",11);
    person p3("ccc",15);
    person p4("ddd",12);
    person p5("eee",13);
    person p[5]={p1,p2,p3,p4,p5};
    quick(p);
    for(int i=0;i<5;i++)
    {
        cout<<p[i].m_name<<"  "<<p[i].m_age<<endl;
    }
}
int main()
{
    test_bubble();
    test_select();
    test_insert();
    test_shell();
    test_merge();
    test_quick();
    system ("pause");
    return 0;
}