#include <iostream>
using namespace std;

// 栈区数据注意事项  --- 不要返回局部变量的地址
// 栈区的数据由编译器开辟和释放，存放函数的参数值，局部变量等
int *func()
{

    int a = 10; // 局部变量 存放在栈区，栈区的数据在函数执行完自动释放
    return &a;  // 返回局部变量的地址
}

int main()
{

    // 接收func函数的返回值
    // int *p = func();

    // cout << *p << endl; //第一次打印正确的数字，是因为编译器做了保留

    return 0;
}