#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>
/*
    案例：
    学生正在做毕设项目，每个老师带领5名学生，总共有3名老师，需求如下
    设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
    学生的成员有姓名、考试分数，创建数组存放3位老师，通过函数给每个老师及所带的学生赋值
    最终打印出老师数据以及老师所带学生数据。
*/

//定义学生结构体
struct Student
{
    string sName;
    int age;
    int score;
};

//定义老师结构体
struct Teacher
{
    string tName;
    struct Student stuArr[5];
};

//给老师和学生赋值的函数
void allocateSpace(struct Teacher tArr[], int len)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < len; i++)
    {

        tArr[i].tName = "Teacher_";
        tArr[i].tName += nameseed[i];
        //对每名老师的学生赋值
        for (int j = 0; j < 5; j++)
        {
            tArr[i].stuArr[j].sName = "Student_";
            tArr[i].stuArr[j].sName += nameseed[j];

            int random = rand() % 61 + 40; //随机生成40-100 之间的值
            tArr[i].stuArr[j].score = random;
        }
    }
}
//打印信息
void printInfo(struct Teacher tArr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << tArr[i].tName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << " \t学生姓名:" << tArr[i].stuArr[j].sName
                 << "\t分数：" << tArr[i].stuArr[j].score << endl;
        }
    }
}

int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    // 1.创建3名老师的数组
    struct Teacher tArray[3];
    // 2. 通过函数给3名老师的信息赋值,并给老师带的学生信息赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);

    // 3.打印所有老师及其所带学生信息
    printInfo(tArray, len);

    return 0;
}