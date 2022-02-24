#include <iostream>
using namespace std;

int main(){
    // 逻辑运算符 - 非 ！
    int a = 10;
    // 在C++中除了0 都为真
    cout << !a << endl;//0

    cout << !!a << endl;//1

    // 逻辑运算符 - 与 &&

    cout << (2&&10) << endl;//1

    cout << (0&&10) << endl;//0


    // 逻辑运算符 - 或 ||

    cout << (1||0) << endl;//1

    cout << (0||0) << endl;//0

    return 0;
}