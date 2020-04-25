//算数生成算法  accumulate  fill
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

//accumulate(iterator beg, iterator end, value); 
//计算容器元素累计总和      value是起始值
void test1()
{
    vector<int> v;
    for(int i=0;i<=100;i++)
    {
        v.push_back(i);
    }
    cout<<"The sum of v is "<<accumulate(v.begin(),v.end(),0)<<endl;
}

//fill(iterator beg, iterator end, value); 
//向容器中填充元素
class myPrint
{
    public:
    void operator()(int v)
    {
        cout<<v<<"  ";
    }
};
void test2()
{
    vector<int> v;
    v.resize(10);
    fill(v.begin(),v.end(),10);
    for_each(v.begin(),v.end(),myPrint());
    cout<<endl;
}

int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}