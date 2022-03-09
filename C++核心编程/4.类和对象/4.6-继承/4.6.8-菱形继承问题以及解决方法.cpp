#include <iostream>
using namespace std;
/*
    菱形继承问题：一个基类派生出两个子类，之后有一个新的类继承这两个派生类
    总结：
        菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
        利用虚继承可以解决菱形继承问题
*/
class Animal
{
public:
    int m_Age;
};

//继承前加virtual 关键字，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal
{
};
class Tuo : virtual public Animal
{
};
class SheepTuo : public Sheep, public Tuo
{
};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 100;

    cout << " st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << " st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << " st.m_Age = " << st.Sheep::m_Age << endl;
}

int main()
{
    test01();
    return 0;
}