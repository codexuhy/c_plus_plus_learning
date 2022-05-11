#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用的拷贝和替换算法 replace_if
class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

class Greater30
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    //大于30的替换为1000
    cout << "替换后：" << endl;
    replace_if(v.begin(), v.end(), Greater30(), 1000);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();

    return 0;
}