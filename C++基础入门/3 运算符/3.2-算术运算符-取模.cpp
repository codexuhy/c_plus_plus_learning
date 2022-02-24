#include <iostream>
using namespace std;

int main(){
    //只有整型变量可以进行取模运算
    int a1 = 10;
    int b1 = 3;

    cout << a1 % b1 << endl;

    int a2 = 10;
    int b2 = 20;
    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 20;

    //cout << a3 % b3 << endl;//取模运算时，除数也不为0

    //两个小数不可以取模
    double d1  = 3.14;
    double d2 = 1.1;
    // cout << d1 % d2 << endl;

    return 0;
}