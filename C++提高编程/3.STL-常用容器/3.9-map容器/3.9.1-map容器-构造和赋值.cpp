#include<iostream>
using namespace std;
#include<map>

//map容器  构造和赋值
/*
构造：
- map<T1,T2> mp;      //map默认构造函数
- map<const map &mp>; //拷贝构造函数
赋值：
- map& operator=(const map &mp); //重载等号操作符
*/
void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++)
    {
        cout << "key = " << (*it).first << " value = " << it->second << endl;
    }
    cout << endl;
}
void test01()
{
    //创建map容器
    map<int,int> m;

    m.insert(pair<int,int>(1,100));
    m.insert(pair<int,int>(2,200));
    m.insert(pair<int,int>(3,300));
    m.insert(pair<int,int>(4,400));

    printMap(m);

    //拷贝构造
    map<int,int> m2(m);
    printMap(m2);

    //赋值
    map<int,int>m3;
    m3 = m2;
    printMap(m3);
}

int main()
{
    test01();
    
    return 0;
}