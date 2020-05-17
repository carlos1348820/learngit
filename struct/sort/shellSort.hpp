//希尔排序,时间复杂度为O(N^1.3~2);不稳定
#pragma once
#include <iostream>
using namespace std;
template<class T>
void mySwap4(T &a,T &b)
{
    T tem=a;
    a=b;
    b=tem;
}

template<class T>
void shell(T &a)
{
    int h=1;
    int len=sizeof(a)/sizeof(a[0]);
    while(h<len/2)
    {
        h=2*h+1;
    }
    for(h;h>=1;h/=2)
    {
        for(int i=h;i<len;i++)
        {
            for(int j=i;j>=h;j-=h)
            {
                if(a[j-h]>a[j]) mySwap4(a[j],a[j-h]);
                else break;
            }
        }
    }
}