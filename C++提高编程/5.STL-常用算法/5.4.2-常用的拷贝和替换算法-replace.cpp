#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//常用的拷贝和替换算法 replace
class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(10);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    cout << "替换后：" << endl;
    replace(v.begin(), v.end(), 10, 1000);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();

    return 0;
}