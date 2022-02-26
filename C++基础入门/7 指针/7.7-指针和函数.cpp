#include<iostream>
using namespace std;

//注： 解引用 *p  就是通过指针变量存放的地址去找到内存中对应的值

//值传递
void swap1(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//地址传递
void swap2(int * p1,int * p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){

    // 指针和函数
    int num1 = 1;
    int num2 = 2;
    cout << "值交换前" << endl;
    cout << num1 << "," << num2 << endl; 
    swap1(num1,num2);//值传递不会改变实参
     cout << "值传递后" << endl;
    cout << num1 << "," << num2 << endl;
    swap2(&num1,&num2);// 地址传递会改变实参

    cout << "地址传递后" << endl;
    cout << num1 << "," << num2 << endl;

    return 0;
}
