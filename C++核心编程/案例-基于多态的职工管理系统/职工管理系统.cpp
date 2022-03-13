#include <iostream>
using namespace std;
#include "workerManager.cpp"

int main()
{

    // 实例化管理者对象
    WorkerManager wm;

    //调用菜单展示成员函数
    wm.Show_Menu();
    return 0;
}