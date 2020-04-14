//通讯录管理系统
#include <iostream>
#include <string>
#define Max 1000   //宏常量
using namespace std;

struct person  //联系人结构体
{
    string name; //姓名
    string sex;     //性别 1男 2女
    int age;     //年龄
    int phone;   //电话
    string address; //地址
};

struct addressbooks //通讯录结构体
{
    struct person per[Max];  //通讯录保存的联系人
    int size;    //体会一下，这很重要
};

void addperson(addressbooks* abs)   //添加联系人
{
    if(abs->size==Max)  //判断通讯录是否满了
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        abs->per[abs->size].name=name;
        int sex;
        cout<<"请输入性别:(1.男  2.女)"<<endl;
        while(true)   //输错重新输入
        {
            cin>>sex;
            if(sex==1)
            {
                abs->per[abs->size].sex="男";
                break;
            }
            else if(sex==2)
            {
                abs->per[abs->size].sex="女";
                break;
            }
            else
            {
                cout<<"输出错误，请重新输入（只需数数字1或者2）."<<endl;
            }
        } 
        int age;
        cout<<"请输入年龄:"<<endl;
        cin>>age;
        abs->per[abs->size].age=age;
        int phone;
        cout<<"请输入电话:"<<endl;
        cin>>phone;
        abs->per[abs->size].phone=phone;
        string address;
        cout<<"请输入地址:"<<endl;
        cin>>address;
        abs->per[abs->size].address=address;
        abs->size++;
        cout<<"添加成功"<<endl;
        system("pause"); //按任意键继续
        system("cls");   //清屏 
    }
    
}

void showperson(addressbooks* abs)   //显示联系人
{
    if (abs->size==0)
    {
        cout<<"尚未建立联系人"<<endl;
    }
    else
    {
        for (int i=0;i<abs->size;i++)
        {
            cout<<"姓名："<<abs->per[i].name<<"\t";
            cout<<"性别："<<abs->per[i].sex<<"\t";   //可以尝试三目运算符哦
            cout<<"年龄："<<abs->per[i].age<<"\t";
            cout<<"电话："<<abs->per[i].phone<<"\t";
            cout<<"地址："<<abs->per[i].address<<endl;
        }
    }
    system ("pause");
    system ("cls");
}

int exist(struct addressbooks* abs,string name)//检测联系人是否存在，若存在返回数组具体位置，不存在返回-1
{
    for (int i=0;i<abs->size;i++)
    {
        if(abs->per[i].name==name)
        {
            return i;//找到了返回编号
        }
    }
    return -1;//没找到
}

void deleteper(addressbooks* abs)//删除联系人
{
    cout<<"请输入您想删除的联系人"<<endl;
    string name;
    cin>>name;
    int ret=exist(abs,name);
    if (ret==-1)  //没查到
    {
        cout<<"查无此人"<<endl;
    }
    else  //查到了
    {
        for(int i=ret;i<abs->size;i++)
        {
            abs->per[i]=abs->per[i+1];  //数据前移
        }
        abs->size--;
        cout<<"删除成功"<<endl;
    }
    system ("pause");
    system ("cls");   
}

void findper(addressbooks* abs)  //查找联系人
{
    cout<<"请输入您想查找的联系人"<<endl;
    string name;
    cin>>name;
    int set=exist(abs,name);
    if(set==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        cout<<"您查找人的姓名："<<abs->per[set].name<<"\t";
        cout<<"性别："<<abs->per[set].sex<<"\t";
        cout<<"年龄："<<abs->per[set].age<<"\t";
        cout<<"电话："<<abs->per[set].phone<<"\t";
        cout<<"地址："<<abs->per[set].address<<endl;
    }
    system ("pause");
    system ("cls");
}

void modifyper(addressbooks* abs) //修改联系人信息
{
    cout<<"请输入您要修改的联系人"<<endl;
    string name;
    cin>>name;
    int set=exist(abs,name);
    if(set==1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        string rename;
        cout<<"请输入新的姓名:"<<endl;
        cin>>rename;
        abs->per[set].name=rename;
        int resex;
        cout<<"请输入新的性别(1.男  2.女):"<<endl;
        while(true)
        {
            cin>>resex;
            if (resex==1||resex==2)
            {
                abs->per[set].sex=(resex==1?"男":"女");
                break;
            }
            else
            {
                cout<<"输出错误，请重新输入（只需数数字1或者2）."<<endl;
            }
        }
        int reage;
        cout<<"请输入新的年龄:"<<endl;
        cin>>reage;
        abs->per[set].age=reage;
        int rephone;
        cout<<"请输入新的电话:"<<endl;
        cin>>rephone;
        abs->per[set].phone=rephone;
        string readdress;
        cout<<"请输入新的住址:"<<endl;
        cin>>readdress;
        abs->per[set].address=readdress;
        cout<<"修改成功！"<<endl;
    }
    system ("pause");
    system ("cls");
}

void cleanper(addressbooks* abs)  //清空联系人
{
    abs->size=0;    //逻辑清空
    cout<<"通讯录已清空"<<endl;
    system ("pause");
    system ("cls");
}

void showmenu() //显示菜单界面
{
    cout<<"***************************"<<endl;
    cout<<"*****  1. 添加联系人  *****"<<endl;
    cout<<"*****  2. 显示联系人  *****"<<endl;
    cout<<"*****  3. 删除联系人  *****"<<endl;
    cout<<"*****  4. 查找联系人  *****"<<endl;
    cout<<"*****  5. 修改联系人  *****"<<endl;
    cout<<"*****  6. 清空联系人  *****"<<endl;
    cout<<"*****  0. 退出通讯录  *****"<<endl;
    cout<<"***************************"<<endl;
}

int main()
{
    struct addressbooks abs; //创建通讯录结构体变量
    abs.size=0;     //初始化通讯录
    int select=0;
    while(true)
    {
        showmenu();  //调用菜单
        cin>>select;
            switch(select)
        {
            case 1: //添加联系人
               addperson(&abs); //地址传递
               break;  //如果上面代码很长，需要加{}
            case 2: //显示联系人
               showperson(&abs);
               break;
            case 3: //删除联系人
               deleteper(&abs); 
               break;
            case 4: //查找联系人
               findper(&abs);
               break;
            case 5: //修改联系人
               modifyper(&abs);
               break;
            case 6: //清空联系人
               cleanper(&abs);
               break;
            case 0: //退出通讯录
               cout<<"欢迎下次使用"<<endl;
               system ("pause");
               return 0;
               break;
            default: //出错
               break;
        } 
    }
}