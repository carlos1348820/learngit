#include <iostream>
#include <string>   //用string创建字符串需要加这个头文件
using namespace std;
int main()
#define  pi 3.14  //define 宏常量,文件上方
{
    const int a=10;  //const 修饰的变量，文件里
    /*sizeof可以数据占用内存大小 e.g.  sizeof(char)  sizeof(pi);   
    整型 short（2字节）<int（四字节）<long（4/8字节）<=long long（8字节）    
    浮点型 float(单精度 4字节)<double(双精度，8字节)      默认情况下输出小数显示6位有效数字
    字符型 char(1字节)
    转义字符：\n 换行 \\ 反斜杠  \t  水平制表符
    字符串型 char string
    布尔类型 true false (1字节)
    */
    char cc='a';   //单引号中只能有一个字符  对应ASCll编码  e.g. (int)cc  (aASC码值为97  A为65) 
    char str[] = "hello"; //[]和双引号
    string str1="world";  //需要头文件
    cout<<str<<" "<<str1<<endl;
    bool flag=false;
    cout<<flag<<endl; //输出为0,1,赋值时也为0,1(非0都为真)
    float c=3e2;  //e-2
    float d=3.14f; //f表示float类型
    double b=a+pi;
    cin>>b;
    cout<<"b="<<b<<endl;
    cout<<"pi="<<pi<<endl;
    cout<<"\\"<<endl;
    cout<<"aaa\thello"<<endl;   //aaa\t 一共显示八个格位，可以整齐输出数据
    printf("Hello World\n");
    system("pause");
    /*运算符
    算数运算符 + - * /(int/int还是 int)   %(取模 e.g. 10%3  )  ++(递增   e.g. a=2;b=a++*3 输出a=3,b=6   b=++a*3 输出a=3,b=9 ) --(递减)  
    赋值运算符 = +=（a=2,a+=3 输出a=5） -= *= /= %=
    比较运算符 == !=(不等于) < > <= >= (返回值都是0,1)
    逻辑运算符 !(非)  &&(与) ||(或)    注：c++中非0都是真，所以!10为假
     */
    int i=10;
    int j=20;
    ++i;  //输出11 前置递增：先让变量+1,后表达式运算
    i++;  //输出11 后置递增：先表达式运算，后让变量+1
    cout<<(i==j)<<endl;  //注意括弧（优先级）
    return 0;
}