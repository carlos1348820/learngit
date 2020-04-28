#include <iostream>
#include <string>
#include <ctime>
#include "speechManager.hpp"
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    speechManager sp;
    while(true)
    {
        sp.showMenu();
        int ret;
        cout<<"请输入您的选项（数字）.";
        cin>>ret;
        switch(ret)
        {
            case 1:  //开始比赛
            sp.startMarch();
            break;
            case 2:  //查看记录
            sp.loadRecord();
            break;
            case 3:  //清空记录
            sp.clearRecord();
            break;
            case 0:  //退出系统
            sp.existSystem();
            break;
            default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}