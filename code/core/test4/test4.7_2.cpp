#include <iostream>
#include <string>
using namespace std;

class abstractdrinking
{
    public:
    virtual void boil()=0;
    virtual void brew()=0;
    virtual void pourInCup()=0;
    virtual void putSomething()=0;
    void makedrink()
    {
        boil();
        brew();
        pourInCup();
        putSomething();
    }
};

class tea:public abstractdrinking
{
    public:
    virtual void boil()
    {
        cout<<"boil."<<endl;
    }
    virtual void brew()
    {
        cout<<"brew tea."<<endl;
    }
    virtual void pourInCup()
    {
        cout<<"pour in cup."<<endl;
    }
    virtual void putSomething()
    {
        cout<<"put lemon."<<endl;
    }
};


class coffee:public abstractdrinking
{
    public:
    virtual void boil()
    {
        cout<<"boil."<<endl;
    }
    virtual void brew()
    {
        cout<<"brew coffee."<<endl;
    }
    virtual void pourInCup()
    {
        cout<<"pour in cup."<<endl;
    }
    virtual void putSomething()
    {
        cout<<"put suger and milk."<<endl;
    }
};

void doWork(abstractdrinking *ab)  //这不算实例化对象
{
    ab->makedrink();
    delete ab;  //防止内存泄露
}

void test1()
{
    doWork(new coffee);
    cout<<"----------------------"<<endl;
    doWork(new tea);
}

int main()
{
    test1();
    system ("pause");
    return 0;
}