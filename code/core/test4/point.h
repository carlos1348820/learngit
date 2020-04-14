#pragma once
#include <iostream>
using namespace std;
class point  //点类
{
    private:
    double px;
    double py;
    public:
    void setpx(double x);
    double getpx();
    void setpy(double y);
    double getpy();
};