//快速排序,时间复杂度为O(N*lnN),但空间复杂度较高;不稳定
#pragma once
#include <iostream>
using namespace std;

//声明
template<class T>
void quick(T &a,int min,int max);

template<class T>
int partition(T &a,int min,int max);

template<class T>
void mySwap5(T &a,T &b)
{
    T tem=a;
    a=b;
    b=tem;
}

template<class T>
void quick(T &a)
{
    int len=sizeof(a)/sizeof(a[0]);
    int min=0;
    int max=len-1;
    quick(a,min,max);
}

template<class T>
void quick(T &a,int min,int max)
{
    if(min>=max) return;//安全性校验
    //返回第一个元素排序后的索引
    int mid=partition(a,min,max);
    //左右小组分组排序（递归）
    quick(a,min,mid-1);
    quick(a,mid+1,max);

}

template<class T>
int partition(T &a,int min,int max)
{
    int right=max;
    int left=min+1;
    while(true)
    {
        while(a[right]>a[min]) 
        {
            if(right==min) break;
            right--;
        }
        while(a[min]>a[left])
        {
            if(left==max) break;
            left++;
        }
        if(left>=right) break;
        else mySwap5(a[left],a[right]);
    }
    mySwap5(a[min],a[right]);
    return right;
}