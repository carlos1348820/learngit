//归并排序,时间复杂度为O(N*lnN),但空间复杂度较高;稳定
#pragma once
#include <iostream>
using namespace std;

//声明
template<class T>
void merge(T &a,T* tem,int min,int max);

template<class T>
void merge(T &a,T* tem,int min,int mid,int max);


template<class T>
void merge(T &a)
{
    int len=sizeof(a)/sizeof(a[0]);
    int min=0;
    int max=len-1;
    T* tem=new T[len]; //优化一下？
    merge(a,tem,min,max);
    delete[] tem;
}

//拆
template<class T>
void merge(T &a,T* tem,int min,int max)
{
    if(min>=max) return;//安全校验,核心****
    //分组
    int mid=(min+max)/2;
    //分组排序
    merge(a,tem,min,mid);
    merge(a,tem,mid+1,max);
    //归并
    merge(a,tem,min,mid,max);
}

//合
template<class T>
void merge(T &a,T* tem,int min,int mid,int max)
{
        int i=min;
        int j=mid+1;
        //比较插入
        int z=min;
        while(j<=max&&i<=mid)
        {
            if(a[i]>a[j])
            {
                *tem[z]=a[j];
                j++;
            }
            else
            {
                *tem[z]=a[i];
                i++;
            }
            z++;
        }
        while(i<=mid)
        {
            *tem[z]=a[i];
            i++;
            z++;
        }   
        while(j<=max)
        {
            *tem[z]=a[j];
            j++;
            z++;
        }
    //拷贝
    for(int k=min;k<=max;k++)
    {
        a[k]=*tem[k];
    }
}