#include<iostream>
using namespace std;

int main(){
    // 32位操作系统下: 占用4个字节空间
    //64位下占用8个字节。
    // uname -m 可在ubuntu查看  i386到i686，那就是32位系统；如果是x86_64 ，那就是64系统

    int a = 10;
    // int * p;
    // p = &a; // 指针指向数据a的地址

    int * p = &a;

    cout << *p << endl; //解引用

    //32位操作系统下，指针是占用4个字节空间大小，不管是什么数据类型
    //64位操作系统下，指针是占用8个字节空间大小
    cout << "sizeof(int *) = " << sizeof(p) << endl; //8
    cout << "sizeof(float *) = " << sizeof(float *) << endl;//8
    cout << "sizeof(double*)= " << sizeof(double*) << endl;//8
    cout << "sizeof(char *) = " << sizeof(char *) << endl;//8

    return 0;
}