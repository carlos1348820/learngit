/*内存分区模型：编程更灵活
代码区：存放函数体的二进制代码，由操作系统管理
       存放CPU执行的机器指令
       特点：共享，只读
全局区：存放全局变量,静态变量和常量(不包括局部常量)
       该区数据在程序结束后由操作系统释放
       局部变量：函数体中的变量（包括main函数）
       全局变量：函数体外变量
       静态变量：static+普通变量     e.g. static int a;
       常量：字符串常量（e.g. “。。。”），const修饰的变量（全局or局部）
栈区：由编译器自动分配释放，存放函数参数值，局部变量等
      注意：不要返回局部变量地址   e.g.return &a;  
堆区：由程序员分配和释放，若不释放则程序结束时系统自动回收
      new开辟新内存（返回地址）
      delete释放

*/

#include <iostream>
using namespace std;
 int* fuc(int b)
 {
       b=100;
       int a=10;
       return &a;  
 }

 int* func()
 {
       int* a=new int(10);//new int（10）返回的是存放10的地址
       //指针本质也是局部变量，放在栈区，但其保存的数据放在堆区
       return a;
 }

 void test()
 {
      int* p2=new int[10];  //十个整型元素的数组
      for (int i=0;i<10;i++)
      {
            p2[i]=i+100;//赋值100-109
      }
      for (int i=0;i<10;i++)
      {
            cout<<p2[i]<<endl;
      }
      delete[] p2;  //释放数组时要加【】
 }

 int main()
 {
       int* p=fuc(10);
       // cout<<*p<<endl;  //数据不再保留,会报错,原因就是fuc函数返回来局部变量地址
       int* p1=func();
       cout<<*p1<<endl;     //堆区数据由程序员开辟释放
       delete p1;           //内存释放
       cout<<*p1<<endl;     //输出乱码
       test();

       system ("pause");
       return 0;
 }