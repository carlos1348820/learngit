#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <map>
#include "speaker.hpp"
using namespace std;


class myPrint1
{
    public:
    void operator()(const speaker s)
    {
        cout<<"选手编号： "<<s.m_ID
        <<"  选手姓名： "<<s.m_name
        <<"  选手分数： "<<s.m_score<<endl;
    }
};
class myPrint2
{
    public:
    void operator()(const speaker s)
    {
        cout<<s.m_ID<<"  ";
    }
};
class myCompare
{
    public:
    bool operator()(speaker p1,speaker p2)
    {
        return p1.m_score>p2.m_score;
    }
};
//设计演讲管理类
class speechManager
{
    public:
    speechManager() 
    {
        initSpeech();
    }

    //菜单
    void showMenu()
    {
        cout << "********************************************" << endl;
        cout << "*************  欢迎参加演讲比赛 ************" << endl;
        cout << "*************  1.开始演讲比赛  *************" << endl;
        cout << "*************  2.查看往届记录  *************" << endl;
        cout << "*************  3.清空比赛记录  *************" << endl;
        cout << "*************  0.退出比赛程序  *************" << endl;
        cout << "********************************************" << endl;
        cout << endl;
    }

    //退出系统
    void existSystem()
    {
        cout<<"欢迎下次继续使用"<<endl;
        system ("pause");
        exit(0);
    }

    //初始化容器
    void initSpeech()
    {
        v.clear();
        m_index=1;
    }

    //创建选手
    void createSpeaker()
    {
        string nameSeed="ABCDEFGHIJKL";
        for(int i=0;i<12;i++)
        {
            speaker p;
            p.m_name="player";
            p.m_name+=nameSeed[i];
            p.m_score=0;
            p.m_ID=1000+i;
            v.push_back(p);
        }
    }

    //抽签
    void speechDraw()
    {
        cout << "第 << " << m_index << " >> 轮比赛选手正在抽签"<<endl;
        cout << "---------------------" << endl;
        cout << "抽签后演讲顺序如下：" << endl;
        if(m_index==1)
        {
            random_shuffle(v.begin(),v.end());
            for_each(v.begin(),v.end(),myPrint2());
            cout<<endl;
        }
        else
        {
            random_shuffle(v.begin(),v.end());
            for_each(v.begin(),v.end(),myPrint2());
            cout<<endl;          
        }
        cout << "---------------------" << endl;
        system("pause");
        cout << endl;
    }

    //比赛
    void speechContest()
    {
        //打分
        cout << "------------- 第"<<m_index << "轮正式比赛开始：------------- " << endl;
        deque<double> d;
        for(vector<speaker>::iterator it=v.begin();it!=v.end();it++)
        {
            for(int i=0;i<10;i++)
            {
                double score=(rand()%401+600)/10.f;
                d.push_back(score);
            }
            sort(d.begin(),d.end());
            d.pop_back();
            d.pop_front();
            (*it).m_score=accumulate(d.begin(),d.end(),0.0f)/(double)d.size();
            d.clear();
        }  
        if(m_index==1)
        {
            //第一轮结果
            vector<speaker> v1;
            v1.resize(6);
            vector<speaker> v2;
            v2.resize(6);
            copy(v.begin(),v.end()-6,v1.begin());
            copy(v.begin()+6,v.end(),v2.begin());
            v.resize(6);
            sort(v1.begin(),v1.end(),myCompare());
            cout << "第1小组比赛名次：" << endl;
            for_each(v1.begin(),v1.end(),myPrint1());
            sort(v2.begin(),v2.end(),myCompare());
            cout << "第2小组比赛名次：" << endl;
            for_each(v2.begin(),v2.end(),myPrint1());
            copy(v1.begin(),v1.begin()+3,v.begin());
            copy(v2.begin(),v2.begin()+3,v.begin()+3);
            cout << "------------- 第1轮比赛完毕  ------------- " << endl;
            system("pause");
            cout << "---------第1轮晋级选手信息如下：-----------" << endl;
            for_each(v.begin(),v.end(),myPrint1());
            m_index++;
            system("pause");
        }
        else
        {
            cout << "第二轮比赛名次：" << endl;
            //第二轮比赛结果
            sort(v.begin(),v.end(),myCompare());
            for_each(v.begin(),v.end(),myPrint1());
            cout << "---------第2轮前三名选手信息如下：-----------" << endl;
            for_each(v.begin(),v.end()-3,myPrint1());
            m_index=1;
            system("pause");
        }     
    }

    //记录信息
    void saveRecord()
    {
        ofstream ofs;
        ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件
        //将每个人数据写入到文件中
        for (vector<speaker>::iterator it = v.begin(); it != v.end()-3; it++)
        {
            ofs<<(*it).m_name<<","<<(*it).m_score<<",";
        }
        ofs << endl;
        //关闭文件
        ofs.close();      
        cout << "记录已经保存" << endl;
        system("pause");
        system("cls");
    }

    //开始比赛
    void startMarch()
    {
        createSpeaker();
        speechDraw();
        speechContest();
        speechDraw();
        speechContest();
        saveRecord();
        v.clear();
    }

    //读取往届信息
    void loadRecord()
    {

        ifstream ifs("speech.csv",ios::in);
        if (!ifs.is_open())
        {
            this->fileIsEmpty = true;
            cout << "文件不存在！" << endl;
            ifs.close();
            return;
        }
        char ch;
        ifs >> ch;
        if (ifs.eof())
        {
            cout << "文件为空!" << endl;
            this->fileIsEmpty = true;
            ifs.close();
            return;
        }
        this->fileIsEmpty = false;
        ifs.putback(ch); //读取的单个字符放回去
        string data;
        int index = 0;
        vector<string> v3;
        while (ifs >> data)
        {
            //cout << data << endl;
            int pos = -1;
            int start = 0;
            while (true)
            {
                pos = data.find(",", start); //从0开始查找 ','
                if (pos == -1)
                {
                    break; //找不到break返回
                }
                string  temp= data.substr(start, pos - start); 
                v3.push_back(temp);
                start = pos + 1;
            }
            index++;
        }
        ifs.close();
        vector<string>::iterator it=v3.begin();
        for (int i = 0; i <v3.size()/6; i++)
        {
            cout << "第" << i + 1 << "届 " <<
                "冠军姓名：" << (*it) << " 得分：" << (*(it+1))<< " "
                "亚军姓名：" << (*(it+2))<< " 得分：" << (*(it+3))<< " "
                "季军姓名：" <<(*(it+4)) << " 得分：" << (*(it+5)) << endl;
                it+=6;
        }
        system("pause");
        system("cls");
	}

    void clearRecord()
    {
        cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		initSpeech();
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
    }

    //展示选手
    void showSpeaker()
    {
        for_each(v.begin(),v.end(),myPrint1());
    }

    ~speechManager()
    {

    }
    vector<speaker> v;
    int m_index;  //比赛轮数
    bool fileIsEmpty;
};
