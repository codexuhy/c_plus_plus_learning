#include <iostream>
using namespace std;
#include <map>
class Mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printSet(map<int, int, Mycompare> &m)
{
    for (map<int, int, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << (*it).second << endl;
    }
}
void test01()
{
    // 默认从小到大排序
    //利用仿函数实现从大到小排序
    map<int, int, Mycompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(3, 30));
    m.insert(map<int, int, Mycompare>::value_type(2, 20));

    printSet(m);
}

int main()
{
    test01();

    return 0;
}