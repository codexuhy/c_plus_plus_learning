#include <iostream>
using namespace std;

/*
    引用做函数返回值
        作用：引用是可以作为函数的返回值存在的
        1.注意：不要返回局部变量的引用
        2.用法：函数调用作为左值
*/

// 1.返回局部变量引用
// int & test01()
// {
//     int a = 10; // 局部变量 存放在四区的 栈区
//     return a;
// }

// 2.返回静态变量引用(函数调用作为左值)
int &test02()
{
    static int a = 20; // 静态变量，存放在全局区，全局区的数据在程序结束后释放
    return a;
}

int main()
{

    // int &ref = test01();
    // Linux报错：reference to local variable ‘a’ returned
    // cout << "ref = " << ref << endl;  // window第一次结果正确，因为编译器做了保留
    // cout << "ref = " << ref << endl;  // window第二次结果正确，因为a的内存已经释放

    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000; //如果函数的返回值是引用，这个函数调用可以作为左值
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}