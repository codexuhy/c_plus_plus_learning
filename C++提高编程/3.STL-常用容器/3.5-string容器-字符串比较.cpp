#include <iostream>
using namespace std;
#include <string>
/*
- int compare(const string& str)const;      // 与字符串s比较
- int compare(const char* s)const;          // 与字符串s比较
*/

void test01()
{
    string s1 = "hello";
    string s2 = "hello";

    int ret = s1.compare(s2);
    if (ret == 0)
    {
        cout << "s1 等于 s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 大于 s2" << endl;
    }
    else
    {
        cout << "s1 大于 s2" << endl;
    }
}

int main()
{
    test01();

    return 0;
}