#include<iostream>
using namespace std;
//声明可以多次，定义只能一次
//声明
int max(int a,int b);
//定义
int max(int a,int b)
{
    return a>b?a:b;
}


int main(){
    int num;
    num = max(1,3);
    cout << "num = " << num << endl;
    return 0;
}