/*map (不允许容器中有重复key值元素)  和   multimap  (可以)
*/
#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int,int> &m)
{
    for(map<int,int>::const_iterator i=m.begin();i!=m.end();i++)
    {
        cout<<"  key: "<<(*i).first<<"  value: "<<(*i).second;
    }
    cout<<endl;
}
void test1()//构造和赋值   operator=
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(4,40));
    map<int,int> m1(m);
    map<int,int> m2;
    m2=m1;
    printMap(m2);//按key值从小到大排序
}

void test2()  //大小和交换   size empty  swap
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));//匿名对组
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(4,40));
    if(m.empty())  cout<<"m is empty"<<endl;
    else
    {
        cout<<m.size()<<endl;
    }
    map<int,int> m1;
    m1.swap(m);
    printMap(m);

}

void test3()//插入和删除    insert  erase  clear  operator[ ]
{
    map<int,int> m;
    //四种插入方式
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(map<int,int>::value_type(3,30));
    m[4]=40;   //可以用key访问value
    cout<<m[5]<<endl;   //默认创建key=5,value=0
    printMap(m);
    m.erase(3);  //3是key
    m.erase(m.begin());
    printMap(m);
    //清空
    m.erase(m.begin(),m.end());
    m.clear();
    printMap(m);
}

void test4()//查找和统计    find  count
{
    map<int,int> m;
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(1,10));
    m.insert(make_pair(4,40));
    map<int,int>::iterator set=m.find(3);  //3是key
    if(set!=m.end())  
    {
        cout<<" value = "<<(*set).second<<endl;
    }
    else  cout<<"we didn't find it"<<endl;
    int num = m.count(3);  //3是key
	cout << "num = " << num << endl;  //map 是0或1   multimap是正整数
}

class myCompare
{
    public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

void test5()//排序
{
    map<int,int,myCompare> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(4,40));
    for(map<int,int,myCompare>::iterator i=m.begin();i!=m.end();i++)
    {
        cout<<"  key= "<<(*i).first<<"  value= "<<(*i).second;
    }
    cout<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    system("pause");
    return 0;
}