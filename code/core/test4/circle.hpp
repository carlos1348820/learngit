#pragma once
#include <iostream>
#include "point.h"
#include <cmath>
using namespace std;
class circle  //圆类
{
    private:
    point cir;  //类中可以以另一个类作为本类中的成员
    double cirr;
    public:
    void setcir(point p)
    {
        cir=p;
    }
    point getcir()
    {
        return cir;
    }
    void setcirr(double r)
    {
        cirr=r;
    }
    double getcirr()
    {
        return cirr;
    }
    void belong(point &p)
    {
        if(pow(p.getpx()-cir.getpx(),2)+pow(p.getpy()-cir.getpy(),2)<pow(cirr,2))
        {
            cout<<"点在圆内"<<endl;
        }
        else if(pow(p.getpx()-cir.getpx(),2)+pow(p.getpy()-cir.getpy(),2)==pow(cirr,2))
        {
            cout<<"点在圆上"<<endl;
        }
        else
        {
            cout<<"点在圆外"<<endl;
        }
        
    }
};