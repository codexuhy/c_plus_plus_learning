#include <iostream>
using namespace std;


// 打印数据函数
void showValue(const int &ref)
{
    // ref = 1000;
    cout << ref << endl;
}

int main()
{

    // 常量引用
    // 使用场景：用来修饰形参，防止误操作

    // int& ref = 10; // 引用本身需要一个合法的内存空间，因此这行错误
    // 加上const就可以了, 编译器优化代码，将代码修改为 int temp = 10; const int & ref = temp;
    // const int &ref = 10; //其实这个引用，引用的是一块临时的空间
    // ref = 20;//加入const后为只读，不可以修改

    int a = 100;
    cout << "a = " << a << endl;
    showValue(a);// 函数利用常量引用防止误操作修改实参
    cout << "a = " << &a << endl;

    int aa = 10;
    int &bb = aa;
    cout << bb << endl;

    return 0;
}
