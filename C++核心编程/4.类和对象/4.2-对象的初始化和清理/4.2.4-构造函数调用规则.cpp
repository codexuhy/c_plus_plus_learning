#include<iostream>
using namespace std;

/*
    
    默认情况下.c++编译器至少给一个类添加3个函数
    1.默认构造函数（无参,函数体为空）
    2.默认析构函数（无参,函数体为空）
    3.默认拷贝函数,对属性进行值拷贝
    构造函数调用规则：
        如果用户定义有参构造，C++不会提供默认无参构造，但是会提供默认拷贝构造
        如果用户定义拷贝构造，C++不会提供其他构造函数
*/
class Person{
public:
    // Person(){
    //     cout << "无参构造调用" << endl;
    // }

    Person(int age){
        m_Age = age;
        cout << "有参构造调用" << endl;
    }

    // Person(const Person &p){
    //     cout << "拷贝构造调用" << endl;
    // }

    // ~Person(){
    //     cout << "析构函数调用" << endl;
    // }

    int m_Age;

};

// void test01(){
//     Person p1(18);
//     Person p2(p1);
// }

//如果用户定义有参构造，C++不会提供默认无参构造，但是会提供默认拷贝构造
void test02(){
    Person p1(20);
    p1.m_Age = 20;
    Person p2(p1);
    cout << "p2年龄为： " << p2.m_Age << endl;
}

// 如果用户定义拷贝构造，C++不会提供其他构造函数
// void test02(){
//     Person p; // 会报错,找不到匹配的默认构造
// }

int main(){

    // test01();
    test02();
    return 0;
    
}