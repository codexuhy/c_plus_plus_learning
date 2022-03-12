#include <iostream>
using namespace std;
/*
    多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
    解决方式：将父类中的析构函数改为 虚析构 或者 纯虚析构

    虚析构和纯虚析构的共性：
        可以解决父类指针释放子类对象
        都需要具体的函数实现
    虚析构和纯虚析构区别：
        如果是纯虚析构，该类属于抽象类，无法实例化
    虚析构语法：
        virtual ~()类名(){};
    纯虚析构语法：
        virtual ~类名() = 0;
        类名::~类名(){}

*/
class Animal
{
public:
    Animal()
    {
        cout << "Animal构造被调用" << endl;
    }
    //利用虚析构可以解决父类指针释放子类对象不干净的问题
    // virtual ~Animal(){
    //     cout << "Animal析构被调用" << endl;
    // }
    //纯虚析构 需要声明也需要实现
    //有了纯虚析构后，这个类也属于抽象类，无法实例化
    virtual ~Animal() = 0;

    // 纯虚函数
    virtual void speak() = 0;
};
Animal::~Animal()
{
    cout << "Animal析构被调用" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造被调用" << endl;
        m_Name = new string(name);
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数被调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    void speak()
    {
        cout << "Cats:我重写了Animal虚函数" << endl;
    }

    string *m_Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构时候，不会调用子类中的析构函数，导致如果堆区有属性，出现内存泄漏
    delete animal;
}

int main()
{
    test01();
    return 0;
}