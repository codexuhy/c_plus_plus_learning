#include <iostream>
using namespace std;

/*
    多继承：C++实际开发中不建议使用多继承，语法需要掌握
        语法：class 子类: 继承方式 父类1， 继承方式 父类2 ...
        多继承可能会引发父类中有同名成员出现，需要加作用域区分
*/

class Base1
{
public:
    int m_A;
};

class Base2
{
public:
    int m_A;
};

class Son : public Base1, public Base2
{
public:
    int m_C;
    int m_D;
};

void test01()
{
    Son s;
    s.Base1::m_A = 100;
    s.Base2::m_A = 200;
    //父类中出现同名成员,需要加作用域区分
    cout << "Base1 的m_A = " << s.Base1::m_A << endl;
    cout << "Base2 的m_A = " << s.Base2::m_A << endl;
}

int main()
{

    test01();
    return 0;
}