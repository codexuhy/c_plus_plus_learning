#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用的集合算法 set_difference

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // 0~9
        v2.push_back(i + 5); // 5~14
    }
    vector<int> vTarget;
    //目标容器需要提前开辟空间
    //最特殊情况 两个容器没有交集 取两个容器中最大的size作为目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));
    //获取差集
    cout << "v1和v2的差集为：" << endl;
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);

    cout << endl;
}

int main()
{
    test01();

    return 0;
}