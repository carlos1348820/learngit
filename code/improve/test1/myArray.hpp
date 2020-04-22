#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class myArray
{
    public:
    myArray(int capacity)
    {
        //cout<<"有参构造"<<endl;
        m_capacity=capacity;
        m_size=0;
        paddress=new T[m_capacity];
    }
    //深拷贝
    myArray(const myArray &a)
    {
        //cout<<"拷贝构造"<<endl;
        m_size=a.m_size;
        m_capacity=a.m_capacity;
        paddress=new T[a.m_capacity];//注意
        for(int i=0;i<m_size;i++)
        {
            paddress[i]=a.paddress[i];
        }
    }
    myArray& operator=(const myArray &a)//防止浅拷贝问题
    {
        //cout<<"operator="<<endl;
        if(paddress!=NULL)
        {
            delete[] paddress;
            paddress=NULL;
            m_capacity=0;
            m_size=0;
        }
        m_size=a.m_size;
        m_capacity=a.m_capacity;
        paddress=new T[a.m_capacity];//注意
        for(int i=0;i<m_size;i++)
        {
            paddress[i]=a.paddress[i];
        }
        return* this;
    }
    //尾插法
    void pushBack(const T va)
    {
        //判断容量和大小关系
        if(m_capacity==m_size)
        {
            cout<<"容量已满"<<endl;
            return;
        } 
        paddress[m_size]=va;
        m_size++;
    }
    //尾删法
    void popBack()
    {
        //判断容量和大小关系
        if(m_size==0)
        {
            cout<<"无数据"<<endl;
            return;
        } 
        m_size--;
    }
    //重载[]
    T& operator[](int index)
    {
        return paddress[index];
    }
    int getcapacity()
    {
        return m_capacity;
    }
    int getsize()
    {
        return m_size;
    }
    ~myArray()
    {
        //cout<<"析构函数"<<endl;
        if(paddress!=NULL)
        {
            delete[] paddress;
            paddress=NULL;
        }
    }
    private:
    T* paddress;//数组地址
    int m_capacity;//容量
    int m_size;//大小
};