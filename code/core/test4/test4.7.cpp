/* 多态：
分类：1.静态多态：函数重载，运算符重载，             //静态多态的函数地址早绑定————编译阶段确定函数地址
      2.动态多态：派生类，虚函数实现运行时多态       //动态多态的函数地址晚绑定————运行阶段确定函数地址
（动态）多态满足条件：有继承关系，子类重写父类中的虚函数       重写：函数返回值类型  函数名 参数列表 完全一致称为重写
多态使用条件：父类指针或引用指向子类对象
多态的优点：1.代码组织结构清晰
            2.可读性强
            3.利于前期和后期的扩展以及维护
纯虚函数和抽象类:将父类中虚函数改成纯虚函数，有纯虚函数的类也称为抽象类   纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0
抽象类特点：1.无法实例化对象
            2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
虚析构和纯虚析构:多态使用时，子类中有属性开辟到堆区，那父类指针在释放时无法调用到子类的析构代码,
                将父类中的析构函数改为虚析构或者纯虚析构以解决     纯虚析构语法：virtual ~类名() = 0; 类名::~类名(){}
                如果子类中没有堆区数据，可以不写为虚析构或纯虚析构  虚析构语法：virtual ~类名(){}
虚析构和纯虚析构共性：1.可以解决父类指针释放子类对象       
                     2.都需要有具体的函数实现             
虚析构和纯虚析构区别：1.如果是纯虚析构，该类属于抽象类，无法实例化对象
                     2.纯虚析构需要声明和代码实现
*/
#include <iostream>
#include <string>
using namespace std;

class animal
{
    public:
    //vfptr————虚（virtual）函数（function）指针（pointer）  ，它指向vftable(虚函数表)
    //，表内部记录虚函数地址 &animal::speak
    virtual void speak()  //虚函数
    {
        cout<<"animal is speaking."<<endl;
    }
};

class cat:public animal
{
    public:
    //当子类重写父类虚函数。内部会替换成子类虚函数地址，父类不发生改变
    //表内部记录虚函数地址 &cat::speak
    void speak()   //这里virtual可以省略
    {
        cout<<"cat is speaking."<<endl;
    }
};
//地址早绑定，编译阶段确定函数地址
//an.spear()定义时加入virtual 变成虚函数，地址晚绑定，运行时确定函数地址
void dospeak(animal &an)  
{
     an.speak();  
}

class base //抽象类
{
    public:
    virtual void func()=0;//纯虚函数
};

class son:public base
{
    public:
    void func()
    {
        cout<<"func 调用"<<endl;
    }
};

class animal1
{
    public:
    virtual void speak()=0;
    animal1()
    {
        cout<<"animal 构造函数"<<endl;
    }
    //虚析构解决父类指针释放子类对象释放不干净问题
    // virtual ~animal1()
    // {
    //     cout<<"animal 析构函数"<<endl;
    // }
    virtual ~animal1()=0;  //纯虚析构,需要有代码实现
};
animal1::~animal1()
{
    cout<<"aniaml 纯虚析构函数"<<endl;
}

class cat1:public animal1
{
    public:
    cat1(string name)
    {
        m_name=new string(name);
        cout<<"cat 构造函数"<<endl;
    }
    void speak()
    {
        cout<<*m_name<<" cat is speaking"<<endl;
    }
    ~cat1()
    {
        if(m_name!=NULL)
        {
            cout<<"cat 析构函数"<<endl;
            delete m_name;
            m_name=NULL;
        }
    }
    string *m_name;
};

void test1()
{
    cat ca;
    dospeak(ca); //animal &an=cat，这里发生多态
    cout<<"size of animal= "<<sizeof(animal)<<endl;//有virtual 8 ;无virtual  1 
}

void test2()
{
    //base b;
    //new base;  //抽象类无法实例化对象
    base *base=new son;
    base->func();
    delete base;
}

void test3()
{
    animal1 *an1=new cat1("Tom");
    an1->speak();
    //父类指针释放时不会调用子类析构函数，若子类有堆区数据，内存会泄露，解决方式：父类改成虚析构
    delete an1;
}

int main()
{
    test1();
    test2();
    test3();
    system ("pause");
    return 0;
}