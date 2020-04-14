#include <iostream>
#include <string>
using namespace std;

/*结构体：创建自定义数据类型  struct (3种创建具体类型方法)
  结构体数组
  结构体指针   ->访问结构体属性
  结构体嵌套
  结构体做函数参数
  const修饰   防止误操作
*/
struct student
{//成员列表
    string name;
    int age;
    int score;
};

struct teacher
{
    int id;
    string name;
    int age;
    struct student stu;
};

//打印学生信息函数，值传递
void printstu1(student s)
{
    s.name="bitch";
    cout<<"name of student:"<<s.name<<endl;
}
  
//地址传递，内存占用较少（4字节）,且不会赋值新的副本出来
void printstu2(const student* s)   //这样表达式修改会报错（只读）
{
    //s->name="bitch";
    cout<<"name of student:"<<s->name<<endl;   //箭头哦
}




int main()
{
    struct student s1;  //可以不写struct(但定义时不能省略)
    s1.name="bitch1";//加.
    s1.age=22;
    s1.score=100; 
    cout<<"name: "<<s1.name<<"\t"<<"age: "<<s1.age<<"\t\t"<<"score: "<<s1.score<<endl;
    struct student s2={"bitch2",23,120};
    cout<<"name: "<<s2.name<<"\t"<<"age: "<<s2.age<<"\t\t"<<"score: "<<s2.score<<endl;
    //定义结构体时顺便创建结构体变量,见上
    // s3.name="bitch3";//加.
    // s3.age=17;
    // s3.score=10;
    // cout<<"name: "<<s3.name<<"\t"<<"age: "<<s3.age<<"\t\t"<<"score: "<<s3.score<<endl;


    struct student stu[3]=  //结构体数组
    {
        {"bitch1",18,100},{"bitch2",22,120},{"bitch3",13,90}
    };
    stu[1].name="bitch4";
    for (int i=0;i<3;i++)
    {
        cout<<"name:"<<stu[i].name
            <<"  age:"<<stu[i].age
            <<"  score:"<<stu[i].score<<endl;
    }


    struct student* p=&s1;
    cout<<"name:"<<p->name   //->访问结构体属性
        <<"  age:"<<p->age
        <<"  score:"<<p->score<<endl;

    
    teacher t={1000,"Bitch1",24,{"bitch1",14,46}};
    // t.id=1000;
    // t.age=24;
    // t.name="Bit1";
    // t.stu.name="bitch1";
    // t.stu.age=14;
    // t.stu.score=46;
    cout<<t.stu.name<<endl;

    printstu1(s1);
    cout<<"name of student:"<<s1.name<<endl;
    printstu2(&s2);
    cout<<"name of student:"<<s2.name<<endl;
    

    system ("pause");
    return 0;
}