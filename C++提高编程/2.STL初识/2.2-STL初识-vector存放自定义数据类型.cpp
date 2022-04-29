#include <iostream>
using namespace std;

#include <vector>
#include <string>

// 学习目标：vector中存放自定义数据类型,并打印输出

class Person
{
public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

public:
    string mName;
    int mAge;
};

// 存放自定义数据类型
void test01()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //遍历容器中的数据
    cout << "test01" << endl;
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) //每个容器都有自己专属的迭代器 --> vector<Person>::iterator
    {
        cout << "姓名：" << (*it).mName << " 年龄：" << (*it).mAge << endl;
    }
}

// 存放自定义数据类型 指针
void test02()
{
    vector<Person *> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //遍历容器中的数据
    cout << "test02" << endl;
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "姓名：" <<(*(*it)).mName << " 年龄：" << (*(*it)).mAge << endl;
        cout << "姓名：" << (*it)->mName << " 年龄：" << (*it)->mAge << endl;
    }
}

int main()
{

    test01();

    test02();

    return 0;
}