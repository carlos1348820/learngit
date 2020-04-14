#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    /*数组 是个常量
    一维数组：可以统计整个数组在内存中的长度（sizeof），获取数组在内存中的首地址(cout<<arr<<endl      3种定义方式
    默认16进制，（int*）arr则变为10进制；&arr[i]为第i个元素地址 
                    这里有问题（不是10进制），以后再修改
    二维数组：作用同一维数组                                                                                    4种定义方式
    */
    int ar[5]; //定义的数组为0,1,2,3,4下标
    ar[0]=6; //数组下标从0开始的
    int arr[10]={0,1,2,3,4,5};  //剩余的以0填补
    for(int i=0;i<10;i++)
    {
    cout<<arr[i]<<endl;
    }
    int ar2[]={10,20,30,40,50};  //定义数组时必须有初始长度
    int a=sizeof(arr)/sizeof(arr[0]); //计算数组元素个数
    cout<<(int*)&arr<<endl;
    int b[2][3];  //也是从0行0列开始的b[0][0]
    int b1[2][3]={{1,2,3},{4,5,6}};  
    int b2[2][3]={1,2,3,4,5,6};  //c++是按行排的
    int b3[][3]={1,2,3,4,5,6};  //列数不能省略
    sizeof(b3);     //总占用空间
    sizeof(b3[0]); //第一行占用内存
    sizeof(b3[0][0]);//每个元素占用内存
    cout<<b3<<endl; //首地址
    cout<<b3[1]<<endl; //第二行首地址
    cout<<&b3[1][2]<<endl;
    string name[3]={"a","b","c"};

    system ("pause");
    return 0;
}