#include<iostream>
using namespace std;
/*
    设计一个结构体,包括成员姓名,年龄，性别;创建结构体数组,数组中放5名英雄
    通过冒泡排序算法，将数组中英雄按照年龄升序排列，最终打印排序后的结果
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"},
*/


//1.定义一个结构体
struct Hero 
{
    string name;
    int age;
    string sex;
};

//冒泡排序
void bubbleSort(struct Hero heroArr[],int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1;j++)
        {
            if (heroArr[j].age > heroArr[j+1].age)
            {
                struct Hero temp = heroArr[j];
                heroArr[j] = heroArr[j+1];
                heroArr[j+1] = temp; 
            }
        }
    }
}

void bubbleSort1(struct Hero *p,int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1;j++)
        {
            if ((p+j)->age > (p+j+1)->age)
            {
                cout << p->age << " ;"<< (p+1)->age << endl;
               
                struct Hero * temp;
                *temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = *temp;
            }
        }
    }
}


//打印信息
void printHero(struct Hero heroArr[],int len)
{
    for (int i = 0;i < len; i++)
    {
        cout << "姓名："<< heroArr[i].name
        << " 年龄：" << heroArr[i].age
        << " 性别：" << heroArr[i].sex
        << endl; 
    }
}
int main(){
    //2.创建一个结构体数组变量
    struct Hero heroArr[5] = 
    {
        {"刘备",230,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",190,"女"},

    };

    //3.根据年龄进行冒泡排序(升序排列)
    int len = sizeof(heroArr) /sizeof(heroArr[0]);
    // bubbleSort(heroArr,len);
    bubbleSort1(heroArr,len);

    //4.打印英雄的信息
    printHero(heroArr,len);
    return 0;
}