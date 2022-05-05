#include <iostream>
using namespace std;
#include <deque>

// deque赋值操作
//  - deque &operator=(const deque &deq); //重载等操作符
//  - assigh(beg, end);                   //将[beg,end)区间中的数据拷贝赋值给本身
//  - assign(n, elem);                    //将n个elem拷贝赋值给本身

void printDeque(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // operator= 赋值
    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    // assign 赋值
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    // n个elem拷贝
    deque<int> d4;
    d4.assign(10, 100);
}

int main()
{
    test01();

    return 0;
}