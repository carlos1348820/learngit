#include <iostream>
#include <string>
#include <fstream>
#include "workerManager.hpp"
using namespace std;


int main()
{
    workerManager wm;
    int choice=0;
    while (true)
    {
        wm.showMenu(); 
        cout<<"请输入您的选择"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0://退出系统
            wm.quitsystem();
            break;
        case 1://增加职工
            wm.addemp();
            break;
        case 2://显示职工
            wm.showemp();
            break;
        case 3://删除职工
            wm.delemp();
            break;
        case 4://修改职工
            wm.modemp();
            break;
        case 5://查找职工
            wm.findemp();
            break;
        case 6://排序职工
            wm.sortemp();
            break;
        case 7://全部清空
            wm.cleanfile();
            break;
        default:
            cout<<"输入错误，请重新输入"<<endl;
            system ("pause");
            system("cls");
            break;
        }
    }
    system ("pause");
    return 0;
}