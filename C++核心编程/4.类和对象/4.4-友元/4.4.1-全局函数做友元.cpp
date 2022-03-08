#include <iostream>
using namespace std;
/*
    友元的目的就是让一个函数或者类 范文另一个类中的私有成员
    友元关键字 friend
    友元的三种实现：
        全局函数做友元
        类做友元
        成员函数做友元
*/
class Building
{
    // 全局函数时Building好朋友，可以访问Building中私有成员
    friend void goodGay(Building *building);

public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

//全局函数做友元
void goodGay(Building *building)
{
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
    Building b;
    goodGay(&b);
}
int main()
{
    test01();

    return 0;
}