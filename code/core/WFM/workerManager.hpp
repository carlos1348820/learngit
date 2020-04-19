#pragma once    //防止头文件重复包含
#include <iostream>
#include <string>
#include <fstream>
#include "worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"
#define FILENAME "empFile.txt"
using namespace std;
class workerManager
{
    public:
    workerManager()
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);
        //文件不存在情况
        if(!ifs.is_open())
        {
            //cout<<"文件不存在！"<<endl;
            //初始化
            m_empNum=0;
            m_wo=NULL;
            m_fileEmpty=true;
            ifs.close();
            return;
        }
        //文件存在，且无记录
        char ch;
        ifs>>ch; //读一个字符
        if(ifs.eof())  //若文件为空，那么ifs.eof()==true
        {
            //cout<<"文件为空！"<<endl;
            m_empNum=0;
            m_wo=NULL;
            m_fileEmpty=true;
            ifs.close();
            return;
        }
        //文件存在且不为空（这种情况是为了可以直接在txt文档中加员工）
        int num=get_num();
        //cout<<"文件存在，职工人数为："<<num<<endl;
        m_empNum=num;
        m_fileEmpty=false;
        m_wo=new worker*[m_empNum];   //开辟空间
        init_ept();  //存放文件中的数据
        // for(int i=0;i<m_empNum;i++)
        // {
        //     cout<<"职工号： " << m_wo[i]->m_ID
		// 	<< " 职工姓名： " << this->m_wo[i]->m_name
		// 	<< " 部门编号： " << this->m_wo[i]->m_deptID << endl;
        // }
    }
    //菜单界面
    void showMenu()
    {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
    }
    //退出程序
    void quitsystem()
    {
        cout<<"欢迎下次使用"<<endl;
        system ("pause");
        exit(0);  //调用这个函数会退出系统
    }
    //添加新员工
    void addemp()
    {
        cout<<"请输入添加职工数目："<<endl;
        int addnum=0;
        cin>>addnum;
        if(addnum>0)
        {
            //计算新空间大小
            int newSize=m_empNum+addnum;
            //开辟空间
            worker** newspace=new worker*[newSize];
            //拷贝
            if(m_wo!=NULL)
            {
                for(int i=0;i<m_empNum;i++)
                {
                    newspace[i]=m_wo[i];
                }
            }
            //添加新数据
            for(int i=0;i<addnum;i++)
            {
                int ID;
                string name;
                int deptID;
                bool ret=true;
                cout<<"请输入第 "<<i+1<<" 个新员工编号"<<endl;
                while(ret)
                {
                    cin>>ID;
                    if(isExist(ID)!=-1)
                    {
                        cout<<"该员工编号已存在，请重新输入："<<endl;
                        ret=true;
                    }
                    else
                    {
                        ret=false;
                    }
                }
                cout<<"请输入第 "<<i+1<<" 个新员工姓名"<<endl;
                cin>>name;
                cout << "请选择新员工的岗位：" << endl;
			    cout << "1、普通职工" << endl;
			    cout << "2、经理" << endl;
			    cout << "3、老板" << endl;
                worker* wo=NULL;
                bool temp;
                while (true)
                {
                    cin>>deptID;
                    switch(deptID)
                    {
                        case 1:
                        wo=new employee(ID,name,deptID);
                        temp=true;
                        break;
                        case 2:
                        wo=new manager(ID,name,deptID);
                        temp=true;
                        break;
                        case 3:
                        wo=new boss(ID,name,deptID);
                        temp=true;
                        break;
                        default:
                        cout<<"输入错误，请重新输入其岗位"<<endl;
                        temp=false;
                        break;
                    }
                    if(temp==true) break;
                }
                //将创建职工职责保存到数组中
                newspace[m_empNum+i]=wo;
            }
            //释放原有空间
            delete[] m_wo;
            //更改新空间指向
            m_wo=newspace;
            m_empNum=newSize;
            cout<<"成功添加 "<<addnum<<" 名新员工"<<endl;
            //保存数据
            save();
            //更新文件状态
            m_fileEmpty=false;
        }
        else
        {
            cout<<"输入错误！"<<endl;
        } 
        system ("pause");
        system ("cls");     
    }
    //保存文件
    void save()
    {
        ofstream ofs;
        ofs.open(FILENAME,ios::out);
        for (int i=0;i<m_empNum;i++)
        {
            ofs<<m_wo[i]->m_ID<<"   "
               <<m_wo[i]->m_name<<"   "
               <<m_wo[i]->m_deptID<<endl;
        }
        ofs.close();
    }
    //统计文件中人数
    int get_num()
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);
        int ID;
        string name;
        int deptID;
        int num=0;
        while(ifs>>ID&&ifs>>name&&ifs>>deptID)
        {
            num++;
        }
        return num;
    }
    //初始化职工
    void init_ept()
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);
        int ID;
        string name;
        int deptID;
        int index=0;
        while(ifs>>ID&&ifs>>name&&ifs>>deptID)
        {
            worker* wo=NULL;
            if (deptID==1)
            {
                wo=new employee(ID,name,deptID);
            }
            else if (deptID==2)
            {
                wo=new manager(ID,name,deptID); 
            }
            else
            {
                wo=new boss(ID,name,deptID);
            }   
            m_wo[index]=wo;
            index++;
        }
        ifs.close();
    }
    //显示职工
    void showemp()
    {
        //判断文件是否为空
        if(m_fileEmpty)
        {
            cout<<"文件无记录"<<endl;
        }
        else
        {
            for(int i=0;i<m_empNum;i++)
            {
                //利用多态调用程序接口
                m_wo[i]->showInfo();
            }
        }
        system ("pause");
        system ("cls");
    }
    //判断职工是否存在
    int isExist(int ID)
    {
        int index=-1;
        for (int i=0;i<m_empNum;i++)
        {
            if(m_wo[i]->m_ID==ID)
            {
                index=i;
            }
        }
        return index;
    }
    //删除职工
    void delemp()
    {
        if(m_fileEmpty)
        {
            cout<<"文件无记录"<<endl;
        }
        else
        {
            cout<<"请输入您想删除员工的编号"<<endl;
            int ID;
            cin>>ID;
            int index=isExist(ID);
            if(index!=-1)
            {
                for (int i=index;i<m_empNum-1;i++)
                {
                    m_wo[i]=m_wo[i+1];  //数据前移
                }
                m_empNum--;
                cout<<"删除成功"<<endl;
                save();
            }
            else
            {
                cout<<"删除失败，未找到该职工"<<endl;
            }      
        } 
        system ("pause");
        system ("cls");    
    }
    //修改职工
    void modemp()
    {
        if(m_fileEmpty)
        {
            cout<<"文件无记录"<<endl;
        }
        else
        {
            cout<<"请输入您想修改职工的编号"<<endl;
            int ID;
            cin>>ID;
            int index=isExist(ID);
            if(index!=-1)
            {
                delete m_wo[index];
                int newID;
                string newname;
                int newdeptID;
                cout<<"查找到ID为 "<<ID<<" 的员工。"<<endl;
                cout<<"请输入员工新编号"<<endl;
                cin>>newID;
                cout<<"请输入员工新姓名"<<endl;
                cin>>newname;
                cout << "请选择员工新岗位：" << endl;
			    cout << "1、普通职工" << endl;
			    cout << "2、经理" << endl;
			    cout << "3、老板" << endl;
                bool temp;
                worker* wo=NULL;
                while (true)
                {
                    cin>>newdeptID;
                    switch(newdeptID)
                    {
                        case 1:
                        wo=new employee(newID,newname,newdeptID);
                        temp=true;
                        break;
                        case 2:
                        wo=new manager(newID,newname,newdeptID);
                        temp=true;
                        break;
                        case 3:
                        wo=new boss(newID,newname,newdeptID);
                        temp=true;
                        break;
                        default:
                        cout<<"输入错误，请重新输入其岗位"<<endl;
                        temp=false;
                        break;
                    }
                    if(temp==true) break;
                }
                m_wo[index]=wo;
                cout<<"修改成功!"<<endl;
                save();
            }
            else
            {
                cout<<"修改失败，未找到该职工"<<endl;
            }       
        }
        system ("pause");
        system ("cls");
    }
    //查找职工
    void findemp()
    {
         if(m_fileEmpty)
        {
            cout<<"文件无记录"<<endl;
        }
        else
        {
            cout << "请输入查找的方式：" << endl;
            cout << "1、按职工编号查找" << endl;
            cout << "2、按姓名查找" << endl;
            int select = 0;
            cin >> select;
            if(select==1)
            {
                cout<<"请输入查找职工的ID:"<<endl;
                int ID;
                cin>>ID;
                int index=isExist(ID);
                if(index!=-1)
                {
                    cout<<"查找成功，职工信息如下："<<endl;
                    m_wo[index]->showInfo();
                }
                else
                {
                    cout<<"未找到该职工"<<endl;
                }    
            }
            else if(select==2)
            {
                cout<<"请输入查找职工的姓名："<<endl;
                string name;
                cin>>name;
                bool ret=false;
                for(int i=0;i<m_empNum;i++)
                {
                    if(m_wo[i]->m_name==name)
                    {
                        cout<<"查找成功，职工编号为："
                            <<m_wo[i]->m_ID<<" ,其具体信息如下"<<endl;
                        m_wo[i]->showInfo();
                        ret=true;
                    }
                }
                if(ret==false)
                {
                    cout<<"查找失败，查无此人。"<<endl;
                }
            }
            else
            {
                cout<<"输入有误"<<endl;
            }          
        }
        system ("pause");
        system ("cls");
    }
    //按ID排序
    void sortemp()
    {
        if(m_fileEmpty)
        {
            cout<<"文件无记录"<<endl;
        }
        else
        {
            cout << "请选择排序方式： " << endl;
            cout << "1、按职工号进行升序" << endl;
            cout << "2、按职工号进行降序" << endl;
            int select;
            cin >> select;
            if(select==1)
            {
                //选择排序
                for(int i=0;i<m_empNum;i++)
                {
                    int min=i;
                    for(int j=i+1;j<m_empNum;j++)
                    {
                        if(m_wo[i]->m_ID>m_wo[j]->m_ID)
                        {
                            min=j;
                        }
                    }
                    if(i!=min)
                    {
                        worker* wo=m_wo[i];
                        m_wo[i]=m_wo[min];
                        m_wo[min]=wo;
                    }
                }
                cout<<"排序成功,排序后的结果为："<<endl;
                save();
                showemp();
            }
            else if(select==2)
            {
                for(int i=0;i<m_empNum;i++)
                {
                    int max=i;
                    for(int j=i+1;j<m_empNum;j++)
                    {
                        if(m_wo[i]->m_ID<m_wo[j]->m_ID)
                        {
                            max=j;
                        }
                    }
                    if(i!=max)
                    {
                        worker* wo=m_wo[i];
                        m_wo[i]=m_wo[max];
                        m_wo[max]=wo;
                    }
                }
                cout<<"排序成功,排序后的结果为："<<endl;
                save();
                showemp();
            }
            else
            {
                cout<<"输入有误"<<endl;
                system ("pause");
                system ("cls");   
            }          
        }
    }
    //清空
    void cleanfile()
    {
        cout<< "确认清空？" << endl;
	    cout << "1、确认" << endl;
	    cout << "2、返回" << endl;
        int select = 0;
	    cin >> select;
        if(select==1)
        {
            ofstream ofs;
            ofs.open(FILENAME,ios::trunc);//ios::trunc如果文件存在，删除并重新创建
            ofs.close();
            if(m_wo!=NULL)
            {
                for(int i=0;i<m_empNum;i++)
                {
                    if(m_wo[i]!=NULL)
                    {
                        delete m_wo[i];//删除堆区每个职工对象
                        m_wo[i]=NULL;
                    }
                }
                delete[] m_wo;
                m_wo=NULL;
                m_empNum=0;
                m_fileEmpty=true;
                cout<<"清空成功！"<<endl;
            }
        }
        system ("pause");
        system ("cls");  
    }

    ~workerManager()
    {
        if(m_wo!=NULL)
        {
            for(int i=0;i<m_empNum;i++)
            {
                if(m_wo[i]!=NULL)
                {
                    delete m_wo[i];
                    m_wo[i]=NULL;
                }
            }
            delete[] m_wo;
            m_wo=NULL;
        }
    }
    //记录员工个数
    int m_empNum;
    //员工数组指针
    worker** m_wo;
    //标志文件是否为空
    bool m_fileEmpty;
};