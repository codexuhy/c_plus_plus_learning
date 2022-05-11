#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

//常用的算术生成算法 accumulate

void test01()
{
    vector<int> v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }
    //参数3 起始累加值
    int total = accumulate(v.begin(), v.end(), 0);

    cout << "total = " << total << endl;
}

int main()
{
    test01();

    return 0;
}