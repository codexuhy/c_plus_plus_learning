#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);

    printVector(v);

    //降序排列  自定义函数对象
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
    //也可以使用内建函数对象 greater<int>()) 需要引入头文件functional
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);
}

int main()
{
    test01();

    return 0;
}