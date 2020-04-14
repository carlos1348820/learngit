/*从大到小的冒泡排序:
1.比较相邻，把较小的放在后面
2.一轮循环之后，最小的到了最后
3.第二轮循环重复1操作，但最后一个元素不需要比较
4.依次。。。
*/
#include <iostream>  
#include <cmath>
using namespace std;
int main()
{
    int a[10]={1,3,2,5,8,4,6,7,3,5};
    int b=sizeof(a)/sizeof(a[0])-1;
    for (int j=b;j>=1;j--)
    {
       for (int i=0;i<j;i++)
       {
          if (a[i]<a[i+1])
          {
            int c=a[i];
            a[i]=a[i+1];
            a[i+1]=c;
          }
       }
    }
    for(int i=0;i<=b;i++)
    {
    cout<<a[i]<<endl;
    }
    system ("pause");
    return 0;
}