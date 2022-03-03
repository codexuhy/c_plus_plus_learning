#include <iostream>
using namespace std;

/*
    函数默认参数
        在C++中，函数的形参列表是可以有默认值得。
        语法：返回值类型  函数名 (参数 = 默认值) {}

        注意事项：
        1.如果某个位置参数有默认值，那么从这个位置往后，从左到右，必须都要有默认值
        2.如果函数声明有默认值，函数实现的时候就不能有默认参数
*/

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 注意事项：
// 1.如果某个位置参数有默认值，那么从这个位置往后，从左到右，必须都要有默认值
int func2(int a, int b, int c = 20)
{
    return a + b + c;
}

// 2.如果函数声明有默认值，函数实现的时候就不能有默认参数
//简单来说，就是声明和实现只能有一个有默认参数
int func3(int a = 10, int b = 10); // 有声明的好处，让编译器知道有这个函数，去找它的实现
int func3(int a, int b)
{
    return a + b;
}

int main()
{
    cout << func(10, 30) << endl;
    cout << func2(10, 30) << endl;
    cout << func3() << endl;

    return 0;
}