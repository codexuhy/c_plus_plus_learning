#include <iostream>
using namespace std;

/*
- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递
*/
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    string operator()(string test)
    {
        this->count++; //统计使用次数
        return test;
    }
    int count; //内部自己的状态
};

void doPrint(MyPrint &mp, string test)
{

    cout << mp(test) << endl;
}

void test01()
{
    // 1、 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    MyAdd myAdd;
    cout << myAdd(10, 20) << endl;

    // 2、 函数对象超出普通函数的概念，函数对象可以有自己的状态
    MyPrint myPrint;
    cout << myPrint("hello world") << endl;
    cout << myPrint("hello world") << endl;
    cout << myPrint("hello world") << endl;
    cout << myPrint.count << endl; // 可以记录调用次数

    // 3、 函数对象可以作为参数传递
    MyPrint myprint1;
    doPrint(myprint1, "hello C++");
}

int main()
{
    test01();

    return 0;
}