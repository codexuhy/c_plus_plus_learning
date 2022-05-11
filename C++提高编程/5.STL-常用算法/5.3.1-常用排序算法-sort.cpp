#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myPrint(int val)
{
    cout << val << " ";
}

class Greater
{
public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout << endl;

    //改为降序
    // sort(v.begin(),v.end(),Greater()); //自定义
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),myPrint);
    cout << endl;
}

int main()
{
    test01();
    
    return 0;
}