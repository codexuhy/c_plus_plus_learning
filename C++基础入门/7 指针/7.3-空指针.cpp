#include<iostream>
using namespace std;

int main(){
    //空指针
    //0、定义：指针变量指向内存中编号为0的空间
    //1、用途：空指针用于给指针变量进行初始化
    int * p = NULL;
    //2、空指针是不可以进行访问的
    // 0~255之间的内存编号是系统占用的，因此不可以访问
    *p = 1000;

    cout << *p << endl;

    return 0;
}