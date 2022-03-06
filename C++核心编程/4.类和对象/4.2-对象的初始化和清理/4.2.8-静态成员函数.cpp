#include<iostream>
using namespace std;

/*
    静态尘缘就是在静态变量和成员函数前加上static关键字，称为静态成员
    静态成员分为：
        静态成员变量：
            所有对象共享一份数据
            在编译阶段分配内存
            类内声明，类外初始化
        静态成员函数：
            所有对象共享同一个函数
            静态成员函数只能访问静态成员变量

*/
class Person{
public:
    //静态成员函数 
    static void func(){
        m_A = 100;//静态成员函数 可以访问静态成员变量
        // m_B = 200;静态成员函数 不可以访问静态成员变量 ,原因：无法区分到底是哪个对象的成员
        cout << "static void func调用 " << endl;
    }

    static int m_A;//静态成员变量
    int m_B;//非静态成员变量
private:
    static void func2(){
        cout << "static void func2调用 " << endl;
    }

};

int Person::m_A = 0;

int main(){
    

    // 1.通过对象访问
    Person p;
    p.func();

    //2.通过类名访问
    Person::func();

    // Person::func2();//类外访问不到私有静态成员函数

    return 0;
}