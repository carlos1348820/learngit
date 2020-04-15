/*友元   friend
友元的目的：让一个函数或者类 访问另一个类中私有成员
友元的三种实现：1.全局函数做友元
               2.类做友元
               3.成员函数做友元
*/
#include <iostream>
#include <string>
using namespace std;

class building;
class goodfriend
{
    public:
    goodfriend();
    void visit();  //函数访问building中的属性,类外成员函数
    building* bud;
};

class building 
{
    friend void fri1(building &b);//全局函数做友元，可以访问私有成员
    //friend class goodfriend;      //类做友元
    friend void goodfriend::visit(); //成员函数做友元
    public:
    building();
    public:
    string m_sittingroom;
    private:
    string m_bedroom;
};
goodfriend::goodfriend()
{
    bud=new building;//创建建筑物对象   //由于这里用到了building ，所以要放到building类定义的后面
}
void goodfriend::visit()
{
    cout<<"You friend is visiting "<<bud->m_sittingroom<<endl;
    cout<<"You friend is visiting "<<bud->m_bedroom<<endl;
}
building::building()
    {
        m_sittingroom="si1";
        m_bedroom="be1";
    }

void fri1(building &b1)
{
    cout<<"全局函数访问:"<<b1.m_sittingroom<<endl;
    cout<<"全局函数访问:"<<b1.m_bedroom<<endl;
}

void test1()
{
    building b1;
    fri1(b1);
}

void test2()
{
    goodfriend gf;
    gf.visit();
}
int main()
{
    test1();
    test2();
    system ("pause");
    return 0;
}