#include <iostream>
using namespace std;
#include <set>

// set容器 查找和统计

//查找
void test01()
{
    set<int> s1;
    //插入
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    // 查找
    set<int>::iterator pos = s1.find(400);
    if (pos != s1.end())
    {
        cout << "找到元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
}

//统计
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    //统计30的个数
    int num = s1.count(30);
    cout << "num= " << num << endl;
}

int main()
{
    test01();

    return 0;
}