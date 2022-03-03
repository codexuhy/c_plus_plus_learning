#include <iostream>
using namespace std;

// 函数重载注意事项
// 1.引用作为重载的条件
void func(int &a) // int &a = 10; 不合法
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a) // const int &a = 10; 编译器优化了代码，相当于 int temp = 10； int &a = temp;
{
    cout << "func(const int &a)调用" << endl;
}

// 2.函数重载碰到默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a)调用" << endl;
}

void func2(int a)
{
    cout << "func2(int a)调用" << endl;
}

int main()
{
    int a = 10;
    func(a); // 调用func(int &a)

    func(10); // 调用func(const int &a)

    func2(10, 20);
    // func2(10); // 当函数重载碰到默认参数，函数调用存在二义性，会报错，尽量必现这种情况
    return 0;
}