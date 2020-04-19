#pragma once    
#include <iostream>
#include <string>
using namespace std;
class worker
{
    public:
    //显示个人信息
    virtual void showInfo()=0;
    //获取岗位名称
    virtual string getDeptname()=0;
    int m_ID;    //职工编号
    string m_name;    //职工姓名
    int m_deptID;    //部门编号
};