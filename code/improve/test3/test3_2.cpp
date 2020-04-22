/*vector容器(单端数组)
*/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void test1()//构造
{
    vector<int> v1;//无参构造
    for(int i=0;i<10;i++)
    {
        v1.push_back(i+1);
    }
    printVector(v1);
    vector<int> v2(v1.begin(),v1.end());// //将v1[begin(), end())区间中的元素拷贝给v2
    printVector(v2);
    vector<int> v3(10,100); //构造函数将10个100拷贝给本身。
    printVector(v3);
    vector<int> v4(v3);
    printVector(v4);
}

void test2()//赋值   operator=  assign
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2=v1;
    printVector(v2);
    vector<int> v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);
    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
}

void test3()//容量和大小   empty capacity size resize
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    if(v1.empty())  //true v1为空  false v1不为空
    {
        cout<<"v1为空"<<endl;
    }
    else
    {
        cout<<"v1不为空"<<endl;
        cout<<"v1的容量"<<v1.capacity()<<endl;
        cout<<"v1的大小"<<v1.size()<<endl;
    }
    v1.resize(15,100);//重新指定容器的长度,若容器变长，则以100填充新位置(默认为0)。如果容器变短，则末尾超出容器长度的元素被删除
    printVector(v1);   
}

void test4()//插入和删除    push_back pop_back insert erase clear
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    v1.pop_back();//尾删
    printVector(v1);
    v1.insert(v1.begin(),2,100);//第一个参数是迭代器(最前面插2个100)
    printVector(v1);
    v1.erase(v1.begin());//最前面删除一个数
    printVector(v1);
    v1.erase(v1.begin(),v1.end());//清空
    v1.clear();//清空
}

void test5()//数据存取   at operator[]  front back
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    for (int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<"  ";
        cout<<v1.at(i)<<"  ";
    }
    cout<<endl;
    cout<<"v1第一个元素为 "<<v1.front()<<endl;
    cout<<"v1最后一个元素为 "<<v1.back()<<endl;
}

void test6()//容器互换   swap
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i=0;i<10;i++)
    {
        v2.push_back(10-i);
    }
    printVector(v2);
    v1.swap(v2);//容器互换
    printVector(v2);
    //swap作用：收缩内存
    vector<int> v;
	for (int i = 0; i < 100000; i++) 
    {
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
	//收缩内存
	vector<int>(v).swap(v); //匿名对象（行执行完即回收）:vector<int>(v);其初始化的容量和大小按v的大小来
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

void test7()  //预留空间  reserve
{
    vector<int> v;
    v.reserve(100000);
    int num=0;
    int* p=NULL;
    for (int i = 0; i < 100000; i++) 
    {
		v.push_back(i);
        if (p != &v[0]) 
        {
			p = &v[0];
			num++;
		}
	}
    cout<<"num:"<<num<<endl;
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
    system ("pause");
    return 0;
}