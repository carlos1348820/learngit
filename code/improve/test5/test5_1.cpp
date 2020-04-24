/*常用算法
<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
<functional>定义了一些模板类,用以声明函数对象。
*/

//遍历算法    for_each   transform
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
//普通函数
void print01(int val)
{
    cout<<val<<"  ";
}
//仿函数
class print02
{
    public:
    void operator()(int val)
    {
        cout<<val<<"  ";
    }
};
void test1()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}

class TransForm
{
    public:
    int operator()(int v)
    {
        return v+100;   //这里可以变成其他逻辑运算
    }
};
void test2()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int> v2;
    v2.resize(v.size());//不能少  
    transform(v.begin(),v.end(),v2.begin(),TransForm());
    for_each(v2.begin(),v2.end(),print02());
    cout<<endl;

}

int main()
{
    test1();
    test2();
    system ("pause");
    return 0;
}