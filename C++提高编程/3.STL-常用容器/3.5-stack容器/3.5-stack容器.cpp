#include <iostream>
using namespace std;
#include <stack>

/*
    构造函数：
    - stack<T> stk;            // stack采用模板类实现，stack对象的默认构造形式
    - stack(const stack &stk); //拷贝构造函数

    赋值操作：
    - stack &operator=(const stack &stk); //重载等号操作符

    数据存取：
    - push(elem); //从栈顶添加元素
    - pop();      //从栈顶移除第一个元素
    - top();      //返回栈顶元素

    大小操作：
    - empty(); //判断堆栈是否为空
    - size();  //返回栈的大小
*/

void printStack(stack<int>&s)
{
    if(!s.empty())
    {
        cout << "stack不为空" << endl;
    }
    else
    {
        cout << "stack为空" << endl;
    }
    cout << "stack容量：" << s.size() << endl;
}

// 栈 stack 容器
void test01()
{
    //特点：符合先进后出数据结构
    stack<int>s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //只要栈顶元素不为空，查看栈顶，并且执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout << "栈顶元素为：" << s.top() << endl;

        //出栈
        s.pop();
    }    
    printStack(s);
}

int main()
{
    test01();
    
    return 0;
}