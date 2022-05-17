#include <iostream>
using namespace std;
#include "speechManager.cpp"
#include<string>
#include <ctime>
int main()
{
    // srand ((unsigned int) time(NULL));

    //创建管理类对象
    SpeechManager sm;

    // //测试12名选手创建
    // for(map<int,Speaker>::iterator it = sm.m_Speaker.begin();it !=sm.m_Speaker.end();it++)
    // {
    //     cout << "选手编号：" << it->first <<" 姓名：" << it->second.m_Name <<" 分数： " << it->second.m_Score[0] << endl;
    // }

    int choice = 0; // 用来存储用户的选择

    while (true)
    {
        sm.show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice; //接受用户的选项

        switch (choice)
        {
        case 1: //开始比赛
            sm.startSpeech();
            break;
        case 2: //查看记录
            sm.showRecord();
            break;
        case 3: //清空记录
            sm.clearRecord();
            break;
        case 0: //退出系统
            sm.existSystem();
            break;
        default:
            // system("clear"); //清屏
            break;
        }
    }

    return 0;
}