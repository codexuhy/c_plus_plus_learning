#include<iostream>
using namespace std;

int main(){
    //野指针
    //0、定义：指针变量指向非法的内存空间
    //(指针指向没有申请的地址空间)

    //指针变量p指向内存地址编号为0x1100的空间
    int * p = (int *)0x1100;

    //访问野指针报错
    cout << *p << endl;


    //正常的指针需要先开辟一块内存地址(a)，然后再执行它(*q = &a)
    int a = 66;
    int * q = &a;
    cout << *q << endl;

    return 0;
}


// 总结：空指针和野指针都不是我们申请的空间,因此不要访问。