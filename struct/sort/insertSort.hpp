//插入排序,时间复杂度为O(N^2);稳定
#pragma once
#include <iostream>
using namespace std;

template<class T>
void mySwap3(T &a,T &b)
{
    T tem=a;
    a=b;
    b=tem;
}

template<class T>
void insert(T &a)
{
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<len;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j-1]>a[j])
            {
                mySwap3(a[j-1],a[j]);
            }
            else break;
        }
    }
}