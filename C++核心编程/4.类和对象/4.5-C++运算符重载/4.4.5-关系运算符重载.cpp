#include <iostream>
using namespace std;

/*
   重载关系运算符，可以让两个自定义类型对象进行对比操作
*/
class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //同理 可以写出 != 关系重载运算符
    bool operator!=(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("张三", 18);
    Person p2("张三", 18);
    if (p1 == p2)
    {
        cout << "p1和p2相等" << endl;
    }
    else
    {
        cout << "p1和p2不相等" << endl;
    }

    if (p1 != p2)
    {
        cout << "p1和p2不相等" << endl;
    }
    else
    {
        cout << "p1和p2相等" << endl;
    }
}

int main()
{

    test01();

    return 0;
}