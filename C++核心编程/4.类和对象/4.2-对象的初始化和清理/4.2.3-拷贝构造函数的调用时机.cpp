#include <iostream>
using namespace std;

/*
    拷贝构造函数的调用时机
        1.使用一个已经创建完毕的对象来初始化一个新对象
        2.值传递的方式给函数参数传值
        3.以值方式返回局部对象

*/

class Person
{
public:
    Person()
    {
        cout << "无参构造函数调用" << endl;
    }
    Person(int age)
    {
        m_Age = age;
        cout << "有参构造函数调用" << endl;
    }

    Person(const Person &p)
    {
        m_Age = p.m_Age;
        cout << "拷贝函数调用" << endl;
    }
    ~Person()
    {
        cout << "析构函数调用" << endl;
    }

    int m_Age;
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);// Person p2 = p1 ;
    cout << "p2年龄为： " << p2.m_Age << endl; 
}

// 2.值传递的方式给函数参数传值
void doWork(Person p){

}
void test02()
{
    Person p;
    doWork(p);
}

// 3.以值方式返回局部对象（ubuntu16亲测p和p1地址一样，visual studio测地址不一样）

Person doWork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}

void test03(){
    Person p = doWork2();
    cout << (int*)&p << endl;
}

int main()
{

    // test01();

    // test02();

    test03();

    return 0;
}