#include<iostream>
using namespace std;


class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C; // 私有成员只是被隐藏了，但还是会继承下去
};


class Son : public Base
{
public:
    int m_D;
};

void test01(){
    cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main(){

    test01();

    return 0;
}