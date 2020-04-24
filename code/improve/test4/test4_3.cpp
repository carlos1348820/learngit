/*内建函数对象
分类:1.算术仿函数:     实现四则运算      其中negate是一元运算，其他(plus minus multiplies divides modulus)都是二元运算     
     2.关系仿函数:     实现关系对比      equal_to  not_equal_to  greater  greater_equal  less less_equal
     3.逻辑仿函数:     实现逻辑运算      logical_and  logical_or  logical_not
用法：1.这些仿函数所产生的对象，用法和一般函数完全相同
      2.使用内建函数对象，需要引入头文件 `#include<functional>`
*/
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

//算数仿函数
void test1()
{
    negate<int> n;
    cout<<n(50)<<endl;
    plus<int> p;  //这里只要一个int,因为只允许相同类型相加
    cout<<p(10,5)<<endl;
}

//关系仿函数
void test2()
{
    vector<int> v;
    v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
    //降序
    sort(v.begin(),v.end(),greater<int>()); 
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//逻辑仿函数
void test3()
{
    vector<bool> v;
    v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());//搬运算法
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
    cout<<endl;
}

int main()
{
    test1();
    test2();
    test3();
    system ("pause");
    return 0;
}