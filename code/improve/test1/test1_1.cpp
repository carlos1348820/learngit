#include <iostream>
#include <string>
#include "myArray.hpp"
using namespace std;
void printint(myArray<int> &arr)
{
    for(int i=0;i<arr.getsize();i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
void test1()
{
    myArray<int> ma1(5);
    for(int i=0;i<5;i++)
    {
        ma1.pushBack(i);
    }
    cout<<"ma1打印输出为"<<endl;
    printint(ma1);
    cout << "ma1的大小：" << ma1.getsize() << endl;
	cout << "ma1的容量：" << ma1.getcapacity() << endl;
    for(int i=0;i<4;i++)
    {
        ma1.popBack();
    }
    cout<<"ma1打印输出为"<<endl;
    printint(ma1);
    cout << "ma1的大小：" << ma1.getsize() << endl;
	cout << "ma1的容量：" << ma1.getcapacity() << endl;
}
int main()
{
    test1();
    system("pause");
    return 0;
}