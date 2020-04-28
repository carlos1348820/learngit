#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "identity.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "computerRoom.hpp"
#include "gloabalFile.hpp"
using namespace std;
void printStudent(student & s)
{
	cout << "学号： " << s.m_ID << " 姓名： " << s.m_name << " 密码：" << s.m_psw<< endl;
}
void printTeacher(teacher & t)
{
	cout << "职工号： " << t.m_empID << " 姓名： " << t.m_name << " 密码：" << t.m_psw<< endl;
}
class manager:public identity
{
    public:
    manager() {};
    manager(string name,string psw)
    {
        m_name=name;
        m_psw=psw;
        initVector();
        ifstream ifs;
        ifs.open(COMPUTER_FILE, ios::in);
        computerRoom c;
        while (ifs >> c.m_comID && ifs >> c.m_maxNum)
        {
            vCom.push_back(c);
        }
        cout << "当前机房数量为： " << vCom.size() << endl;
        ifs.close();
    }
    //选择菜单
	void operMenu()
    {
        cout << "欢迎管理员："<<this->m_name << "登录！" << endl;
        cout << "\t\t ---------------------------------\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          1.添加账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          2.查看账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          3.查看机房            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          4.清空预约            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          0.注销登录            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t ---------------------------------\n";
        cout << "请选择您的操作： " << endl;
    }
	//添加账号  
	void addPerson()
    {
        cout << "请输入添加账号的类型" << endl;
        cout << "1、添加学生" << endl;
        cout << "2、添加老师" << endl;
        string fileName;
        string tip;
        string errorTip; //重复错误提示
        int select = 0;
        cin >> select;
        ofstream ofs;
        if (select == 1)
        {
            fileName = STUDENT_FILE;
            tip = "请输入学号： ";
            errorTip = "学号重复，请重新输入";
        }
        else
        {
            fileName = TEACHER_FILE;
            tip = "请输入职工编号：";
            errorTip = "职工号重复，请重新输入";
        }
        ofs.open(fileName, ios::out | ios::app);
        int ID;
        string name;
        string psw;
        cout <<tip << endl;
        while (true)
        {
            cin >> ID;
            bool ret = checkRepeat(ID, select);
            if (ret) //有重复
            {
                cout << errorTip << endl;
            }
            else
            {
                break;
            }
        }
        cout << "请输入姓名： " << endl;
        cin >> name;
        cout << "请输入密码： " << endl;
        cin >> psw;
        ofs << ID << " " << name << " " << psw << " " << endl;
        initVector();
        cout << "添加成功" << endl;
        system("pause");
        system("cls");
        ofs.close(); 
    }
	//查看账号
	void showPerson()
    {
        cout << "请选择查看内容：" << endl;
        cout << "1、查看所有学生" << endl;
        cout << "2、查看所有老师" << endl;
        int select = 0;
        cin >> select;   
        if (select == 1)
        {
            cout << "所有学生信息如下： " << endl;
            for_each(vStu.begin(), vStu.end(), printStudent);
        }
        else
        {
            cout << "所有老师信息如下： " << endl;
            for_each(vTea.begin(), vTea.end(), printTeacher);
        }
        system("pause");
        system("cls");
    }
	//查看机房信息
	void showComputer()
    {
        cout << "机房信息如下： " << endl;
        for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
        {
            cout << "机房编号： " << it->m_comID << " 机房最大容量： " << it->m_maxNum << endl;
        }
        system("pause");
        system("cls");     
    }
	//清空预约记录
	void cleanFile()
    {
        ofstream ofs(ORDER_FILE, ios::trunc);
        ofs.close();
        cout << "清空成功！" << endl;
        system("pause");
        system("cls");
    }
    //初始化容器
    void initVector()
    {
        ifstream ifs;
        ifs.open(STUDENT_FILE, ios::in);
        if (!ifs.is_open())
        {
            cout << "文件读取失败" << endl;
            return;
        }  
        vStu.clear();
        vTea.clear();    
        student s;
        while (ifs >> s.m_ID && ifs >> s.m_name &&  ifs >> s.m_psw)
        {
            vStu.push_back(s);
        }
        cout << "当前学生数量为： " << vStu.size() << endl;
        ifs.close(); //学生初始化
        //读取老师文件信息
        ifs.open(TEACHER_FILE, ios::in);
        teacher t;
        while (ifs >> t.m_empID && ifs >> t.m_name &&  ifs >> t.m_psw)
        {
            vTea.push_back(t);
        }
        cout << "当前教师数量为： " << vTea.size() << endl;
        ifs.close();
    }
    //检测重复
    bool checkRepeat(int ID, int type)
    {
        if (type == 1)
        {
            for (vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++)
            {
                if (ID == it->m_ID)
                {
                    return true;
                }
            }
        }
        else
        {
            for (vector<teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
            {
                if (ID == it->m_empID)
                {
                    return true;
                }
            }
        }
        return false;
    }

    vector<student> vStu;
	vector<teacher> vTea;
    vector<computerRoom> vCom;
};