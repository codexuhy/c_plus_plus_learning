#include <iostream>
using namespace std;
#include <list>
// List：
// 优点：可以对任意位置进行快速插入或删除元素
// 缺点：容器遍历速度，没有数组快 占用空间比数组大

/*
- list<T> lst;          //采用模板实现类实现，默认构造函数
- list(beg, end);       //将v[begin(),end()]区间中的元素拷贝给本身
- list(n, elem);        //构造函数将n个elem拷贝给本身
- list(const list &lst) //拷贝构造函数
*/

void printList(list<int>& lst)
{
    for(list<int>::iterator it = lst.begin();it != lst.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// list容器构造函数
void test01()
{
    list<int>L1;//默认构造
    //添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //遍历容器
    printList(L1);

    //区间方式构造
    list<int>L2(L1.begin(),L1.end());
    printList(L2);

    //拷贝构造
    list<int>L3(L2);
    printList(L3);

    list<int>L4(10,1000);
    printList(L4);

}

int main()
{
    test01();

    return 0;
}