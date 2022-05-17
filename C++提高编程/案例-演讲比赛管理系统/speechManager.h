#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "Speaker.h"
#include <string>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>


//设计演讲管理类
class SpeechManager
{
public:
    //构造函数
    SpeechManager();

    //菜单功能
    void show_Menu();

    //退出功能
    void existSystem();

    //析构函数
    ~SpeechManager();

    //初始化属性
    void initSpeech();

    //创建12名选手
    void createSpeaker();

    // 开始比赛 比赛整个流程控制函数
    void startSpeech();
    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示得分
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示往届得分
    void showRecord();

    //清空记录
    void clearRecord();

    //判断文件是否为空
    bool fileIsEmpty;

    //存放往届记录的容器
    map<int, vector<string>> m_Record;

    //成员属性
    //比赛选手 容器 12人
    vector<int> v1;

    //第一轮晋级容器 6人
    vector<int> v2;

    //胜利前三名容器 3人
    vector<int> vVictory;

    //存放编号 以及对应的 具体选手 容器
    map<int, Speaker> m_Speaker;

    //记录比赛轮数
    int m_Index;
};
