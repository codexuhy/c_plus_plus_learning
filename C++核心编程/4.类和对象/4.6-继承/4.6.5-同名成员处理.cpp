#include <iostream>
using namespace std;

/*
    当子类与父类出现同名的成员，如何通过子类对象，访问到子类或者父类同名的数据？
        访问子类同名成员，直接访问即可
        访问父类同名成员，需要加作用域
*/

class Base
{
public:
    Base()
    {
        m_A = 10;
    }
    void func()
    {
        cout << "Base下的 func" << endl;
    }
    void func(int a)
    {
        cout << "Base下的 func = " << a << endl;
    }
    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 20;
    }
    void func()
    {
        cout << "Son下的 func" << endl;
    }
    int m_A;
};

// 同名成员属性处理
void test01()
{
    Son s;
    cout << "Son 下m_A = " << s.m_A << endl;
    cout << "Base下的 func" << s.Base::m_A << endl;
}
// 同名成员函数处理
void test02()
{
    Son s;
    s.func(); // 调用子类成员，直接调用
    // 如何调用父类中同名的成员函数？
    s.Base::func();
    // 如果子类中出现和父类同名的成员函数,子类的同名成员会隐藏掉父类中所有同名成员函数
    // 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s.Base::func(100);
}

int main()
{
    test01();
    test02();

    return 0;
}