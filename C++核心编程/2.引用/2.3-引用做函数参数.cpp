#include<iostream>
using namespace std;

/*
    引用做函数参数
        作用：函数传参时，可以利用引用的技术让形参修饰实参
        优点：可以简化指针修改实参
    总结：通过引用参数产生的效果同按地址传递一样的。引用的语法更清楚简单。
*/

//交换函数

//1.值传递
void mySwap01(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;

}

//2.地址传递
void mySwap02(int* a,int *b)
{
    cout << "swap02 a = " << *a << endl;
    cout << "swap02 b = " << *b << endl;

    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "swap02 a = " << *a << endl;
    cout << "swap02 b = " << *b << endl;

}


// 3.引用传递
void mySwap03(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "swap03 a = " << a << endl;
    cout << "swap03 b = " << b << endl;
}
int main(){

    int a = 10;
    int b = 20;
    // mySwap01(a,b); // 值传递，形参不会修饰实参
    
    // mySwap02(&a,&b); // 地址传递，形参会修饰实参

    mySwap03(a,b);// 引用传递，形参会修饰实参的

    return 0;
}