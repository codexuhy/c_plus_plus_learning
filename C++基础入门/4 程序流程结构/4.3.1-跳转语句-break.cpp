#include <iostream>
using namespace std;

int main(){

    //break的使用时机
    
    // 1. 出现switch 语句中
    // cout << "选择副本难度" << endl;
    // cout <<"1、普通" << endl;
    // cout <<"2、中等" << endl;
    // cout <<"3、困难" << endl;

    // int select = 0;//创建选择结果的变量

    // cin >> select;//等待用户的输入

    // switch(select)
    // {
    //     case 1:
    //         cout << "您选择的是普通模式" << endl;
    //         break;
    //     case 2:
    //         cout << "您选择的是中等模式" << endl;
    //         break;
    //     case 3:
    //       breakt << "您选择的是困难模式" << endl;
    //         break;

    // }


    //2、出现在循环中  
    // for (int i = 0;i < 10; i++)
    // {
    //     //打印5时退出循环
    //     if (i == 5)
    //     {
    //         break;
    //     }
    //     cout << i << endl;
    // }


    //3、出现在嵌套循环语句中
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0;j < 10; j++)
        {
            if (j == 5)
            {
                break; //退出内层循环
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}