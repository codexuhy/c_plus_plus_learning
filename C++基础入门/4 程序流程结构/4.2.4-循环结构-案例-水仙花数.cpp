#include <iostream>
using namespace std;

int main(){

    //案例:使用do...while找出所有的水仙花数
    //水仙花数是指一个三位数个位，十位，百位，分别3次方的和，等于本身，如：1^3+5^3+3^3 = 153
    int num = 100;
    do{
        int a = 0;
        int b = 0;
        int c = 0;
        a = num % 10;
        b = num /10 % 10;
        c= num /100;

        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout<< "num = " << num << endl;
        }
        num++;
    }while(num < 1000);
    return 0;
}