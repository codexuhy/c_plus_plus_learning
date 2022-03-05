#include <iostream>
using namespace std;

/*
    深浅拷贝，面试经典问题，也是常见的一个坑！
    浅拷贝:简单的赋值拷贝操作
    深拷贝：在堆区重新申请空间，进行拷贝操作
*/
class Person
{

public:
    Person()
    {
        cout << "默认构造" << endl;
    }

    Person(int age, int height)
    {

        cout << "有参构造" << endl;
        m_Age = age;
        m_Height = new int(height);
    }

    //自己实现拷贝构造 解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "拷贝构造调用" << endl;
        m_Age = p.m_Age;
        // m_height = p.m_Height;//编译器默认实现就是这行代码
        // 深拷贝操作(如果不利用深拷贝在堆区创建内存，会导致浅拷贝带来的重复释放堆区问题)
        m_Height = new int(*p.m_Height);
    }

    ~Person()
    {
        // 析构代码，将堆区开辟的数据做释放操作
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height;
};

void test01()
{

    Person p1(18, 160);
    Person p2(p1);

    cout << p1.m_Age << "," << *p1.m_Height << endl;
    cout << p2.m_Age << "," << *p2.m_Height << endl;
}

int main()
{

    test01();

    return 0;
}