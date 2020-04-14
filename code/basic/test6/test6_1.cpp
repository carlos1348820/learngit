#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct student
{
    string name;
    int score;
};
struct teacher
{
    string name;
    struct student stu[5];
};

void allocatespace(struct teacher tea[],int len)
{
    string nameseed="ABCDE";
    for (int i=0;i<len;i++)
    {
        tea[i].name="Teacher_";
        tea[i].name+=nameseed[i];  //追加nameseed中第i个字母
        for (int j=0;j<5;j++)
        {
            tea[i].stu[j].name="Student";
            tea[i].stu[j].name+=nameseed[j];
            tea[i].stu[j].score=rand()%61+40;  //40-100分
        }
    }
}

void printall(teacher tea[],int len)
{
    for (int i=0;i<len;i++)
    {
        cout<<"teacher's name:"<<tea[i].name<<endl;
        for (int j=0;j<5;j++)
        {
            cout<<"\tstudent's name:"<<tea[i].stu[j].name;
            cout<<"    student's score:"<<tea[i].stu[j].score<<endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));  //时间随机数种子
    struct teacher tea[3];
    int len=sizeof(tea)/sizeof(tea[0]);
    allocatespace(tea,len);   //主要结构体可以直接传数组
    printall(tea,len);

    system ("pause");
    return 0;
}