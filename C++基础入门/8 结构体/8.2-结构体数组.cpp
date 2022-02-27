#include <iostream>
using namespace std;

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
    // 2.结构体数组中元素赋值
    struct Student stuArr[3] =
        {
            {"张三", 18, 100},
            {"李四", 19, 99},
            {"王五", 20, 98}};
    // 3.给结构体数组找那个元素赋值
    stuArr[2].name = "赵六";
    stuArr[2].age = 80;
    stuArr[2].score = 60;

    // 4.遍历结构体数组
    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << stuArr[i].name
             << "年龄：" << stuArr[i].age
             << "得分：" << stuArr[i].score
             << endl;
    }

    return 0;
}