#include <iostream>  //封装一个函数，利用冒泡排序，对整型数组进行升序排序
#include <string>
using namespace std;

void shengxu(int* arr,int N)
{
    for(int i=N;i>1;i--)
    {
        for (int j=0;j<i-1;j++)
        {   
            // int* a=arr+0x1*j;
            // int* b=a+0x1;
            // if (*a>*b)
            // {
            //     int c=*a;
            //     *a=*b;
            //     *b=c;
            // }  //这个也行，但下面更简单
            if (arr[j]>arr[j+1])  //注意传进来的是整个数组的地址，所以可以用arr[j]访问数组元素，同时可以改变实参值
            {
                int a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
            }
        }
    }

}

int main()
{   int a[]={1,5,2,7,4,5,2,4,9,0,5};
    int N=sizeof(a)/sizeof(a[0]);
    shengxu(a,N);
    for (int i=0;i<N;i++)
    {
        cout<<a[i]<<endl;
    }

    system ("pause");
    return 0;
}