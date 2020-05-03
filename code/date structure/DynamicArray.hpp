#pragma once
#include <iostream>
using namespace std;
//动态增长内存(堆区)
//申请内存 拷贝数据 释放内存 ??   capacity  size
class DynamicArray
{
    public:
    //初始化
    DynamicArray* init_Array() 
    {
        DynamicArray* myArray=new DynamicArray;
        *myArray->size=0;
        *myArray->capacity=20;
        (*myArray)->pAddr=(int)(new int[myArray->capacity]);
        return myArray;
    }
    //大小
    int size(DynamicArray* arr)
    {
        if(arr=NULL) return;
        return arr->size;
    }
    //容量
    int capacity(DynamicArray* arr)
    {
        if(arr=NULL) return;
        return arr->capacity;
    }
    //由位置返回元素
    int at(DynamicArray* arr,int pos)
    {
        if(arr=NULL) return;
        return arr->pAddr[pos];
    }
    //插入
    void push_back(DynamicArray* arr,int value)
    {
        if(arr=NULL) return;
        //判断空间是否足够
        if(arr->size==arr->capacity)
        {
            //申请更大内存
            int* newspace =new int[2*arr->capacity];
            //拷贝
            memcpy(newspace,arr->pAddr,arr->capacity*sizeof(int));
            //释放旧空间
            delete arr->pAddr;
            //更新
            arr->capacity=arr->capacity*2;
            arr->pAddr=newspace;
        }
        //插入新元素
        *(arr->pAddr[arr->size])=value;
        arr->size++;
    }
    //删除(值)
    void remove(int value)
    {

    }
    //删除(位置)
    void remove(int* pos)
    {

    }
    //查找
    int find(int value)
    {

    }
    //打印
    void print(DynamicArray* arr)
    {
        if(arr=NULL) return;
        for(int i=0;i<(arr->size);i++)
        {
            cout<<arr->pAddr[i]<<" ";
        }
        cout<<endl;
    }
    //清空
    void clear(DynamicArray* arr)
    {
        arr->size=0;
    }
    //释放内存
    void freeSpace(DynamicArray* arr)
    {
        if(arr=NULL) return;
        if(arr->pAddr!=NULL)
        {
            delete arr->pAddr;
        }
        delete arr;
    }
    //private:
    int pAddr;//存放数据地址
    int size;//元素个数
    int capacity;//容量
};
