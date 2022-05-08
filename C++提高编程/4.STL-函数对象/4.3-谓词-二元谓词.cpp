#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    cout << "排序前" << endl;
    PrintVector(v);

    cout << " 排序后" << endl;
    //使用函数对象改变算法策略，排序从大到小
    sort(v.begin(), v.end(), MyCompare());

    return 0;
}