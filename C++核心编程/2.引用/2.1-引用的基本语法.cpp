#include <iostream>
using namespace std;

int main()
{
    /*
        引用

        作用： 给变量起别名
        语法：数据类型 & 别名 = 原名
    */

    int a = 10;
    //创建引用
    int &b = a;

    cout << "a = " << a << endl; // 10
    cout << "b = " << b << endl; // 10

    b = 100;

    cout << "a = " << a << endl; // 100
    cout << "b = " << b << endl; // 100

    return 0;
}
