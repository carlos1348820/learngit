#include <iostream>
#include <string>
using namespace std;
struct hero 
{
    string name;
    int age;
    string sex;
};

//年龄升序
void bubble(struct hero he[],int len)
{
    for (int i=len;i>1;i--)
    {
        for (int j=0;j<i-1;j++)
        {
            if(he[j].age<he[j+1].age)
            {
            //     int a=he[j].age;
            //     he[j].age=he[j+1].age;
            //     he[j+1].age=a;
            //     string b=he[j].name;
            //     he[j].name=he[j+1].name;
            //     he[j+1].name=b;
            //     string c=he[j].sex;
            //     he[j].sex=he[j+1].sex;
            //     he[j+1].sex=c;
            struct hero her=he[j];   //更简便
            he[j]=he[j+1];
            he[j+1]=her;
            }
        }
    }
    for (int i=0;i<len;i++)
    {
        cout<<"name:"<<he[i].name<<"  age:"<<he[i].age<<"  sex:"<<he[i].sex<<endl;
    }
}

int main()
{
    struct hero he[5]={{"a",23,"man"},
                       {"b",22,"man"},
                       {"c",20,"man"},
                       {"d",21,"man"},
                       {"e",19,"woman"}};
    int len=sizeof(he)/sizeof(he[0]);
    // for (int i=0;i<len;i++)
    // {
    //     cout<<"name:"<<he[i].name<<"  age:"<<he[i].age<<"  sex:"<<he[i].sex<<endl;
    // }
    bubble(he,len);
    system ("pause");
    return 0;
}