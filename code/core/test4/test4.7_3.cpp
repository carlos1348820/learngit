#include <iostream>
#include <string>
using namespace std;
class CPU
{
    public:
    virtual void calculate()=0;
};

class videoCard
{
    public:
    virtual void display()=0;
};

class memory
{
    public:
    virtual void storage()=0;
};

class computer
{
    private:
    CPU* m_cp;
    videoCard* m_vi;
    memory* m_me;
    public:
    computer(CPU* cp,videoCard* vi,memory* me)
    {
         m_cp=cp;
         m_vi=vi;
         m_me=me;    
    }
    void doWork()
    {
        m_cp->calculate();
        m_vi->display();
        m_me->storage();
    }
    ~computer()
    {
        if(m_cp!=NULL)
        {
            delete m_cp;
            m_cp=NULL;
        }
        if(m_vi!=NULL)
        {
            delete m_vi;
            m_vi=NULL;
        }
        if(m_me!=NULL)
        {
            delete m_me;
            m_me=NULL;
        }
    }
};

class intelCPU:public CPU
{
    void calculate()
    {
        cout<<"intel@CPU is calculating"<<endl;
    }
};
class intelVideoCard :public videoCard
{
    void display()
    {
        cout<<"intel@videoCard is displaying"<<endl;
    }
};
class intelMemory:  public memory
{
    void storage()
    {
        cout<<"intel@memory is storaging"<<endl;
    }
};

class lenovoCPU:public CPU
{
    void calculate()
    {
        cout<<"lenovo@CPU is calculating"<<endl;
    }
};
class lenovoVideoCard :public videoCard
{
    void display()
    {
        cout<<"lenovo@videoCard is displaying"<<endl;
    }
};
class lenovoMemory:  public memory
{
    void storage()
    {
        cout<<"lenovo@memory is storaging"<<endl;
    }
};

void test1()
{
    CPU* cp=new intelCPU;
    videoCard* vi=new intelVideoCard;
    memory* me=new  lenovoMemory;
    computer* co=new computer(cp,vi,me);
    co->doWork();
    delete co;
}

int main()
{
    test1();
    system ("pause");
    return 0;
}