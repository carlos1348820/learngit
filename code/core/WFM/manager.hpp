#pragma once    
#include <iostream>
#include <string>
#include "worker.hpp"
using namespace std;
class manager:public worker
{
    public:
    manager(int ID,string name,int deptID)
    {
        m_ID=ID;
        m_name=name;
        m_deptID=deptID;
    }
    virtual void showInfo()
    {
        cout<<"职工编号："<<m_ID
            <<"\t职工姓名："<<m_name
            <<"\t岗位："<<getDeptname()
            <<"\t岗位职责：完成老板交给的任务,并下发任务给员工"<<endl;
    }
    virtual string getDeptname()
    {
        return (string)"经理";
    }
};