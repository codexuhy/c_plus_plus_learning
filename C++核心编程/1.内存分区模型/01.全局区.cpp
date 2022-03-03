#include<iostream>
using namespace std;

/*
    局部变量a的地址为：140722326149864
    局部变量b的地址为：140722326149868
    全局变量a的地址为：6299760
    全局变量b的地址为：6299764
    静态变量s_a的地址为：6299768
    静态变量s_b的地址为：6299772
    字符串常量的地址为：4197591
    全局常量c_g_a的地址为：4197400
    全局常量c_g_b的地址为：4197404
    局部变量c_l_a的地址为：140722326149872
    局部变量c_l_b的地址为：140722326149876

    总结：
    全局区：全局变量、静态常量（static关键字）、常量：字符串常量、const修饰的全局变量（全局变量）
    不在全局区：局部变量、const修饰的局部变量
*/

// 全局变量
int g_a = 10;
int g_b = 10;

// const修饰的全局变量，全局变量
const int c_g_a = 10;
const int c_g_b = 10;

int main(){

    // 全局区

    // 全局变量、静态变量、常量

    // 创建普通局部变量
    int a= 10;
    int b = 10;

    cout << "局部变量a的地址为：" << (long)&a << endl;
    cout << "局部变量b的地址为：" << (long)&b << endl;

    cout << "全局变量a的地址为：" << (long)&g_a << endl;
    cout << "全局变量b的地址为：" << (long)&g_b << endl;

    // 静态变量 在普通变量前面加static  属于静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址为：" << (long)&s_a << endl;
    cout << "静态变量s_b的地址为：" << (long)&s_b << endl;


    // 常量
    // 字符串常量
     cout << "字符串常量的地址为：" << (long)&"hello_world" << endl;

     // const 修饰的变量
     // const修饰的全局变量，const修饰的局部变量
    cout << "全局常量c_g_a的地址为：" << (long)&c_g_a << endl;
    cout << "全局常量c_g_b的地址为：" << (long)&c_g_b << endl;


    const int c_l_a = 10; // c-const l-local 
    const int c_l_b = 10;
    cout << "局部变量c_l_a的地址为：" << (long)&c_l_a << endl;
    cout << "局部变量c_l_b的地址为：" << (long)&c_l_b << endl;

 

    return 0;
}

