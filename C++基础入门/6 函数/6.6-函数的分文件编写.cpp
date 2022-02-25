#include<iostream>
using namespace std;

#include "swap.h"
void swap(int a,int b)
{
    int temp = a;
    b = a;
    a = temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//1、创建.h后缀名的头文件
//2、创建.cpp后缀名的源文件
//3、在头文件中写函数的声明
//4、在源文件中写函数的定义


int main(){

    swap(2,5);
    return 0;
}