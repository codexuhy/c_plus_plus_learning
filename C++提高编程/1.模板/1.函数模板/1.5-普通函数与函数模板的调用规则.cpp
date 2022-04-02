#include <iostream>
using namespace std;

/*
    普通函数与函数模板调用规则
        1.如果函数模板和普通函数都可以调用，优先调用普通函数
        2.可以通过空模板参数列表 强制调用 函数模板
        3.函数模板也可以发生重载
        4.如果函数模板可以产生更好的匹配,优先调用函数模板
    总结：既然提供了函数模板,最好不要提供普通函数,否则容易出现二义性
*/

// 普通函数
void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

// 函数模板
template <typename T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template <typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用的重载的模板" << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    myPrint(a, b);      // 1.如果函数模板和普通函数都可以调用，优先调用普通函数
    myPrint<>(a, b);    // 2.可以通过空模板参数列表 强制调用 函数模板
    myPrint(a, b, 100); // 3.函数模板也可以发生重载
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1,c2);// 4.如果函数模板可以产生更好的匹配,优先调用函数模板
    return 0;
}