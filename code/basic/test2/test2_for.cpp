#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    for(int i=1;i<=100;i++)
    {
        if(7!=i%10&&0!=i%7)
        {
            if (70>i||i>79)
            {
                cout<<i<<endl;
            }
        }
    }
    system("pause");
    return 0;
}