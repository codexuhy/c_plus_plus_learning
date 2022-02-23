#include <iostream>
using namespace std;

int main(){
    //整型 （ 占用内存空间的不同，表示的数值范围也不同）
    // 1、short 短整型 2字节 -2^15 ~ 2^15-1（-32768 ~ 32767）
    short num1 = 32768; // 越界会返回 -32768

    // 2、int 整型 4字节 -2^31 ~ 2^31-1
    int num2 = 32768;
    
    // 3、长整型 window 4 字节 linux 4字节（32位） 8字节（64位）-2^31 ~ 2^31-1
    long num3 = 10;

    //4、长长整型 8字节 -2^63 ~ 2^63-1
    long long num4  = 10;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;
    return 0;
    
    
}