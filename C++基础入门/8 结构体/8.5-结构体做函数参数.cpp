#include <iostream>
using namespace std;
/*
    结构体做函数参数
    作用：将结构体作为参数向函数中传递
    传递方式有2种：
        值传递:实参不会因为形参而改变
        地址传递：实参会因为形参的改变而改变
*/

//学生结构体定义
struct Student
{
    //成员列表
    string name; //姓名
    int age;     //年龄
    int score;   //分数
};

//打印函数
// 方式1.值传递
void printStudent1(Student stu)
{
    stu.age = 100;
    cout << "子函数1中 姓名：" << stu.name
         << " 年龄：" << stu.age
         << " 分数：" << stu.score
         << endl;
}

//方式2.地址传递
void printStudent2(Student * p)
{
    p->age = 200;
    cout << "子函数2中 姓名：" << p->name
        << " 年龄：" << p->age
        << " 分数：" << p->score
        << endl;
}

int main()
{

    Student stu;
    stu.name = "张三";
    stu.age = 18;
    stu.score = 100;
    //方式1.值传递
    printStudent1(stu);
    //方式2.地址传递
    printStudent2(&stu);
    cout << "main函数中 姓名：" << stu.name
        << " 年龄：" << stu.age
        << " 分数：" << stu.score
        << endl;
    return 0;
}