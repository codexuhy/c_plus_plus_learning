#include <iostream>
using namespace std;

/*
    普通函数与函数模板区别
        1、普通函数调用可以发生隐式类型转换
        2、 函数模板 用自动类型推导，不可以发生隐式类型转换
        3、函数模板 用显示指定类型，可以发生隐式类型转换
    总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T

*/

//普通函数
int myAdd01(int a, int b)
{
    return a + b;
}

//函数模板
template <class T>
T myAdd02(T a, T b)
{
    return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换，即隐式类型转换

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a, c) << endl; // 普通函数 调用可以发生隐式类型转换  109  a = 10 c = 99
    cout << myAdd02(a, b) << endl; // 函数模板  --> 正常调用
    // cout << myAdd02(a,c) << endl; // 函数模板 --> 用自动类型推导，不可以发生隐式类型转换
    cout << myAdd02<int>(a, c) << endl; // 函数模板 --> 用显示指定类型，可以发生隐式类型转换
}
int main()
{
    test01();

    return 0;
}