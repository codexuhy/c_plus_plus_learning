#include <iostream>
using namespace std;

#include <typeinfo> // gcc只输出类型名的第一个字符
#include <cxxabi.h> //使用abi  将名字完整输出
/*
    类模板与继承：
        当类模板碰到继承时，需要注意以下几点：
        1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中的T类型***
        2.如果不指定，编译器无法给子类分配内存
        3.如果想灵活制定出父类中T的类型，子类也需变为类模板
*/

template <class T>
class Base
{
    T m;
};

// class Son:public Base // 错误， C++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son : public Base<int> //必须指定一个类型
{
};


void test01()
{
    Son s1;
}

//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>
{
public:
    Son2(){
        cout << "T1的类型为："<< abi::__cxa_demangle(typeid(T1).name(),0,0,0 ) << endl;
        cout << "T2的类型为："<< abi::__cxa_demangle(typeid(T2).name(),0,0,0 ) << endl;
    }
    T1 obj;
};

void test02(){
    Son2<int,char> S2;
}
int main()
{
    test01();
    test02();

    return 0;
}
