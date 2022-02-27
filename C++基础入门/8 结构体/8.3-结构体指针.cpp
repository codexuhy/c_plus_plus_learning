#include <iostream>
using namespace std;

/*
    结构体指针
    作用:通过指针访问结构体的成员
    使用：利用操作符 -> 可以通过结构体指针访问结构体属性
*/

// 1.结构体定义
struct Student
{
    //成员列表
    string name;
    int age;
    int score;
};

int main()
{

    // 2、创建结构体变量
    struct Student stu = {"张三", 18, 100};

    // 3、创建指针指向结构体变量
    struct Student *p = &stu;
    // 4、使用指针访问结构体变量属性
    cout << "姓名" << p->name << " 年龄：" << p->age << " 得分：" << p->score << endl;

    return 0;
}