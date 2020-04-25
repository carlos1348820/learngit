//拷贝算法  copy  replace  replace_if  swap
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//copy(iterator beg, iterator end, iterator dest); 
//容器内指定范围的元素拷贝到另一容器中            ??直接用赋值或者拷贝构造
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
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    for_each(v2.begin(),v2.end(),myPrint());
    cout<<endl;
}

//replace(iterator beg, iterator end, oldvalue, newvalue); 
//将区间内旧元素 替换成 新元素
void test2()
{
    vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中的20 替换成 2000
	cout << "替换后：" << endl;
    replace(v.begin(),v.end(),20,2000);
    for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//replace_if(iterator beg, iterator end, _pred, newvalue);  
//按条件替换元素，满足条件的替换成指定元素
class lager
{
    public:
    bool operator()(int v)
    {
        return v>=30;
    }
};
void test3()
{
    vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中大于等于的30 替换成 3000
    cout << "替换后：" << endl;
    replace_if(v.begin(),v.end(),lager(),3000);
    for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//swap(container c1, container c2);
//互换两个容器的元素
void test4()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+100);
	}
	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    system ("pause");
    return 0;
}