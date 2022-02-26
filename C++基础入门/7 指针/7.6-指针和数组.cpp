#include<iostream>
using namespace std;

int main(){

    //指针和数组
    //利用指针访问数组中的元素

    int arr[9] = {2,3,4,5,6,7,8,9};

    cout << "利用数组下标访问第二个元素：" << arr[1] << endl;

    int * p = arr;//指针指向数组的首地址

    cout << "利用指针访问数组中第二个元素：" <<*(p+1) <<endl;

    *p++;
    *p++;

    cout << "利用指针访问数组第四个元素：" << *p << endl;


    cout << "使用指针遍历数组" << endl;
    int * p1 = arr;
    for (int i = 0 ;i < 8; i++)
    {
        cout << "数组中第"  << (i+1) << "个元素: " << *(p1+i) << endl;
    }


    return 0;
}