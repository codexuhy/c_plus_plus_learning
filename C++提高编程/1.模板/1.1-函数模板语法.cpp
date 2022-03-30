#include<iostream>
using namespace std;
/*
    C++提供了两种模板机制：函数模板和类模板
    函数模板作用：
        建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表。
    语法：
    template<typename T>
    函数声明或定义
    解释：
    template --- 声明创建模板
    typename --- 表明其后面的符号是一种数据类型，可以用class代替
    T --- 通用的数据类型，名称可以替换，通常为大写字母
    总结：
        函数模板利用关键字template
        使用函数模板有两种方式:自动类型推导，显示指定类型
        模板的目的是为了提高复用性，将类型参数化
*/

// 交换整型函数
void swapInt(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//交换浮点型函数
void swapDouble(double &a,double &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//利用模板提供通用的交换函数
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    
    swapInt(a,b);

    //利用模板实现交换
    //1、自动类型推导
    mySwap(a,b);

    //2、显示指定类型
    mnySwap<int>(a,b);

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

int main(){

    void test01();

    return 0;
    
}

