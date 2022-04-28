#include<iostream>
using namespace std;

/*
    学习目标：
        掌握类模板成员函数分文件编写产生的问题以及解决方式
    问题：
        类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
    解决：
        解决方式1：直接包含.cpp源文件
        解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp  hpp是约定的名称 并不是强
*/


// 问题：直接包含person.h 显示无法解析外部命令
// 原因：类模板中成员函数创建时机是在调用阶段，导致分文件编写链接不到
// 第一种解决方式：直接包含 源文件
// #include "person.cpp"

// 第二种解决方式，将.h和.cpp的内容写到一起，将后缀名改为.hpp文件
// 一般都有一种约定俗成的规定，.hpp为类模板(声明和实现都写一起)（主流的方式）
#include "person.hpp"



// template <class T1,class T2>
// class Person{
// public:
//     Person(T1 name,T2 age);
    
//     void showPerson();

//     T1 m_Name;
//     T2 m_Age;
// };

// template<class T1,class T2>
// Person<T1,T2>::Person(T1 name,T2 age){
//     this->m_Name = name;
//     this->m_Age = age;
// }

// template<class T1,class T2>
// void Person<T1,T2>::showPerson()
// {
//     cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
// }

void test01()
{
    Person<string,int> p("Jerry",18);
    p.showPerson();
}

int main(){
    
    test01();

    return 0;
}