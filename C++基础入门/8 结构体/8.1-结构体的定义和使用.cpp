#include<iostream>
using namespace std;

/*
    语法：struct 结构体名{ 结构体成员列表};
    通过结构体创建变量的方式有3种：
        1. struct 结构体名 变量名
        2. struct 结构体名 变量名 = {成员1值，成员2值,...};
        3. 定义结构体时候顺便创建变量

    总结：
        1.定义结构体时的关键字struct不能省略
        2.创建结构体变量时，关键字struct可以省略
        3.结构体变量利用操作符"."访问成员
*/

//结构体的定义
struct Student{
    string name;
    int age;
    int score;
}stu3;//结构体变量创建方式3

int main (){

    //结构体变量创建方式1
    struct Student stu1;

    stu1.name = "张三";
    stu1.age = 18;
    stu1.score = 100;

    cout << "姓名："<< stu1.name <<" 年龄：" << stu1.age << " 分数：" << stu1.score << endl;


    //结构体变量创建方式2
    struct Student stu2 = {"李四",19,99};
    cout << "姓名："<< stu2.name <<" 年龄：" << stu2.age << " 分数：" << stu2.score << endl;

    //结构体变量创建方式3(在创建结构体时创建结构体变量)
    stu3.name = "王五";
    stu3.age = 17;
    stu3.score = 98;
    cout << "姓名："<< stu3.name <<" 年龄：" << stu3.age << " 分数：" << stu3.score << endl;


    return 0;
}