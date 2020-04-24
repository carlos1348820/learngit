/*queue  队列  先进先出    只允许从一端新增元素，从另一端移除元素    不允许有遍历行为
operator=   push pop front back empty size
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class person 
{
    public:
    person(int age,string name)
    {
        m_age=age;
        m_name=name;
    }
    int m_age;
    string m_name;
};

void test1()
{
    queue<person> q;
    person p1(18,"aaa");
    person p2(19,"bbb");
    person p3(20,"ccc");
    person p4(21,"ddd");
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"size: "<<q.size()<<endl;
    while(!q.empty())
    {
        cout<<"top.name: "<<q.front().m_name<<" top.age: "<<q.front().m_age<<endl;
        cout<<"end.name: "<<q.back().m_name<<" end.age: "<<q.back().m_age<<endl;
        q.pop();
    }
    cout<<"size: "<<q.size()<<endl;
}

int main()
{
    test1();
    system ("pause");
    return 0;
}