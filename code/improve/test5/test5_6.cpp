//集合算法   set_intersection  set_union  set_difference
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
//求两个集合的交集,并返回迭代器      注意:两个集合必须是有序序列
class myPrint
{
    public:
    void operator()(int v)
    {
        cout<<v<<"  ";
    }
};
void test1()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);  //0-9
		v2.push_back(i+5);  //5-14
	}
    vector<int> v;
    v.resize(min(v1.size(),v2.size()));//v的元素最多只可能有v1<v2?v1:v2
    vector<int>::iterator ret=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    for_each(v.begin(),ret,myPrint());  //注意结束迭代器的位置,或者之前用erase删了其余部分
    cout<<endl;
}

//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
//求两个集合的并集并返回迭代器            注意:两个集合必须是有序序列**
void test2()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) 
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}
    vector<int> v;
    v.resize(v1.size()+v2.size());
    vector<int>::iterator set=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    for_each(v.begin(),set,myPrint());  //注意结束迭代器的位置,或者之前用erase删了其余部分
    cout<<endl;
}

//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
//求两个集合的差集并返回迭代器        注意:两个集合必须是有序序列**
void test3()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) 
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}
    vector<int> v;
    v.resize(max(v1.size(),v2.size()));
    vector<int>::iterator set=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    cout<<"v1/v2: "<<endl;
    for_each(v.begin(),set,myPrint());  //注意结束迭代器的位置,或者之前用erase删了其余部分
    cout<<endl;
    cout<<"v2/v1: "<<endl;
    set=set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),v.begin());
    for_each(v.begin(),set,myPrint());  //注意结束迭代器的位置,或者之前用erase删了其余部分
    cout<<endl;
}

int main()
{
    test1();
    test2();
    test3();
    system("pause");
    return 0;
}