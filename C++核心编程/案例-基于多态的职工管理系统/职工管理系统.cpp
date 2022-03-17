#include <iostream>
using namespace std;
#include "workerManager.cpp"

int main()
{

    // 实例化管理者对象
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        //展示菜单
        wm.Show_Menu();
        cout << "请输入您的选择:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: //退出系统
            wm.exitSystem();
            break;
        case 1: //添加职工
            break;
        case 2: //显示职工
            break;
        case 3: //删除职工
            break;
        case 4: //修改职工
            break;
        case 5: //查找职工
            break;
        case 6: //排序职工
            break;
        case 7: //清空文件
            break;
        default:
            // system("pause");7
            exit(0);
        }
    }

    return 0;
}