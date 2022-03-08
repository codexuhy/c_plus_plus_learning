#include<iostream>
using namespace std;

/*
    继承
        好处：可以减少重复的代码
        class A : public B;
        A 类称为子类 或派生类
        B 类称为父类 或基类

        派生类中的成员，包含两大部分：
        一类是从基类继承过来的，一类是自己增加的成员。
        从基类继承过来的表现其共性，而新增的成员体现了其个性。
*/
class Animal{
public:
    void eat(){
        cout << "吃饭饭" << endl;
    }

    void run(){
        cout << "跑步步" << endl;
    }
};

class Dog:public Animal
{
public:
    void action(){
        cout << "狗儿叫叫" << endl;
    }
};


class Cat:public Animal{
public:
    void action(){
        cout << "猫儿喵喵" << endl;
    }
};

int main(){
    Dog dog;
    dog.eat();
    dog.run();
    dog.action();
    Cat cat;
    cat.eat();
    dog.run();
    cat.action();


    return 0;
}