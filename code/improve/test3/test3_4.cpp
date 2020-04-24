/*
*/
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class person
{
    public:
    string m_name;
    int m_score;
    person(string name ,int score)
    {
        m_name=name;
        m_score=score;
    }
};

void creatperson(vector<person> &v)
{
    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name="player";
        name+=nameseed[i];//名称拼接
        int score=0;
        person p(name,score);
        v.push_back(p);
    }
}

void setscore(vector<person> &v)
{
    for(vector<person>::iterator i=v.begin();i!=v.end();i++)
    {
        deque<int> d;
        for (int j=0;j<10;j++)
        {
            int score=rand()%41+60;//60-100
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_back();//去最低分
        d.pop_front();//去最高分
        int sum=0;
        for(deque<int>::iterator j=d.begin();j!=d.end();j++)
        {
            sum+=*j;
        }
        (*i).m_score=sum/d.size();
    }
}

void test1()
{
    vector<person> v;
    creatperson(v);//创建五名选手
    setscore(v);//打分
    for(vector<person>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<"name:"<<(*i).m_name<<"  score:"<<(*i).m_score<<endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));//随机数种子
    test1();
    system ("pause");
    return 0;
}