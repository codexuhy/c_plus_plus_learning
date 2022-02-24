#include <iostream>
using namespace std;

int main(){

    //数组名用途
    // 1. 可以获取整个数组占用内存空间大小
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "数组所占内存空间为：" << sizeof(arr) << endl;
    cout << "每个元素占用的空间为：" << sizeof(arr[0]) << endl;
    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;


    //2.可以通过数组名获取到数组首地址
    cout  << "数组首地址为：" << arr << endl;
    cout  << "数组中第一个元素的地址为：" << &arr[0] << endl;

    //数组名是常量,不可以进行复制操作
    // arr = 100;
    
    return 0;
}