//多态的优点：1.代码组织结构清晰
//           2.可读性强
//           3.利于前期和后期的扩展以及维护
#include <iostream>
#include <string>
using namespace std;
//普通写法
class calculator
{
    public:
    int getresult(string oper)
    {
        if (oper=="+")
        {
            return m_num1+m_num2;
        }
        else if(oper=="-")
        {
            return m_num1-m_num2;
        }
        else if(oper=="*")
        {
            return m_num1*m_num2;
        }
    }
    //如果需要拓展新功能，需修改源码，真实开发中，提倡开闭原则
    //开闭原则：对拓展进行开放，对修改进行关闭
    int m_num1;
    int m_num2;
};
//多态写法
class abstractcalculator
{
    public:
    virtual int getresult()
    {
        return 0;
    }
    int m_num1;
    int m_num2;
};

class addcalculator:public abstractcalculator
{
    public:
    int getresult()
    {
        return m_num1+m_num2;
    }
};

class minuscalculator :public abstractcalculator
{
    public:
    int getresult()
    {
        return m_num1-m_num2;
    }
};

class mulcalculator :public abstractcalculator
{
    public:
    int getresult()
    {
        return m_num1*m_num2;
    }
};

void test1()
{
    calculator ca;
    ca.m_num1=10;
    ca.m_num2=5;
    cout<<ca.m_num1<<" + "<<ca.m_num2<<" = "<<ca.getresult("+")<<endl;
}

void test2()
{
    //加法计算器
    abstractcalculator *ab=new addcalculator;
    ab->m_num1=7;
    ab->m_num2=5;
    cout<<ab->m_num1<<" + "<<ab->m_num2<<" = "<<ab->getresult()<<endl;
    delete ab;//用完销毁
    //减法计算器
    ab=new minuscalculator;  //只是销毁了数据，数据类型没变
    ab->m_num1=7;
    ab->m_num2=5;
    cout<<ab->m_num1<<" - "<<ab->m_num2<<" = "<<ab->getresult()<<endl;
    delete ab;
}

int main()
{
    test1();
    test2();
    system ("pause");
    return 0;
}