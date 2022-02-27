#include <iostream>
using namespace std;

//定义学生结构体
struct Student
{
    string name;
    int age;
    int score;
};

// const使用场景(加const防止函数体中的误操作)
void printStudent(const Student *s)
// 地址传递只占8个字节，相比值传递把实参传过来减少了内存开销
// 值传递：将实参复制一份到内存中
// 地址传递： 64位占用8个字节，开辟一块内存存放所需数据的地址
{
    // s->age = 85; // 操作失败,因为加了const修饰
    cout << "子函数中姓名：" << s->name << "年龄：" << s->age << "分数：" << s->score << endl;
}

int main()
{

    Student stu;
    stu.name = "张三";
    stu.age = 18;
    stu.score = 100;

    printStudent(&stu);
    cout << "main函数中姓名：" << stu.name << "年龄：" << stu.age << "分数：" << stu.score << endl;

    return 0;
}