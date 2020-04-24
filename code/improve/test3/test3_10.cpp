#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
#define CHEHUA 0
#define MEISHU 1
#define YANFA  2

class worker
{
    public:
    string m_name;
    int m_salary;
};

void createWorker(vector<worker> &v)
{
    string nameSeed="ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        worker w;
        w.m_name="worker";
        w.m_name+=nameSeed[i];
        w.m_salary=rand()%10000+10000;  //10000-19999 
        v.push_back(w);
    }
}

void setGroup(vector<worker> &v,multimap<int,worker> &m)
{    
    for(vector<worker>::iterator i=v.begin();i!=v.end();i++)
    {
        //产生随机部门编号
        int set=rand()%3;//0,1,2
        m.insert(make_pair(set,(*i)));
    }
}

void showWorker(multimap<int,worker> &m)
{
    cout<<"策划部门："<<endl;
    multimap<int,worker>::iterator set=m.find(CHEHUA);//第一个策划部门
    int count=m.count(CHEHUA);//统计策划有多少人
    int index=0;
    for(;set!=m.end()&&index<count;set++)
    {
        cout<<" name: "<<(*set).second.m_name<<"  salary: "<<(*set).second.m_salary<<endl;
        index++;
    }
    cout<<"美术部门："<<endl;
    set=m.find(MEISHU);
    count=m.count(MEISHU);
    index=0;
    for(;set!=m.end()&&index<count;set++)
    {
        cout<<" name: "<<(*set).second.m_name<<"  salary: "<<(*set).second.m_salary<<endl;
        index++;
    }
    cout<<"研发部门："<<endl;
    set=m.find(YANFA);
    count=m.count(YANFA);
    index=0;
    for(;set!=m.end()&&index<count;set++)
    {
        cout<<" name: "<<(*set).second.m_name<<"  salary: "<<(*set).second.m_salary<<endl;
        index++;
    }
    
    
}

int main()
{
    srand((unsigned int)time(NULL));
    //创建员工
    vector<worker> v;
    createWorker(v);
    //分组
    multimap<int,worker> m;
    setGroup(v,m);
    showWorker(m);
    // for(vector<worker>::iterator i=v.begin();i!=v.end();i++)
    // {
    //     cout<<"name: "<<(*i).m_name<<"  salary: "<<(*i).m_salary<<endl;
    // }
    system ("pause");
    return 0;
}