#include <iostream>
#include <string>
#include <cmath>
#include "point.h"
#include "point.cpp"
#include "circle.hpp"
using namespace std;
int main()
{
    point p1;
    p1.setpx(2);
    p1.setpy(10);
    circle c1;
    point p2;
    p2.setpx(1);
    p2.setpy(2);
    c1.setcir(p2);
    c1.setcirr(4);
    c1.belong(p1);
    system ("pause");
    return 0;
}