#include <iostream>
using namespace std;

#include <vector>
#include <algorithm> // 标准算法头文件

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{

    //创建vector容器对象,并且通过模板参数指定容器中存放的数据的类型
    vector<int> v; // 数组

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin(); // 起始迭代器 指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end(); // 结束迭代器 指向容器中最后一个元素的下一个元素
    // vector<int>::iterator 拿到vector<int> 这种容器的迭代器类型

    // 第一种遍历方式
    // while(itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // 第二种遍历方式
    // for(vector<int>::iterator it = v.begin();it!= v.end();it++)
    // {
    //     cout << *it << endl;
    // }
    // 迭代器自动类型推导
    // for (auto it =v.begin();it < v.end();it++)
    // {
    //     cout << *it << endl;
    // }

    // 第三种遍历方式 利用STL提供遍历算法 头文件algorithm
    // for_each(v.begin(), v.end(), myPrint);
}

int main()
{

    test01();

    return 0;
}

/*
下方代码来源：https://blog.csdn.net/chenzongduozhu/article/details/53259572
目的为了验证for_each 功能
*/

// #include <iostream>

// using namespace std;

// // 先导入头文件
// #include <map>
// // 算法包
// #include <algorithm>
// #include <vector>
// // 仿函数
// class PrintElement {
// public:
//     void operator()(pair<int, int> element){
//         cout << element.first << ", " << element.second << endl;
//     }
// };

// // 普通函数
// void printElement(pair<int, int> element){
//     cout << element.first << ", " << element.second << endl;
// }

// void myPrint(int val)
// {
//     cout << val << endl;
// }

// int main() {
//     // map<int, int> m;
//     // m[1] = 1;
//     // m[2] = 2;
//     // m[3] = 3;

//     // cout << "用仿函数遍历map" << endl;
//     // for_each(m.begin(), m.end(),PrintElement());
//     // cout << endl << "用普通函数遍历map" << endl;
//     // for_each(m.begin(), m.end(), printElement);

//     return 0;
// }