/*谓词
概念：1.返回bool类型的仿函数称为**谓词**
      2.如果operator()接受一个参数，那么叫做一元谓词
      3.如果operator()接受两个参数，那么叫做二元谓词
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class greaterFive
{
    public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test1()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //查找容器中大于5数字(第一个)
    vector<int>::iterator  set=find_if(v.begin(),v.end(),greaterFive());   //greaterFive() 匿名函数对象
    if(set==v.end())  cout<<"we didn't find"<<endl;
    else cout<<"we find. It is "<<*set<<endl;  

}

class MyCompare
{
    public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

void test2()
{
    vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
    sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
int main()
{
    test1();
    test2();
    system ("pause");
    return 0;
}