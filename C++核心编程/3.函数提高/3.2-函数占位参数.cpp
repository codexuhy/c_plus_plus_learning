#include <iostream>
using namespace std;
/*
    C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
*/
void func(int a, int)
{
    cout << "this is func " << endl;
}

void func1(int a, int = 10)
{ // int = 10 w为占位参数
    cout << "this is func1 " << endl;
}

int main()
{

    func(10, 10); //占位参数必须填补
    func1(10);

    return 0;
}