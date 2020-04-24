/*stack   先进后出数据结构    只有顶端的元素才可以被外界使用      不允许有遍历行为
operator=   push pop top empty size
*/
#include <iostream>
#include <stack>
using namespace std;
void test1()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"The size of stack is "<<s.size()<<endl;
    while(!s.empty())
    {
        cout<<"The element in the top of stack is "<<s.top()<<endl;
        s.pop();//出栈
    }
    cout<<"The size of stack is "<<s.size()<<endl;
}

int main()
{
    test1();
    system ("pause");
    return 0;
}