#include <iostream>
#include <fstream>
#include <string>
#include "identity.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "manager.hpp"
#include "gloabalFile.hpp"
using namespace std;

void managerMenu(identity* &m )
{
	while(true)
	{
		(*m).operMenu();
		manager* man = (manager*)m;
		int select = 0;
		cin >> select;
		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson(); 
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete m;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(identity* &s )
{
	while(true)
	{
		(*s).operMenu();
		student* stu = (student*)s;
		int select = 0;
		cin >> select;
		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete s;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(identity * &t)
{
	while (true)
	{
		//教师菜单
		t->operMenu();
		teacher* tea = (teacher*)t;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete t;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void loginIn(string filename,int type)
{
	identity *identity=NULL;
	ifstream ifs;
	ifs.open(filename,ios::in);
	//文件不存在情况
	if(!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		ifs.close();
		return;
	}
	int ID=0;
	string name;
	string psw;
	if(type==1)//学生登录
	{
		cout<<"请输入您的学号："<<endl;
		cin>>ID;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号：" << endl;
		cin >>ID;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> psw;
	if (type == 1)
	{
		//学生登录验证
		int fID;
		string fname;
		string fpsw;
		while(ifs>>fID&&ifs>>fname&&ifs>>fpsw)
		{
			if(ID==fID && name == fname && psw==fpsw)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity = new student(ID, name, psw);
				studentMenu(identity);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fID;
		string fname;
		string fpsw;
		while(ifs>>fID&&ifs>>fname&&ifs>>fpsw)
		{
			if(ID==fID && name == fname && psw==fpsw)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity = new teacher(ID, name, psw);
				teacherMenu(identity);
				return;
			}
		}
	}
	else if(type == 3)
	{
		//管理员登录验证
		string fname;
		string fpsw;
		while (ifs >> fname && ifs >> fpsw)
		{
			if (name == fname && psw == fpsw)
			{
				cout << "验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity = new manager(name,psw);
				managerMenu(identity);
				return;
			}
		}
	}	
	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
    int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select; //接受用户选择
		switch (select)
		{
		case 1:  //学生身份
			loginIn(STUDENT_FILE,1);
			break;
		case 2:  //老师身份
			loginIn(TEACHER_FILE,2);
			break;
		case 3:  //管理员身份
			loginIn(ADMIN_FILE,3);
			break;
		case 0:  //退出系统
            cout << "欢迎下一次使用"<<endl;
            system("pause");
            return 0;
		default:
             cout << "输入有误，请重新选择！" << endl;
		    system("pause");
			system("cls");
			break;
		}
	}
    system("pause");
    return 0;
}                           