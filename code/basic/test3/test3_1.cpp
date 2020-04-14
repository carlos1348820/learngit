#include <iostream>//数组元素逆值
#include <cmath>
using namespace std;
int main()
{
    int a[10]={1,2,3,4}; 
    int j=9;
    for (int i=0;i<=j;i++)
    {
        int b=a[i];
        a[i]=a[j];
        a[j]=b;
        j--;
    }
    for (int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
    system ("pause");
    return 0;
}