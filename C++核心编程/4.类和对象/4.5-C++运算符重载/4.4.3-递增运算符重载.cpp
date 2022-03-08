#include<iostream>
using namespace std;

class MyInteger{
    friend ostream& operator<<(ostream& cout,MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符 
    MyInteger& operator++(){
        // 先++
        m_Num++;
        // 再将自身做返回
        return *this;
    }

    //重载后置++运算符
    // MyInteger operator++(int) int 代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int){
        // 先记录当前结果,然后让本身值加1，但是返回的是以前的值，达到返回
        MyInteger temp = *this;
        // 后 递增
        m_Num++;
        //最后将记录结果返回
        return temp;
    }


private:
    int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout,MyInteger myint)
{
    cout << myint.m_Num;
    return cout;
}


void test01(){
    MyInteger myint;
    cout << ++myint << endl;
    cout << myint << endl;
    cout << myint++ << endl;
    cout << myint << endl;
}


int main(){

    test01();

    return 0;
}