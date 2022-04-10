#include <iostream>
using namespace std;
#include <string>

/*
    类模板与函数模板区别主要有两点：
        1.类模板没有自动类型推导的使用方式
        2.类模板在模板参数列表中可以有默认参数
*/

// 2.类模板在模板参数列表中可以有默认参数
template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name:" << mName << "age:" << mAge << endl;
    }
    NameType mName;
    AgeType mAge;
};

void test01()
{
    // 1.类模板没有自动类型推导的使用方式
    //  Person p("孙悟空",1000)// 错误，无法用自动类型推导
    //  Person<string,int> p1("孙悟空", 666);// 正确，只能用自动类型推导

    // 2.类模板在模板参数列表中可以有默认参数
    Person<string> p1("孙悟空", 666);
    p1.showPerson();
}
int main()
{
    test01();
    return 0;
}