//排序算法   sort  random_shuffle  merge  reverse
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void myPrint(int v)
{
    cout<<v<<"  ";
}

//sort(iterator beg, iterator end, _Pred); 
//对容器内元素进行排序
void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

//random_shuffle(iterator beg, iterator end);  
//指定范围内的元素随机调整次序
void test2()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  
//容器元素合并，并存储到另一容器中       注意: 两个容器必须是有序的且顺序相同
void test3()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i*10);
    }
    vector<int> v;
    v.resize(v1.size()+v2.size());//需要提前分配空间
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());//会自动给你排序（从小到大）
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

//reverse(iterator beg, iterator end);  
//将容器内元素进行反转
void test4()
{
    vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	cout << "反转后： " << endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
    test1();
    srand((unsigned int)time(NULL));
    test2();
    test3();
    test4();
    system ("pause");
    return 0;
}