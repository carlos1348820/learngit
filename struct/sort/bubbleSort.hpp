//冒泡排序,时间复杂度为O(N^2);稳定
#pragma once
#include <iostream>
using namespace std;

template<class T>
void mySwap1(T &a,T &b)
{
    T tem=a;
    a=b;
    b=tem;
}

template<class T>
void bubble(T &a)
{
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(a[j]>a[j+1])//从小到大排序   tips：要重载>运算符
            {
                mySwap1(a[j],a[j+1]);
            }
        }
    }
}