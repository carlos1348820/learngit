#include <iostream>
#include <string>
#include <ctime>
#include <cmath> //幂次头文件
using namespace std;
int main()
{
    int a=100;
    do
    {
        int b=a/100;
        int c=a/10%10;
        int d=a%10;
        if (a==pow(b,3)+pow(c,3)+pow(d,3))
        {
            cout<<a<<"是一个水仙花数。"<<endl;
            a++;
        }
        else
        {
            a++;
        }
        
    } while (a<1000);
    system ("pause");
    return 0;
    
}