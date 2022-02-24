#include <iostream>
using namespace std;

int main(){
    //总结：前置递增先对变量进行++ ,再计算表达式，后置递增反之

    //后置递增
    int a = 10;
    a++; //等价于a = a + 1
    cout << a << endl;

    //前置递增
    int b = 10;
    ++b;
    cout << b << endl; // 11

    //区别
    //前置递增先对变量进行++,在计算表达式
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << b2 << endl;

    //后置递增先计算表达式，后对变量进行++
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << b3 << endl;

    return 0;
}