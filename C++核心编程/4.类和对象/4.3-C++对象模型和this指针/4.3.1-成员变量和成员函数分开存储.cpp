#include <iostream>
using namespace std;
/*
    成员变量和成员函数时分开存储的
    只有非静态成员变量才属于类的对象
*/

class Person
{
public:
    Person()
    {
        mA = 0;
    }
    //非静态成员变量占类对象空间
    int mA;
    //静态成员变量不占对类象空间
    static int mB;
    //函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA" << this - mA << endl;
    }
};

int Person::mB = 0;

void test01()
{
    // 空对象占用内存空间为:1
    // C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    Person p;
    cout << sizeof(p) << endl;
}

int main()
{

    Person p;
    cout << sizeof(p) << endl;

    return 0;
}