#pragma once
#include<iostream>
#include <map>
#include <fstream>
#include "gloabalFile.hpp"
using namespace std;
class orderFile
{
    public:
	orderFile()
    {
        ifstream ifs;
        ifs.open(ORDER_FILE, ios::in);
        string date;      //日期
        string interval;  //时间段
        string stuID;     //学生编号
        string stuName;   //学生姓名
        string roomID;    //机房编号
        string status;    //预约状态
        m_Size = 0; //预约记录个数
        while (ifs >> date && ifs >> interval && ifs >> stuID && ifs >> stuName && ifs >> roomID &&  ifs >> status)
        {
            string key;
            string value;
            map<string, string> m;
            int pos = date.find(":");
            if (pos != -1)
            {
                key = date.substr(0, pos);
                value = date.substr(pos + 1, date.size() - pos -1);
                m.insert(make_pair(key, value));
            }
            pos = interval.find(":");
            if (pos != -1)
            {
                key = interval.substr(0, pos);
                value = interval.substr(pos + 1, interval.size() - pos -1 );
                m.insert(make_pair(key, value));
            }
            pos = stuID.find(":");
            if (pos != -1)
            {
                key = stuID.substr(0, pos);
                value = stuID.substr(pos + 1, stuID.size() - pos -1 );
                m.insert(make_pair(key, value));
            }
            pos = stuName.find(":");
            if (pos != -1)
            {
                key = stuName.substr(0, pos);
                value = stuName.substr(pos + 1, stuName.size() - pos -1);
                m.insert(make_pair(key, value));
            }
            pos = roomID.find(":");
            if (pos != -1)
            {
                key = roomID.substr(0, pos);
                value = roomID.substr(pos + 1, roomID.size() - pos -1 );
                m.insert(make_pair(key, value));
            }
            pos = status.find(":");
            if (pos != -1)
            {
                key = status.substr(0, pos);
                value = status.substr(pos + 1, status.size() - pos -1);
                m.insert(make_pair(key, value));
            }
            m_orderData.insert(make_pair(m_Size, m));
            m_Size++;
        }
        ifs.close();
    }
    //更新预约记录
    void updateOrder()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
        for (int i = 0; i < m_Size;i++)
        {
            ofs << "date:" << this->m_orderData[i]["date"] << " ";
            ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
            ofs << "stuId:" << this->m_orderData[i]["stuID"] << " ";
            ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
            ofs << "roomId:" << this->m_orderData[i]["roomID"] << " ";
            ofs << "status:" << this->m_orderData[i]["status"] << endl;
        }
        ofs.close();
    }
	//记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
	map<int, map<string, string>> m_orderData;
	//预约记录条数
	int m_Size;
};