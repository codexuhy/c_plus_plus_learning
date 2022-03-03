#include <iostream>
using namespace std;

/*
    new关键字：
        C++中利用new关键字在堆区开辟数据
        堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
        语法： new 数据类型
        利用new 创建的数据，会返回该数据对应的类型的指针
*/

// 1、new的基本语法
int *func()
{
    //在堆区创建整型数据
    // new 返回的是  该数据类型的指针
    int *p = new int(10);
    return p;
}

void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据由程序员管理开辟，程序员管理释放
    //如果想释放堆区的数据，利用关键字delete
    delete p;
    cout << *p << endl; // 内存已经被释放，在此访问就是非法操作，会报错
}

// 2、在堆区利用new 开辟数组
void test02()
{
    // 创建10个整型数据的数组，在堆区
    int *arr = new int[10]; // 10代表数组有10个元素

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100; // 给10个元素赋值 100~109
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{

    test01();

    test02();

    return 0;
}