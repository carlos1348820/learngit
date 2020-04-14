#include <iostream>
#include <string>
using namespace std;
int main()
{
    int pig1;
    int pig2;
    int pig3;
    cout<<"we have 3 pigs. Let us measure which is the heaviest."<<endl;
    cout<<"what's the weight of pig1"<<endl;
    cin>>pig1;
    cout<<"what's the weight of pig2"<<endl;
    cin>>pig2;
    cout<<"what's the weight of pig3"<<endl;
    cin>>pig3;
    if (pig1>pig2)
    {
        if (pig3>pig1)
        {
            cout<<"the heaviest pig is pig3."<<endl;
        }
        else 
        {
            cout<<"the heaviest pig is pig1."<<endl;
        }
    }
    else
    {
        if (pig3>pig2)
        {
            cout<<"the heaviest pig is pig3."<<endl;
        }
        else 
        {
            cout<<"the heaviest pig is pig2."<<endl;
        }
    }
    system ("pause");
    return 0;
}