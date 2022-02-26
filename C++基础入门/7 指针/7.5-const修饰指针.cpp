#include<iostream>
using namespace std;

int main(){

    //const修饰指针
    int a= 10;
    int b = 20;
    cout << "修改前地址和值" << endl;
    cout <<"&a = " << &a << "\ta = " << a << endl;
    cout <<"&b = " << &b << "\tb = " << b << endl;

    // int * p = &a;
    // cout <<"指针" << endl;
    // cout << "地址" << p << endl;
    // cout << "值 = " << *p << endl;

    //1.常量指针： 
    //特点：指针的指向可以修改，但是指针指向的值不可以改
    // const int * p = &a;
    // p = &b;
    // cout <<"常量指针" << endl;
    // cout << "地址" << p << endl;
    // cout << "值 = " << *p << endl;

    //2.指针常量： 
    //特点：指针的指向不可以修改，指针指向的值可以修改
    // int * const p = &a;
    // *p = 20;
    // cout <<"指针常量" << endl;
    // cout << "地址" << p << endl;
    // cout << "值 = " << *p << endl;


    //3. const 即修饰指针，又修饰常量
    //特点：指针的指向和指针的值都不可以改
    const int * const p =  &a;
    // *p = 20;//错误
    // p = &b;//错误

    return 0;
}