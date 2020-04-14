#include <iostream>
#include <string>
using namespace std;
class cube
{
    private:
    double m_l;
    double m_h;
    double m_w;
    public:
    void setl(double l)
    {
        m_l=l;
    }
    double getl()
    {
        return m_l;
    }
    void seth(double h)
    {
        m_h=h;
    }
    double geth()
    {
        return m_h;
    }
    void setw(double w)
    {
        m_w=w;
    }
    double getw()
    {
        return m_w;
    }
    double area()
    {
        return 2*(m_l*m_h+m_l*m_w+m_h*m_w);
    }
    double volume()
    {
        return m_l*m_h*m_w;
    }
    //利用成员函数判断是否相等
    bool same(cube &c)
    {
    if (m_l==c.getl()&&m_h==c.geth()&&m_w==c.getw())
    {
        cout<<"This two cube are equal."<<endl;
        return true;
    }
    cout<<"This two cube are not equal."<<endl;
    return false;
    }
};

//利用全局函数判断是否相等
bool issame(cube &c1,cube &c2)//引用方式传递，不会拷贝出来数据
{
    if (c1.getl()==c2.getl()&&c1.geth()==c2.geth()&&c1.getw()==c2.getw())
    {
        return true;
    }
    return false;
}

int main()
{
    cube c1;
    c1.setl(10.3);
    c1.setw(12.1);
    c1.seth(5.6);
    cout<<"area is "<<c1.area()<<endl;
    cout<<"volume is "<<c1.volume()<<endl;
    cube c2;
    c2.setl(10.3);
    c2.setw(12.1);
    c2.seth(5.6);
    cout<<"area is "<<c2.area()<<endl;
    cout<<"volume is "<<c2.volume()<<endl;
    bool sa=issame(c1,c2);//利用全局函数判断
    if(sa)
    {
        cout<<"c1与c2相等"<<endl;
    }
    else
    {
        cout<<"c1与c2不相等"<<endl;
    }
    c1.same(c2);  //利用成员函数判断
    system ("pause");
    return 0;
}