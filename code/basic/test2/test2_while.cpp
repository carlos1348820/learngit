#include <iostream>
#include <string>
#include <ctime>  //系统时间头文件
using namespace std;
int main()
{
    int a=0;
    int b=101;
    srand((unsigned int)time(NULL));
    a=rand()%100+1;  //rand() %100生成0——99的随机数
    //cout<<a<<endl;
    while(a!=b)
    {
        cout<<"please guess the number!"<<endl;
        cin>>b;
        cout<<"The number you guess is "<<b<<endl;
        if (a>b)
        {
            cout<<"The number you guess is smaller than mine. Pleasr try again."<<endl;
        }
        else if(a<b)
        {
            cout<<"The number you guess is bigger than mine. Pleasr try again."<<endl;
        }
        else
        {
            cout<<"Ecellent. You win."<<endl;
            break; //退出当前循环
        }   
    }
    system("pause");
    return 0;
}