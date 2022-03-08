#include<iostream>
using namespace std;

/*
    函数调用运算符重载
        函数调用运算符()也可以重载
        由于重载后使用的方式非常像函数的调用，因此称为仿函数
        仿函数没有固定写法，非常灵活
*/

class MyPrint{
public:
    void operator()(string text){//函数调用运算符()也可以重载
        cout << text << endl;
    }
};

void myfunc2(string text){
    cout << text << endl;
}

void test01(){
    MyPrint myfunc;
    myfunc("hello world");//由于重载后使用的方式非常像函数的调用，因此称为仿函数
    myfunc2("hello world");
}


//仿函数没有固定写法，非常灵活(上面返回void,下面返回int)
//加法类
class MyAdd{
public:
    int operator()(int a,int b){
        return a + b;
    }
};

void test02(){
    MyAdd myadd;
    int ret = myadd(100,100);
    cout << "ret= " << ret << endl;

    //匿名函数对象：MyAdd()匿名对象 重载了() 所以叫仿函数
    cout << MyAdd()(100,100) << endl;
}

int main(){

    test01();

    test02();

    return 0;
}