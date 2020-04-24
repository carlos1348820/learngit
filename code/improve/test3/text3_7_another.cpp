#include <iostream>
#include <list>
using namespace std;
class person 
{
    public:
    person(string name,int age,int height)
    {
        m_age=age;
        m_height=height;
        m_name=name;
    }
    string m_name;
    int m_age;
    int m_height;
};

bool myCompare(person p1,person p2)
{
    //按照年龄进行升序，如果年龄相同按照身高进行降序
    if(p1.m_age==p2.m_age) return p1.m_height>p2.m_height;
    else return p1.m_age<p2.m_age;
}

void test1()
{
    list<person> L;
    person p1("刘备", 35 , 175);
	person p2("曹操", 45 , 180);
	person p3("孙权", 40 , 170);
	person p4("赵云", 25 , 190);
	person p5("张飞", 35 , 160);
	person p6("关羽", 35 , 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

    for(list<person>::iterator i=L.begin();i!=L.end();i++)
    {
        cout<<"name: "<<(*i).m_name
        <<"  age: "<<(*i).m_age
        <<"  height: "<<(*i).m_height<<endl;
    }
    cout<<"-------------------------------------------"<<endl;
    L.sort(myCompare);
    for(list<person>::iterator i=L.begin();i!=L.end();i++)
    {
        cout<<"name: "<<(*i).m_name
        <<"  age: "<<(*i).m_age
        <<"  height: "<<(*i).m_height<<endl;
    }
}

int main()
{
    test1();
    system ("pause");
    return 0;
}