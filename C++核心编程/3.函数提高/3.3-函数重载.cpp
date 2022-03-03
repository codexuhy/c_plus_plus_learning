#include <iostream>
using namespace std;
/*
    函数重载：
        作用：函数名可以相同，提高复用性
        函数重载满足条件：
            同一个作用域下
            函数名相同
            函数参数类型不同 或者 个数不同 或者 顺序不同
        注意： 函数的返回值不可以作为重载的条件

*/

void func()
{
    cout << "func 的调用" << endl;
}

void func(int a)
{
    cout << "func (int a) 的调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a,double b) 的调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b) 的调用" << endl;
}

// 函数的返回值不可以作为重载的条件
// int func(double a, int b)
// {
//     cout << "func(double a, int b) 的调用" << endl;
//     return a;
// }
int main()
{
    func();
    func(1);
    func(1, 2.0);
    func(1.0, 2);

    return 0;
}