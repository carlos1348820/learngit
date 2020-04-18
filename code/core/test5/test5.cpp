/*文件操作：  包含头文件<fstream>
文件类型：1.文本文件   文件以文本的ASCII码形式存储在计算机中。
          2.二进制文件  文件以文本的二进制形式存储在计算机中。
操作文件的三大类:1.ofstream：写操作
                2. ifstream：读操作
                3. fstream：读写操作
| 打开方式     | 解释                      |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建  |
| ios::binary | 二进制方式                 |
e.g.   ios::binary | ios:: out
二进制写文件：ostream& write(const char * buffer,int len);
      读文件：istream& read(char *buffer,int len);
*/
#include <iostream>
#include <fstream>//包含头文件
#include <string>
using namespace std;
class person
{
    public:
    char m_name[64];
    int m_age;
};
//写文件
void test1()
{
    //创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("test1.txt",ios::out);
    //写内容
    ofs<<"name:bitch"<<endl;
    ofs<<"age:male"<<endl;
    ofs<<"age:18"<<endl;
    //关闭文件
    ofs.close();
}
//读文件
void test2()
{
    //创建流对象
    ifstream ifs;
    //打开文件并判断是否打开成功
    ifs.open("test1.txt",ios::in);
    if (!ifs.is_open())
    {
        cout<<"failed open file."<<endl;
        return;
    }
    //读数据
        //第一种
        char buf[1024]={0};
        while(ifs>>buf)
        {
            cout<<buf<<endl;
        }
        //第二种
        // char buf[1024]={0};
        // while(ifs.getline(buf,sizeof(buf)))
        // {
        //     cout<<buf<<endl;
        // }
        //第三种
        // string buf;
        // while (getline(ifs,buf))
        // {
        //     cout<<buf<<endl;
        // }
        //第四种(不推荐)
        // char c;
        // while((c=ifs.get()) != EOF)  //EOF=end of file
        // {
        //     cout<<c;
        // }   
    //关闭文件
    ifs.close();
}
//写二进制文件
void test3()
{
    //创建流对象并指定打开方式
    ofstream ofs("person.md",ios::out | ios::binary);
    //也可以用ofs.open(....);
    //写文件
    person p={"张三",18};
    ofs.write((const char*)&p,sizeof(person));
    //关闭文件
    ofs.close();
}
//读二进制文件
void test4()
{
    //创建流对象并指定打开方式,判断文件是否打开成功
    ifstream ifs("person.md",ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout<<"failed open file"<<endl;
    }
    //读文件
    person p1;
    ifs.read((char*)&p1,sizeof(person));
    cout<<"name:"<<p1.m_name<<endl;
    cout<<"age:"<<p1.m_age<<endl;
    //关闭文件
    ifs.close();
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    system ("pause");
    return 0;
}