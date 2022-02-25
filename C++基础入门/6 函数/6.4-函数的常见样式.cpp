#include<iostream>
using namespace std;

//函数常见样式
//1、无参无返
void test01()
{
    //void a = 10; //无类型不可以创建变量，原因无法分配内存
    cout << "this is test01" << endl;
    
}

//2.有参无返
void test02(int num1)
{
    cout << num1 << endl;
}

//3. 无参有返
int test03()
{
    int num2 = 5;
    return num2;
}

//4.有参有返
int test04(int num2)
{
    return num2;
}

int main(){
    test01();
    test02(2);
    int test3;
    test3 = test03();
    cout << "test03 = " << test3 << endl;
    int test4 = test04(5);
    cout << "test04 = " << test4 << endl;
    return 0;
}