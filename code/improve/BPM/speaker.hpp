#pragma once
#include <iostream>
#include <string>
using namespace std;
class speaker
{
    public:
    void operator=(const speaker &p)
    {
        this->m_name=p.m_name;
        this->m_ID=p.m_ID;
        this->m_score=p.m_score;
    }
    string m_name;
    int m_ID;
    double m_score;
};