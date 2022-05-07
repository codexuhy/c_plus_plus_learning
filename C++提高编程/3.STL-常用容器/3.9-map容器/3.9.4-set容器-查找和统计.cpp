#include <iostream>
using namespace std;
#include <map>

// set容器 查找和统计
void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    //查找
    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end())
    {
        cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    //统计
    // map不允许插入重复key 元素，count统计而言 结果要么为0要么为1
    // multimap的count 统计可能大于1
    int num = m.count(3);
    cout << "num = " << num << endl;
}

void printMultiMap(multimap<int, int> &s)
{
    for (multimap<int, int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "key = " << (*it).first << " value = " << it->second << endl;
    }
    cout << endl;
}
void test02()
{
    multimap<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(3, 40));

    //查找
    multimap<int, int>::iterator pos = m.find(3);

    if (pos != m.end())
    {
        cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main()
{
    // test01();

    test02();

    return 0;
}