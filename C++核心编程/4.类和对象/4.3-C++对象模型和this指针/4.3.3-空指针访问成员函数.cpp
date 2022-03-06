#include <iostream>
using namespace std;
/*
    C++空指针也是可以调用成员函数的，但是要注意有没有用到this指针

    如果用到this指针，需要加以判断保证代码的健壮性
*/

// 空指针访问成员函数
class Person
{
public:
    void showClassName()
    {
        cout << "我是Person类" << endl;
    }

    void showPerson(int age)
    {
        //不加入下面的代码会报错，原因传入的指针为空
        // if (this == NULL){
        //     return;
        // }

        m_Age = age;
        cout << "年龄为：" << m_Age << endl; // 打印m_Age实际是调用this->m_Age,默认加了this->
    }

    int m_Age;
};

int main()
{

    Person *p1 = NULL;
    p1->showClassName();
    p1->showPerson(10);
    // p1->m_Age = 10;
    // cout << p1.m_Age << endl;

    return 0;
}