#include <iostream>
using namespace std;

/*
    构造函数的分类和调用
        两种分类方式：
            按参数分为：有参构造和无参构造
            按类型分为：普通构造和拷贝构造
        三种调用方式：
            1.括号法
            2.显示法
            3.隐式转换法
*/

class Person
{
public:
    Person()
    {
        cout << "无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "有参构造函数调用" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的人身上的所有属性，拷贝到我的身上
        cout << "拷贝构造函数调用" << endl;
        age = p.age;
    }
    ~Person()
    {
        cout << "析构构造函数调用" << endl;
    }

public:
    int age;
};

void test01()
{

    // 1.括号法
    // Person p1;     // 默认拷贝函数调用
    // Person p2(10); // 有参构造函数
    // Person p3(p2); // 拷贝构造函数

    // 注意事项
    // 调用默认函数时候，不要加()
    // 因为下面这行代码。编译器会认为是一个函数的声明，不会认为在创建对象
    // Person p1();

    // cout << "p2的年龄为：" << p2.age << endl;
    // cout << "p3的年龄为：" << p3.age << endl;

    // 2. 显示法
    Person p1;
    Person p2 = Person(10);// 有参构造
    // Person p3 = Person(p2);// 拷贝构造

    // Person(10); //匿名对象  特点：当前行执行结束后，系统会立即析构(也就是回收匿名对象)
    // cout << "aaa" << endl;

    // 注意事项2
    // 不要利用拷贝构造函数初始化匿名对象 编译器会认为 Person (p3) === Person p3;当成对象声明
    Person(p3);

    //3.隐式转换法
    Person p4 = 10; // 有参构造 相当于 Person p4  = Person(10); 
    Person p5 = p4; // 拷贝构造 相当于 Person p5  = Person(p4)


}

int main()
{

    test01();

    return 0;
}