#include<iostream>
using namespace std;

/*
    构造函数和析构函数
        对象的初始化和清理
        1.构造函数 进行初始化操作
            没有返回值 不用写void
            函数名 与 类名 相同
            构造函数可以有参数，可以发生重载
            创建对象的时候，构造函数会自动调用，而且只会调用一次
        2.析构函数 进行清理的操作
            没有返回值 不写void
            函数名和类名相同 在名称前加~
            析构函数不可以有参数的，不可以发生重载
            对象在销毁前 会自动调用析构函数，而且只会调用一次

*/

class Person{

public:
    //1.构造函数
    Person(){
        cout << "Person 的构造函数调用" << endl;
    }
    ~Person(){
        cout << "Person 的析构函数调用" << endl;
    }


};

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01(){
    Person p;//在栈区存放的数据，test01执行完毕后，释放掉这个对象
}

int main(){

    test01();

    // Person p1;

    return 0;
}