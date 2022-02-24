#include <iostream>
using namespace std;

int main(){

    //赋值运算符
    
    int a = 10;
    a += 2;
    cout << a << endl;//12

    a = 10;
    a *= 2;
    cout << a << endl;//20

    a = 10;
    a /= 2;
    cout << a << endl;//5

    a  = 10;
    a %= 2;
    cout << a << endl;//0
 
    return 0;
}