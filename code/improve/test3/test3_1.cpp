/*string容器
*/
#include <iostream>
#include <string>
using namespace std;

void test1()//构造
{
    string s1;//默认构造
    const char* str="hello world";
    string s2(str);//含参构造
    cout<<s2<<endl;
    string s3(s2);//拷贝构造
    cout<<s3<<endl;
    string s4(5,'a');//'ab'的话只会识别b
    cout<<s4<<endl; 
}

void test2()//赋值  =  assign
{
    string s5;
    s5="hello world";
    string s6;
    s6=s5;
    string s7;
    s7='a';
    string s8;
    s8.assign("hello c++");
    string s9;
    s9.assign("hello c++",5);//把“hello c++”前5个字符赋值给s9
    string s10;
    s10.assign(s9);
    string s11;
    s11.assign(10,'a');
}

void test3()//拼接  +=  append
{ 
    string str1="I";
    str1+=" like playing";
    str1+='.';
    string str2=" :) ";
    str1+=str2;
    cout<<str1<<endl;
    string str3="What";
    str3.append(" about");
    str3.append(" you?    ewfveq ",5);//把字符串s的前n个字符连接到当前字符串结尾
    str3.append(str1);
    str3.append(str2,0,2);//字符串中从第0个开始的2个字符连接到字符串结尾
    cout<<str3<<endl;
}

void test4()//查找和替换  find   rfind   replace 
{
    string str1="I like you.";
    //查找find 和rfind 都返回位置（int）,没有返回-1
    //find 从左往右的第一个出现位置
    //rfind 从右往左查的第一个出现位置
    cout<<str1.find("ik",0)<<endl;//查找ik第一次出现位置,从第0个字符开始查找
    str1.replace(2,4,"don't like");///替换从第2个字符开始4个字符为字符串"  ..."
    cout<<str1<<endl;
}

void test5()//字符串比较（ASCII码）  =返回0  >返回1  <返回-1     主要用来比是否相等
{
    string str1="hello";
    string str2="world";
    cout<<str1.compare(str2)<<endl;//str1<str2(h<w)
}

void test6()//存取   operator[]   at
{
    string str1="hello world";
    for (int i=0;i<str1.size();i++)   //size()  返回字符串长度
    {
        cout<<str1[i]<<"  ";
        cout<<str1.at(i)<<"  ";
    }
    cout<<endl;
    str1[0]='x';
    str1.at(1)='v';
    cout<<str1<<endl;

}

void test7()//插入和删除  insert erase
{
    string str="hello world";
    str.insert(5," hello");//在第五个之前插入
    cout<<str<<endl;
    str.erase(5,6);//删除从第五个字符开始的6个字符
    cout<<str<<endl;
}

void test8()//子串   substr
{
    string str="hello world";
    string st=str.substr(6,5);//提取从第6个字符开始的5个字符
    cout<<st<<endl;
    string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    system ("pause");
    return 0;
}