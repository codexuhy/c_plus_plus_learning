#include <iostream>
using namespace std;

// 常量的定义方式
//1. # define 宏常量
//2. const 修饰的变量

//1. #define 宏常量
#define Day 7
int main() {
    //Day  = 14; // 错误，Day是常量，一旦修改就会报错
    cout << "一周总共有：" << Day << " 天" << endl;
    return 0;

    // 2.const 修饰的变量
    const int month = 12;
    // month = 24; //错误,const修饰的变量也称为常量
    return 0;

}