#include<iostream>
using namespace std;

/*
    引用的本质：
        本质：C++内部实现是一个指针常量。
*/

void func(int &ref)
{
    ref = 100;//ref是引用，转换成*ref = 100
}

int main()
{
    int a = 10;

    //自动转换为 int* const ref = &a;指针常量是指针指向不可改，也说明为什么引用不可更改
    // int &ref = a;
    // ref = 20;// 内部发现ref是引用，自动帮我们转换为：*ref = 20；

    // cout << "a = " << a << endl;
    // cout << "ref = " << ref << endl;

    
    cout << "a = " << a << endl;
    func(a);
    cout << "ref = " << a << endl;
    
    return 0;
}