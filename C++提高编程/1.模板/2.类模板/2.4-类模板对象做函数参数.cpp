#include<iostream>
using namespace std;
#include<string>
#include <typeinfo>
/*
    学习目标：
        类模板实例化出的对象，向函数传参的方式
    一共有三种传入方式：
        1.指定传入的类型  --- 直接显示对象的数据类型
        2.参数模板化      --- 将对象中的参数变为模板进行传递
        3.整个类模板化    ---  将这个对象类型 模板化进行传递
*/
template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType name,AgeType age){
        this->mName = name;
        this->mAge = age;
    }
    void showPerson(){
        cout << "name: " << mName << "age: " << mAge << endl; 
    }
    NameType mName;
    AgeType mAge;

};
//1.传入指定类型
void printPerson1(Person<string,int> &p){
    p.showPerson();
}
void test01(){
    Person<string,int> p("孙悟空",555);
    printPerson1(p);
}


//2.参数模板化
template<typename T1,typename T2>
void printPerson2(Person< T1,T2> &p){
    p.showPerson();
    cout << "T1的数据类型为：" <<typeid(T1).name() << endl;
    cout << "T2的数据类型为：" <<typeid(T2).name() << endl;
}
void test02(){
    Person<string,int> p("猪八戒",666);
    printPerson2(p);
}

// 3.整个类模板化 
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout << "T的数据类型为：" <<typeid(T).name() << endl;
}
void test03(){
    Person<string,int> p("沙和尚",777);
    printPerson3(p);
}
int main(){
    test01();
    test02();
    test03();
    
    return 0;
}