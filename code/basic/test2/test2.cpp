#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*程序流控制
    顺序结构 选择结构（if,三目运算符,switch） 循环结构（while(){},     do{}while(),     for(起始表达式；条件表达式；末尾循环体){} ）
                                                   判断后循环   先循环后判断
    跳转语句  break（出现在swith选择语句,循环语句 if。。。break ,循环嵌套语句,只能跳出一"个"循环）
              continue(循环语句中跳出未循环的代码，执行下一"次"循环，if。。。continue)
              goto(无条件跳转循环 goto 标记)  e.g. FLAG:      goto FLAG;
    */
   int a=5;
   int b=10;
   int c;
   cout<<"please imput a "<<endl;
   cin>>a;
   if (a>5)  //不要加分号
   {
       cout<<"you win!"<<endl;
   }
   else if (a<5)
   {
       cout<<"you lose!"<<endl;
   }
   else
   {
       cout<<"so so!"<<endl;
   }
   c=a>b?a:b; //三目运算符结构：a?b:c a为真，返回b；a为假，返回c  返回值为变量
   (a>b?a:b)=100; //返回a=5,b=100
   cout<<"please input c."<<endl;
   cin>>c;
   switch(c)  //只能判断整型或者字符，不可以判断区间，但结构清晰，执行效率高
   {
       case 10:
       cout<<"you are well!"<<endl;
       break; //退出这个分支
       case 7:
       cout<<"you are good"<<endl;
       break;
       default:
       cout<<"you are bad"<<endl;
       break;
   }
   int num=0;
   while(num<=9) //避免死循环
   {
       cout<<num<<endl;
       num++;
   }
   int nuu=0;
   do
   {
       cout<<nuu<<endl;
       nuu++;
   } while (nuu<10); //输出0-9
   for(int i=0;i<10;i++) //i++可以写道循环体中,分号中都可以不写
   {
       cout<<i<<endl;
   }
   for (int i=0;i<10;i++)
   {
       for (int j=0;j<10;j++)
       {
           cout<<"* ";
       }
       cout<<endl;
   }

    system("pause");
    return 0;
}