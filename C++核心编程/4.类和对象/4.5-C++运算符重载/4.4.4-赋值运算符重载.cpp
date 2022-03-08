#include<iostream>
using namespace std;

/*
    赋值运算符重载
    C++编译器至少给一个类添加4个函数
    1.默认构造函数（无参，函数体为空）
    2.默认析构函数（无参，函数体为空）
    3.默认拷贝构造函数，对属性进行值拷贝
    4.赋值运算符operator=，对属性进行值拷贝

    如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/

class Person{
public:
    Person(int age){
        m_Age = new int(age);
    }

    // // //重载 赋值运算符
    Person& operator=(Person &p)
    {
        //编译器是提供浅拷贝
        //m_Age = p.m_Age;
       
        // 应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        // 深拷贝
        m_Age = new int (*p.m_Age);
        //返回对象本身
        return *this;
    }

    ~Person(){
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    int *m_Age;
};

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << "p1的年龄为：" << *p1.m_Age << endl;
    cout << "p2的年龄为：" << *p2.m_Age << endl;
    cout << "p2的年龄为：" << *p3.m_Age << endl;
}
int main(){

    test01();

    return 0;
}