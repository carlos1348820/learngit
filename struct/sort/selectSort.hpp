//选择排序,时间复杂度为O(N^2);不稳定
#pragma once
#include <iostream>
using namespace std;
template<class T>
void mySwap2(T &a,T &b)
{
    T tem=a;
    a=b;
    b=tem;
}

template<class T>
void select(T &a)
{
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len-1;i++)
    {
        int min=i;
        for(int j=i;j<len;j++)
        {
            if(a[min]>a[j])//从小到大排序   tips：要重载>运算符
            {
                min=j;
            }
        }
        if(min!=i)
        {
            mySwap2(a[i],a[min]);
        }
    }
}