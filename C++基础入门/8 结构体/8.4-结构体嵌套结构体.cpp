#include <iostream>
using namespace std;

//学生结构体定义
struct Student
{
    //成员列表
    string name; //姓名
    int age;     //年龄
    int score;   //分数
};

// 教师结构体定义
struct Teacher
{
    //成员列表
    int id;             //职工编号
    string name;        // 教师姓名
    int age;            //教师年龄
    struct Student stu; //子结构 学生
};

int main()
{
    //结构体嵌套结构体 
    // 创建方式1：直接初始化成员值
    // struct Teacher t = {1122, "李华", 23, {"张三", 15, 100}};
    //创建方式2；通过定义的结构体变量，来对结构体成员进行赋值
    Teacher t;
    t.id = 1122;
    t.name = "李华";
    t.age = 23;
    t.stu.name = "张三";
    t.stu.age = 15;
    t.stu.score = 100;

    cout << "职工编号："<< t.id
        << " 教师姓名：" << t.name
        << " 教师年龄：" << t.age
        << " 所带学生：" << t.stu.name
        << " 所带学生年龄：" << t.stu.age
        << " 所带学生分数：" << t.stu.score
        << endl;
    return 0;
}