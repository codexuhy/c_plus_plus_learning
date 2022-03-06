#include<iostream>
using namespace std;
/*
    先调用对象的构造，再调用自身的构造，先析构自身的构造，再析构对象成员
*/
// class A{
// public:
//     A(){
//         cout << "A的无参构造调用" << endl;
//     }
//     ~A(){
//         cout << "A的析构函数调用" << endl;
//     }
// };

// class B{
// public:
//     B(){
//         cout << "B的无参构造调用" << endl;
//     }
//     ~B(){
//         cout << "B的析构函数调用" << endl;
//     }

//     A a;
// };

    
// int main(){

//     B b;
//     return 0;
// }


class Phone{
public:
    Phone(string name){
        phone = name;
        cout << "Phone的构造函数" << endl;
    }
    string phone;
};

class Person{
public:
    Person(string name,string phone_name):m_Name(name),m_Phone(phone_name){
        cout << "Person的构造函数" << endl;
    }

    string m_Name;
    Phone m_Phone;

};

int main(){

    Person p("张三","苹果MAX");
    return 0;
}