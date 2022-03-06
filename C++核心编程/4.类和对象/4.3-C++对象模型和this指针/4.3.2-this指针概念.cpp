#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        // this指针指向 被调用的成员函数 所属的对象
        this->age = age;
    }
    Person& PersonAddAge(Person &p)
    // 返回引用 Person& PersonAddAge(Person &p) ==>值40 返回的还是p2
    // 返回值 Person PersonAddAge(Person &p) ==> 值20 返回的不是p2了，相当于创建了一个新的对象
    {
        this->age += p.age;
        return *this;
    }

    int age;
};

// 1 解决名称冲突
void test01()
{
    Person p1(18);
    cout << "p1年龄为： " << p1.age << endl;
}

void test02()
{
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2年龄为：" << p2.age << endl;
}

int main()
{
    // test01();

    test02();

    return 0;
}