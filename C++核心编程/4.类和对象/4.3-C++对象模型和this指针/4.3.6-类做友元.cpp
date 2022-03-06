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
class Building;
class goodGay
{
public:
    goodGay();
    void visit();
private:
    Building *building;
};

class Building{
    //告诉编译器 goodGay类是Building类的好朋友 可以访问到Building类中私有内容
    friend class goodGay;
public:
    Building();
public:
    string m_SittingRoom; //客厅
    string m_BedRoom; //卧室
};

Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
    building = new Building;
}

void goodGay::visit(){
    cout << "好基友正访问：" << building->m_SittingRoom<< endl;
    cout << "好基友正访问：" << building->m_BedRoom<< endl;
}

void test01(){
    goodGay gg;
    gg.visit();
}
int main(){

    test01();

    return 0;
}