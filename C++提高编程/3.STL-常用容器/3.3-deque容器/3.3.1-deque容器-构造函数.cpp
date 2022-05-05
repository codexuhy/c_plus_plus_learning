#include <iostream>
using namespace std;
#include <deque>

// deque构造函数
// - deque<T> deqT;           //默认构造形式
// - deque(beg, end);         //构造函数将[beg，end)区间中的元素拷贝给本身
// - deque(n, elem);          //构造函数将n个elem拷贝给本身
// - deque(const deque &deq); //拷贝构造函数
void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1; //无参构造
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end()); //区间构造
    printDeque(d2);

    deque<int> d3(10, 100); // n个elem构造
    printDeque(d3);

    deque<int> d4 = d3; //拷贝构造
    printDeque(d4);
}

int main()
{
    test01();

    return 0;
}