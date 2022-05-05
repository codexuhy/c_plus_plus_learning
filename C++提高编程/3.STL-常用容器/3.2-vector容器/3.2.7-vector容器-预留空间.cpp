#include <iostream>
using namespace std;
#include <vector>

//容器预留空间
void test01()
{
    vector<int> v;

    // 利用reserve预留空间
    v.reserve(100000); //若知道vector内存放100000数据，可直接预留，可以节省开辟空间次数

    int num = 0; // 统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num = " << num << endl; // vector动态分配空间，空间不足时，会开辟新空间，将原有空间数据拷贝过去，进行后续存入 num = 18
}

int main()
{
    test01();

    return 0;
}