#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

void printVector(vector<bool> &v)
{
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//内建函数对象 逻辑仿函数
//逻辑非 logical_not
void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    printVector(v);

    //利用逻辑非 将容器v搬运到 容器v2中 并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());

    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    printVector(v2);
}

int main()
{
    test01();

    return 0;
}